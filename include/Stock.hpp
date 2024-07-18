/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Stock
*/

#ifndef STOCK_HPP_
    #define STOCK_HPP_

    #include <iostream>
    #include <stack>
    #include <thread>
    #include "Mutex.hpp"
    #include "Thread.hpp"

    struct Product {
        int quantity;
    };

    enum prod {
        Doe,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        Eggplant,
        GoatCheese,
        ChiefLove
    };

    class Stock {
    public:
        Stock(int timeStocks);
        ~Stock();
        void StockUpdate(void);
        int StockCheck(int i);
        void StopUpdate(void);
        void close();
        Product _products[9];
        int _running;
        sem_t semaphore;
        Mutex mutex;
        int _timeStocks;
        Thread thread;
    private:
    };

#endif /* !STOCK_HPP_ */
