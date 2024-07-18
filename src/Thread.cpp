/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** Thread
*/

/**
 * @file Thread.cpp
 * @brief Thread class file.
 * @date 2023-05-29
 */

#include "../include/Thread.hpp"

/**
 * @brief Construct a new Thread:: Thread object
 * 
 */

Thread::Thread() : threadId(0)
{
}

/**
 * @brief Destroy the Thread:: Thread object
 * 
 */

Thread::~Thread()
{
}

/**
 * @brief Start the thread
 * 
 * @param function 
 * @param arg 
 */

void Thread::start(void *(*function)(void *), void *arg) {
    pthread_create(&threadId, NULL, function, arg);
}

/**
 * @brief Join the thread
 * 
 */

void Thread::join() {
    pthread_join(threadId, NULL);
}

/**
 * @brief Cancel the thread
 * 
 */

void Thread::cancel()
{
    pthread_cancel(threadId);
}