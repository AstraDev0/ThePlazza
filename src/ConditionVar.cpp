/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** ConditionVar
*/

/**
 * @file ConditionVar.cpp
 * @brief ConditionVar class file.
 * @date 2023-05-29
 */

#include "../include/ConditionVar.hpp"

/**
 * @brief Construct a new Condition Var:: Condition Var object 
 * 
 */
ConditionVar::ConditionVar()
{
    pthread_cond_init(&condition, nullptr);
}
/**
 * @brief Destroy the Condition Var:: Condition Var object
 * 
 */
ConditionVar::~ConditionVar()
{
    pthread_cond_destroy(&condition);
}
/**
 * @brief Wait for the condition
 * 
 * @param mutex 
 */
void ConditionVar::wait(pthread_mutex_t& mutex) {
    pthread_cond_wait(&condition, &mutex);
}

/**
 * @brief   Signal the condition
 * 
 */

void ConditionVar::signal() {
    pthread_cond_signal(&condition);
}

/**
 * @brief  Broadcast the condition
 * 
 */

void ConditionVar::broadcast() {
    pthread_cond_broadcast(&condition);
}
