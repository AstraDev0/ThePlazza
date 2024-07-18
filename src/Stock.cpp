/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Stock
*/


/**
 * @file Stock.cpp
 * @brief Stock class file.
 * @date 2023-05-29
 */

#include "../include/Stock.hpp"

/**
 * @brief Construct a new Stock:: Stock object
 * 
 * @param timeStocks 
 */

Stock::Stock(int timeStocks) : _running(1), _timeStocks(timeStocks)
{
    for (int i = 0; i < 9; i++)
        _products[i].quantity = 5;
    StockUpdate();
}

/**
 * @brief Destroy the Stock:: Stock object
 * 
 */

Stock::~Stock()
{
}

/**
 * @brief Close the Stock
 * 
 */

void Stock::close()
{
    thread.cancel();
    thread.join();
}

/**
 * @brief Add a product to the stock
 * 
 * @param args 
 * @return void* 
 */

void *AddProduct(void *args)
{
    Stock *stock = (Stock *)(args);

    while (stock->_running) {
        sem_wait(&stock->semaphore);
        sleep(1);
        sem_post(&stock->semaphore);
        stock->mutex.lock();
        for (int i = 0; i < 9; i++)
            stock->_products[i].quantity += 1;
        stock->mutex.unlock();
    }
    return NULL;
}

/**
 * @brief Stop the stock update
 * 
 */

void Stock::StopUpdate(void)
{
    _running = 0;
}

/**
 * @brief Update the stock
 * 
 */

void Stock::StockUpdate(void)
{
    sem_init(&semaphore, 0, 1);
    thread.start(AddProduct, this);
    sem_destroy(&semaphore);
}

/**
 * @brief Check if the stock is empty
 * 
 * @param i 
 * @return int 
 */

int Stock::StockCheck(int i)
{
    return _products[i].quantity != 0 ? 1 : 0;
}
