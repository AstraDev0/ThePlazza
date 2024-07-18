/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_
    #include <iostream>
    #include <mqueue.h>
    #include <cstring>
    #include <cerrno>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>
    #include "Getorder.hpp"

    struct pizza_t;
    struct orderFinished;
    struct orderPizza;

    class IPC {
        public:
            IPC();
            ~IPC();
            int CreateInstance(key_t newKey);
            friend IPC& operator>>(IPC& ipc, pizza_t& order);
            friend IPC& operator<<(IPC& ipc, const pizza_t& order);
            friend IPC& operator>>(IPC& ipc, orderFinished& order);
            friend IPC& operator<<(IPC& ipc, const orderFinished& order);
            friend IPC& operator>>(IPC& ipc, orderPizza& order);
            friend IPC& operator<<(IPC& ipc, const orderPizza& order);
        protected:
        private:
            int msqid;
            std::string nameConnection;
    };

#endif /* !IPC_HPP_ */
