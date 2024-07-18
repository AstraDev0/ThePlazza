/*
** EPITECH PROJECT, 2023
** The Reception
** File description:
** plazza_start
*/


/**
 * @file Reception.cpp
 * @brief Reception class file.
 * @date 2023-05-29
 */

#include "../include/Reception.hpp"

/**
 * @brief Construct a new Reception:: Reception object
 * 
 */

Reception::Reception()
{
}

/**
 * @brief Destroy the Reception:: Reception object
 * 
 */

Reception::~Reception()
{

}

/**
 * @brief Send oreder to the Kitchen
 * 
 * @param ipc 
 * @return int 
 */

int Reception::sendOrderToKetchen(IPC *ipc)
{
    for (size_t i = 0; orders.size() > i; i++) {
        *ipc << (orderPizza){orders.top(), false};
        orders.pop();
    }
    return 0;
}

/**
 * @brief Get the order from the user
 * 
 * @param ipc 
 */

void Reception::loopGetSentMessage(IPC *ipc)
{
    while (this->running) {
        getorder(this);
        if (status) {
            *ipc << (orderPizza){(pizza_t){0, 0, 0, 0}, true};
            status = false;
        }
        if (sendOrderToKetchen(ipc) == 84)
            return;
    }
    *ipc << (orderPizza){(pizza_t){0, 0, 0, 0}, false};
}

/**
 * @brief Manage the reception
 * 
 * @return int 
 */

int Reception::ManagementRecepetion()
{
    IPC ipc;

    ipc.CreateInstance(1444);
    process.create([&ipc, this](){
        Kitchen kitchen;
        kitchen.managelentKitchens(&ipc,
        _cookingTime, _cooksKitchen, _timeStocks);
    }, [this, &ipc](){
        this->loopGetSentMessage(&ipc);
    }, 1);
    return 0;
}

/**
 * @brief Run the reception
 * 
 * @param _cookingTime 
 * @param _cooksKitchen 
 * @param _timeStocks 
 * @return int 
 */

int Reception::run(float _cookingTime, int _cooksKitchen, int _timeStocks)
{
    this->_cookingTime = _cookingTime;
    this->_cooksKitchen = _cooksKitchen;
    this->_timeStocks = _timeStocks;
    this->running = true;
    return ManagementRecepetion();
}
