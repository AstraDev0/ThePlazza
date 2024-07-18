/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** IPC
*/

/**
 * @file IPC.cpp
 * @brief IPC class file.
 * @date 2023-05-29
 */

#include "../include/IPC.hpp"

/**
 * @brief Construct a new IPC::IPC object
 * 
 */

IPC::IPC() : msqid(-1)
{
}

/**
 * @brief Destroy the IPC::IPC object
 * 
 */

IPC::~IPC()
{
    if (msqid != -1)
        msgctl(msqid, IPC_RMID, nullptr);
}

/**
 * @brief Create a Instance object
 * 
 * @param key 
 * @return int 
 */

int IPC::CreateInstance(key_t key)
{
    msgctl(msgget(key, 0), IPC_RMID, nullptr);
    while (msqid == -1) {
        msqid = msgget(key, IPC_CREAT | 0666);
        msqid == -1 ? key = key + 1 : 0;
    }
    return (msqid != -1);
}

/**
 * @brief Get the Instance object
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator>>(IPC& ipc, pizza_t& order)
{
    struct Message {
        long type;
        pizza_t order;
    };

    Message msg;

    if (ipc.msqid == -1 ||
    msgrcv(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 1, 0) == -1)
        return ipc;
    order = msg.order;
    return ipc;
}

/**
 * @brief Put the Instance object
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator<<(IPC& ipc, const pizza_t& order)
{
    struct Message {
        long type;
        pizza_t order;
    };

    Message msg;

    if (ipc.msqid == -1)
        return ipc;
    msg.type = 1;
    msg.order = order;
    msgsnd(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 0);
    return ipc;
}

/**
 * @brief Get the Instance object   
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator>>(IPC& ipc, orderPizza& order)
{
    struct Message {
        long type;
        orderPizza order;
    };

    Message msg;

    if (ipc.msqid == -1 ||
    msgrcv(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 1, 0) == -1)
        return ipc;
    order = msg.order;
    return ipc;
}

/**
 * @brief Put the Instance object
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator<<(IPC& ipc, const orderPizza& order)
{
    struct Message {
        long type;
        orderPizza order;
    };

    Message msg;

    if (ipc.msqid == -1)
        return ipc;
    msg.type = 1;
    msg.order = order;
    msgsnd(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 0);
    return ipc;
}

/**
 * @brief Get the Instance object
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator>>(IPC& ipc, orderFinished& order)
{
    struct Message {
        long type;
        orderFinished order;
    };

    Message msg;

    if (ipc.msqid == -1 ||
    msgrcv(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 1, 0) == -1)
        return ipc;
    order = msg.order;
    return ipc;
}

/**
 * @brief Put the Instance object
 * 
 * @param ipc 
 * @param order 
 * @return IPC& 
 */

IPC& operator<<(IPC& ipc, const orderFinished& order)
{
    struct Message {
        long type;
        orderFinished order;
    };

    Message msg;

    if (ipc.msqid == -1)
        return ipc;
    msg.type = 1;
    msg.order = order;
    msgsnd(ipc.msqid, &msg, sizeof(msg) - sizeof(long), 0);
    return ipc;
}