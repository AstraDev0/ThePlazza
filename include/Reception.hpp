/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_
    #include <cstring>
    #include <cstdlib>
    #include <pthread.h>
    #include <sstream>
    #include <stack>
    #include <iostream>
    #include <unistd.h>
    #include <sys/wait.h>
    #include "Kitchen.hpp"
    #include "IPC.hpp"
    #include "Processes.hpp"

    struct pizza_t;
    class IPC;

    class Reception {
        public:
            Reception();
            ~Reception();
            int run(float _cookingTime, int _cooksKitchen, int _timeStocks);
            int sendOrderToKetchen(IPC *ipc);
            int ManagementRecepetion();
            void loopGetSentMessage(IPC *ipc);
            float _cookingTime;
            int _cooksKitchen;
            int _timeStocks;
            bool running;
            bool status;
            std::stack<pizza_t> orders;
        protected:
        private:
            Process process;
    };

#endif /* !RECEPTION_HPP_ */
