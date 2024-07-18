/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Kitchen
*/

#ifndef Kitchen_HPP_
    #define Kitchen_HPP_
    #include <iostream>
    #include <string>
    #include <pthread.h>
    #include <thread>
    #include "Getorder.hpp"
    #include "Threadpool.hpp"
    #include "Cook.hpp"
    #include "Mutex.hpp"
    #include "Utils.hpp"
    #include "Processes.hpp"
    #include "Logger.hpp"

    struct pizza_t;
    class Reception;
    class IPC;
    class Threadpool;
    struct orderKitchenID;
    struct KitchenInfo;
    struct ordersProcess;
    class Logger;
    struct orderPizza;

    class Kitchen {
        public:
            Kitchen();
            ~Kitchen();
            void managelentKitchens(IPC *ipc, float cookingTime, int cooksKitchen, int timeStocks);
            float _cookingTime;
            int _cooksKitchen;
            int _timeStocks;
            std::vector<KitchenInfo> _kitchens;
            std::vector<ordersProcess> orders;
        protected:
        private:

    };

#endif /* !Kitchen_HPP_ */
