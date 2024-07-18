/*
** EPITECH PROJECT, 2023
** The Reception
** File description:
** kitchen
*/

/**
 * @file Kitchen.cpp
 * @brief Kitchen class file.
 * @date 2023-05-29
 */

#include "../include/Kitchen.hpp"


/**
 * @brief Construct a new Kitchen:: Kitchen object
 * 
 */
Kitchen::Kitchen()
{
}

/**
 * @brief Destroy the Kitchen:: Kitchen object
 * 
 */

Kitchen::~Kitchen()
{
    for (size_t i = 0; _kitchens.size() > i;  i++) {
        _kitchens[i].process->remove();
        delete _kitchens[i].ipc;
        delete _kitchens[i].process;
    }
}

/**
 * @brief display the finished order
 * 
 * @param kitchen 
 * @param i 
 * @return int 
 */

int displayOrderFinished(Kitchen *kitchen, int i)
{
    Logger logger("logfile.txt");
    std::ostringstream logStream;

    logStream << "Order " << kitchen->orders[i].order.id << " finished {" << std::endl;
    logStream << " Type : " << getType(kitchen->orders[i].order.type) << std::endl;
    logStream << " Size : " << getSize(kitchen->orders[i].order.size) << std::endl;
    logStream << " Quantity : " << kitchen->orders[i].order.quantity << std::endl;
    logStream << " Id : " << kitchen->orders[i].order.id << std::endl;
    logStream << " }" << std::endl;
    std::cout << logStream.str();
    logger.log(logStream.str());
    return 0;
}

/**
 * @brief If the order is finished move it to the finished vector
 * 
 * @param order 
 * @param kitchen 
 * @param i 
 * @return int 
 */

int OrderFinishedMoveVector(orderFinished order, Kitchen *kitchen, int i)
{
    kitchen->_kitchens[i].idKitchen != order.idKitchen
    ? OrderFinishedMoveVector(order, kitchen, i + 1) : 0;
    kitchen->_kitchens[i]._PizzaFinished.push_back(kitchen->_kitchens[i]._PizzaProcess[0]);
    kitchen->_kitchens[i]._PizzaProcess.erase(kitchen->_kitchens[i]._PizzaProcess.begin());
    return 0;
}

/**
 * @brief add Result to order
 * 
 * @param order 
 * @param kitchen 
 * @param i 
 * @return int 
 */

int addResultToVector(orderFinished order, Kitchen *kitchen, int i)
{
    kitchen->orders[i].order.id != order.idOder
    ? addResultToVector(order, kitchen, i + 1) : 0;
    kitchen->orders[i].quantityFinished++;
    return kitchen->orders[i].order.quantity == kitchen->orders[i].quantityFinished
    ? OrderFinishedMoveVector(order, kitchen, 0), kitchen->orders[i].finished = true,
    displayOrderFinished(kitchen, i) : 0;
}

/**
 * @brief Remove Kitchen
 * 
 * @param kitchen 
 * @param id 
 * @return int 
 */

int removeKitchen(Kitchen *kitchen, int id)
{
    for (size_t i = 0; kitchen->_kitchens.size() > i; i++) {
        if (kitchen->_kitchens[i].idKitchen != id)
            continue;
        kitchen->_kitchens[i].process->remove();
        delete kitchen->_kitchens[i].ipc;
        delete kitchen->_kitchens[i].process;
        kitchen->_kitchens.erase(kitchen->_kitchens.begin() + i);
        std::cout << "Kitchen " << id << " deleted\n";
    }
    return 0;
}

/**
 * @brief Recieve the kitchen
 * 
 * @param ipcToKit 
 * @param kitchen 
 * @return int 
 */

int RecvKitchen(IPC *ipcToKit, Kitchen *kitchen)
{
    orderFinished order;

    while (1) {
        *ipcToKit >> order;
        if(order.idKitchen == 0 && order.idOder == 0
        && order.quantityFinished == 0)
            break;
        order.exit ? removeKitchen(kitchen, order.idKitchen)
        : addResultToVector(order, kitchen, 0);
    }
    return 0;
}

/**
 * @brief Create a new Thread Pool object
 * 
 * @param ipcToKit 
 * @param kitchen 
 * @return int 
 */

int newThreadPool(IPC *ipcToKit, Kitchen *kitchen)
{
    KitchenInfo kitInfo;
    int id = GenerateID();
    IPC *ipcToThreadPl = new IPC;

    kitInfo.process = new Process;
    ipcToThreadPl->CreateInstance(id);
    kitInfo.process->create([ipcToThreadPl, ipcToKit, kitchen, id](){
        Threadpool threadpool(kitchen->_cookingTime,
        kitchen->_cooksKitchen, kitchen->_timeStocks,
        id, ipcToKit, ipcToThreadPl);
        threadpool.start();
    }, [](){}, 0);
    kitInfo.idKitchen = id;
    kitInfo.ipc = ipcToThreadPl;
    kitchen->_kitchens.push_back(kitInfo);
    return 0;
}

/**
 * @brief Sennnd the order to the kitchen
 * 
 * @param kitchen 
 * @param order 
 * @return true 
 * @return false 
 */

bool sendOrderToTheKitchens(Kitchen *kitchen, pizza_t &order)
{
    for (size_t i = 0; kitchen->_kitchens.size() > i
    && order.quantity != 0; i++) {
        if (kitchen->_kitchens[i]._PizzaProcess.size() == 0) {
            kitchen->_kitchens[i]._PizzaProcess.push_back((pizza_t){order.type,
            order.size, 1, order.id});
            *kitchen->_kitchens[i].ipc
            << (orderPizza){kitchen->_kitchens[i]._PizzaProcess.back(), false};
            order.quantity--;
        }
    }
    for (size_t i = 0; kitchen->_kitchens.size() > i
    && order.quantity != 0; i++) {
        if (kitchen->_kitchens[i]._PizzaProcess.size() == 1) {
            kitchen->_kitchens[i]._PizzaProcess.push_back((pizza_t){order.type,
            order.size, 1, order.id});
            *kitchen->_kitchens[i].ipc
            << (orderPizza){kitchen->_kitchens[i]._PizzaProcess.back(), false};
            order.quantity--;
        }
    }
    return order.quantity == 0 ? true : false;
}

/**
 * @brief Process the kitchen
 * 
 * @param ipcToKit 
 * @param kitchen 
 * @param order 
 * @return int 
 */

int processKitchen(IPC *ipcToKit, Kitchen *kitchen, pizza_t order)
{
    kitchen->orders.push_back((ordersProcess){order, false, 0});
    while (order.quantity != 0) {
        if (sendOrderToTheKitchens(kitchen, order))
            break;
        newThreadPool(ipcToKit, kitchen);
    }
    return 0;
}

/**
 * @brief Display the status of the kitchen
 * 
 * @param kitchen 
 * @return int 
 */

int displayStatus(Kitchen *kitchen)
{
    if (kitchen->_kitchens.size() == 0) {
        std::cout << "No open kitchen\n";
        return 0;
    }
    std::cout << "Status kitchens :\n";
    for (size_t i = 0; kitchen->_kitchens.size() > i;  i++)
        *kitchen->_kitchens[i].ipc << (orderPizza){(pizza_t){0, 0, 0 ,0}, true};
    return 0;
}

/**
 * @brief Reception of the messages
 * 
 * @param ipc 
 * @param ipcToKit 
 * @param kitchen 
 */

void receptionMessages(IPC *ipc, IPC *ipcToKit, Kitchen *kitchen)
{
    orderPizza order;
    KitchenInfo kitInfo;

    while(1) {
        *ipc >> order;
        if(order.order.quantity == 0 && order.status == false
        && order.order.size == 0 && order.order.type == 0) {
            for (size_t i = 0; kitchen->_kitchens.size() > i;  i++)
                *kitchen->_kitchens[i].ipc << (orderPizza){(pizza_t){0, 0, 0}};
            *ipcToKit << (orderFinished){0, 0, 0, 0};
            break;
        }
        order.status ? displayStatus(kitchen)
        : processKitchen(ipcToKit, kitchen, order.order);
    }
}

/**
 * @brief Manage the kitchens
 * 
 * @param ipc 
 * @param cookingTime 
 * @param cooksKitchen 
 * @param timeStocks 
 */

void Kitchen::managelentKitchens(IPC *ipc, float cookingTime, int cooksKitchen, int timeStocks)
{
    IPC ipcToKit;

    _cookingTime = cookingTime;
    _cooksKitchen = cooksKitchen;
    _timeStocks = timeStocks;
    ipcToKit.CreateInstance(4784);
    std::thread threadReception(receptionMessages, ipc, &ipcToKit, this);
    std::thread threadRecvKitchen(RecvKitchen, &ipcToKit, this);
    threadRecvKitchen.join();
    threadReception.join();
}
