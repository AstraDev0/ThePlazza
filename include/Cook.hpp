/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_
    #include <vector>
    #include "Mutex.hpp"
    #include "ConditionVar.hpp"
    #include "Pizza.hpp"
    #include "IPC.hpp"

    struct pizza_t;
    class IPC;

    class Cook {
        public:
            Cook(float cookingTime, int idKitchen, Stock* stock, IPC *ipcToKit);
            ~Cook();
            void getStatus(pizza_t &PizzaWatting, pizza_t &PizzaProcess);
            void start();
            bool isRunning();
            bool addOrder(pizza_t order, int mode);
            void close();
            pizza_t waitOrderFinish();
            Mutex _mutex;
            std::vector<pizza_t> PizzaQueue;
            std::vector<pizza_t> PizzaFinished;
            Stock *_stock;
            float _cookingTime;
            ConditionVar _conditionVarRecvOrder;
            Thread thread;
            bool started;
            int finishedOrder;
            pthread_cond_t condition;
            IPC *_ipcToKit;
            int _idKitchen;
        private:
    };

#endif /* !COOK_HPP_ */
