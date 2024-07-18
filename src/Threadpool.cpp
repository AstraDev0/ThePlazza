/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Threadpool
*/

/**
 * @file Threadpool.cpp
 * @brief Threadpool class file.
 * @date 2023-05-29
 */

#include "../include/Threadpool.hpp"

/**
 * @brief Construct a new Threadpool:: Threadpool object
 * 
 * @param cookingTime 
 * @param cooksKitchen 
 * @param timeStocks 
 * @param id 
 * @param ipcToKit 
 * @param ipcToThreadPl 
 */
Threadpool::Threadpool(float cookingTime, int cooksKitchen, int timeStocks, int id, IPC *ipcToKit, IPC *ipcToThreadPl)
{
    _cookingTime = cookingTime;
    _cooksKitchen = cooksKitchen;
    _ipcToThreadPl = ipcToThreadPl;
    _ipcToKit = ipcToKit;
    _id = id;
    _stock = new Stock(timeStocks);
}
/**
 * @brief Destroy the Threadpool:: Threadpool object
 * 
 */
Threadpool::~Threadpool()
{
}
/**
 * @brief Close the Threadpool
 * 
 */
void Threadpool::close()
{
    for (size_t i = 0; threadrecv.size() > i; i++) {
        threadrecv[i]->cancel();
        threadrecv[i]->join();
        delete threadrecv[i];
    }
    for (size_t i = 0; cooks.size() > i; i++) {
        cooks[i]->close();
        delete cooks[i];
    }
    _stock->close();
    delete _stock;
}

/**
 * @brief Display the status of the current pizza
 * 
 * @param write 
 */

void Threadpool::displayStatusNext(std::ostringstream& write)
{
    write << "\n   }\n    Waiting { ";
    for (size_t i = 0; cooks.size() > i; i++) {
        if (cooks[i]->PizzaQueue.size() > 1)
            write << "\n     cook [" << i << "] | id: " << cooks[i]->PizzaQueue[1].id
            << " | Type: " << getType(cooks[i]->PizzaQueue[1].type) << " | Size: "
            << getSize(cooks[i]->PizzaQueue[1].size) << " | Quantity: "
            << cooks[i]->PizzaQueue[1].quantity;
    }
    write << "\n    }\n  }\n Pizza Finish {";
    for (size_t i = 0; cooks.size() > i; i++) {
        for (size_t j = 0; cooks[i]->PizzaFinished.size() > j; j++) {
            write << "\n   cook [" << i << "] | id: " << cooks[i]->PizzaQueue[j].id
            << " | Type: " << getType(cooks[i]->PizzaQueue[j].type) << " | Size: "
            << getSize(cooks[i]->PizzaQueue[j].size) << " | Quantity: "
            << cooks[i]->PizzaQueue[j].quantity;
        }
    }
    write << "\n  }\n}\n";
}

/**
 * @brief Display the status of a kitchen
 * 
 * @return int 
 */

int Threadpool::displayStatus()
{
    std::ostringstream write;

    write << "Kitchen " << _id << " {\n stock {"
    << " Doe:" << _stock->_products[Doe].quantity << ", Tomato: "
    << _stock->_products[Tomato].quantity << ", Gruyere: "
    << _stock->_products[Gruyere].quantity << ", Ham: "
    << _stock->_products[Ham].quantity << ", Mushrooms: "
    << _stock->_products[Mushrooms].quantity << ", Steak: "
    << _stock->_products[Steak].quantity << ", Eggplant: "
    <<  _stock->_products[Eggplant].quantity << ", Goat Cheese: "
    << _stock->_products[GoatCheese].quantity << ", Chief Love: "
    << _stock->_products[ChiefLove].quantity
    << " } \n Pizza Queue { \n   Process {";
    for (size_t i = 0; cooks.size() > i; i++) {
        if (cooks[i]->PizzaQueue.size() == 1)
            write << "\n     cook [" << i << "] | id: " << cooks[i]->PizzaQueue[0].id
            << " | Type: " << getType(cooks[i]->PizzaQueue[0].type) << " | Size: "
            << getSize(cooks[i]->PizzaQueue[0].size) << " | Quantity: "
            << cooks[i]->PizzaQueue[0].quantity;
    }
    displayStatusNext(write);
    std::cout << write.str();
    return 0;
}

/**
 * @brief Recive thread for the threadpool
 * 
 */

void Threadpool::RecvThreadPl()
{
    orderPizza order;

    while (1) {
        *_ipcToThreadPl >> order;
        if(order.order.id == 0 && order.order.quantity == 0
        && order.order.size == 0 && order.order.type == 0
        && order.status == false) {
            close();
            break;
        }
        order.status == true ? displayStatus() : work(order.order);
    }
}

/**
 * @brief Work function for the threadpool
 * 
 * @param arg 
 * @return void* 
 */

void *checkActivity(void *arg)
{
    Threadpool *threadpool = static_cast<Threadpool *>(arg);
    int activity = 0;
    int check = 1;

    while (1) {
        sleep(1);
        check = 1;
        for (size_t i = 0; threadpool->cooks.size() > i; i++) {
            if (threadpool->cooks[i]->PizzaQueue.size() != 0)
                check = 0;
        }
        check ? activity++ : activity = 0;
        if (activity == 5) {
            threadpool->close();
            *threadpool->_ipcToKit
            << (orderFinished){0, threadpool->_id, 0, 1};
            break;
        }
    }
    pthread_exit(NULL);
}

/**
 * @brief Start the threadpool
 * 
 */

void Threadpool::start()
{
    Thread threadActivity;

    for (int i = 0; _cooksKitchen > i; i++) {
        cooks.push_back(new Cook(_cookingTime, _id, _stock, _ipcToKit));
        cooks.back()->start();
    }
    threadActivity.start(checkActivity, this);
    RecvThreadPl();
}

/**
 * @brief Work function for the threadpool
 * 
 * @param order 
 * @return true 
 * @return false 
 */

bool Threadpool::work(pizza_t order)
{
    for (size_t i = 0; cooks.size() > i; i++) {
        if (cooks[i]->addOrder(order, 0))
            return true;
    }
     for (size_t i = 0; cooks.size() > i; i++) {
        if (cooks[i]->addOrder(order, 1))
            return true;
    }
    return false;
}
