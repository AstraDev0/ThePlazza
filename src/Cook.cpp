/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Cooks
*/

/**
 * @file Cook.cpp
 * @brief Cook class file.
 * @date 2023-05-29
 */

#include "../include/Cook.hpp"

/**
 * @brief Construct a new Cook:: Cook object
 * 
 * @param cookingTime 
 * @param idKitchen 
 * @param stock 
 * @param ipcToKit 
 */

Cook::Cook(float cookingTime, int idKitchen, Stock* stock, IPC *ipcToKit) : started(false), finishedOrder(0)
{
    _stock = stock;
    _cookingTime = cookingTime;
    _ipcToKit = ipcToKit;
    _idKitchen = idKitchen;
}

/**
 * @brief Destroy the Cook:: Cook object
 * 
 */

Cook::~Cook()
{
}

/**
 * @brief Close the Cook
 * 
 */

void Cook::close()
{
    if (started) {
        started = 0;
        thread.cancel();
        thread.join();
    }
}
/**
 * @brief Add a order to the queue
 * 
 * @param order 
 * @param mode 
 * @return true 
 * @return false 
 */


bool Cook::addOrder(pizza_t order, int mode)
{
    if ((PizzaQueue.size() == 0 && mode == 0) ||
    (PizzaQueue.size() == 1 && mode == 1)) {
        PizzaQueue.push_back(order);
        _conditionVarRecvOrder.signal();
        return true;
    }
    return false;
}

/**
 * @brief Wait the order finish
 * 
 * @return pizza_t 
 */

pizza_t Cook::waitOrderFinish()
{
    while (PizzaFinished.size() != 0);
    return PizzaFinished.back();
}
\

/**
 * @brief Send the order to the kitchen
 * 
 * @param arg 
 * @return void* 
 */
void *sendToKitchen(void *arg)
{
    Cook *cook = static_cast<Cook *>(arg);
    orderFinished orderFinsh;

    orderFinsh.exit = 0;
    orderFinsh.idKitchen = cook->_idKitchen;
    orderFinsh.idOder = cook->PizzaFinished.back().id;
    orderFinsh.quantityFinished = cook->PizzaFinished.back().quantity;
    *cook->_ipcToKit << orderFinsh;
    return NULL;
}

/**
 * @brief Process the order
 * 
 * @param arg 
 * @return void* 
 */

void *process(void *arg)
{
    Cook* cook = static_cast<Cook*>(arg);
    Pizza pizza(cook->_cookingTime);

    while (1) {
        cook->_mutex.lock();
        while (cook->PizzaQueue.size() == 0) {
            cook->_conditionVarRecvOrder.wait(cook->_mutex.mutex);
        };
        while (pizza.checkIngrenient(cook->_stock) == false);
        pizza.pack(cook->PizzaQueue[0]);
        sleep(pizza.getBakingTime());
        pizza.useIngredient(cook->_stock);
        cook->PizzaFinished.push_back(cook->PizzaQueue[0]);
        cook->PizzaQueue.erase(cook->PizzaQueue.begin());
        sendToKitchen(cook);
        cook->_mutex.unlock();
    }
    return NULL;
}

/**
 * @brief Start the cook
 * 
 */

void Cook::start()
{
    thread.start(process, this);
    started = true;
}

/**
 * @brief   Get the status of the cook
 * 
 * @param PizzaWatting 
 * @param PizzaProcess 
 */

void Cook::getStatus(pizza_t &PizzaWatting, pizza_t &PizzaProcess)
{
    if (PizzaQueue.size() == 1) {
        PizzaWatting = PizzaFinished[0];
        return;
    }
    if (PizzaQueue.size() == 2)
        PizzaProcess = PizzaFinished[1];
    else
        PizzaProcess = (pizza_t){0, 0, 0, 0};
}

/**
 * @brief   Get the status of the cook
 * 
 * @return true 
 * @return false 
 */

bool Cook::isRunning()
{
    return PizzaQueue.size() != 0;
}