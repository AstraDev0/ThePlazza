/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Threadpool
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_
    #include "IPC.hpp"
    #include "Stock.hpp"
    #include "Mutex.hpp"
    #include "ConditionVar.hpp"
    #include "Cook.hpp"

    struct Message;
    struct pizza_t;
    class IPC;
    class Cook;

    class Threadpool {
        public:
            Threadpool(float cookingTime, int cooksKitchen, int timeStocks, int id, IPC *_ipcToKit,  IPC *ipcToThreadPl);
            ~Threadpool();
            bool work(pizza_t order);
            void start();
            void close();
            void RecvThreadPl();
            int displayStatus();
            void displayStatusNext(std::ostringstream& write);
            int _id;
            std::vector<pizza_t> _PizzaProcess;
            std::vector<Cook *> cooks;
            std::vector<Thread *> threadrecv;
            float _cookingTime;
            Stock* _stock;
            IPC *_ipcToKit;
        protected:
        private:
            int _cooksKitchen;
            IPC *_ipcToThreadPl;
    };

#endif /* !THREADPOOL_HPP_ */
