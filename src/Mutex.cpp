/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Mutex
*/


/**
 * @file Mutex.cpp
 * @brief  Mutex class file.
 * @date 2023-05-29
 */

#include "../include/Mutex.hpp"

/**
 * @brief Construct a new Mutex:: Mutex object
 * 
 */

Mutex::Mutex()
{
    pthread_mutex_init(&mutex, NULL);
}

/**
 * @brief Destroy the Mutex:: Mutex object
 * 
 */

Mutex::~Mutex()
{
    pthread_mutex_destroy(&mutex);
}

/**
 * @brief Lock the mutex
 * 
 */

void Mutex::lock() {
    pthread_mutex_lock(&mutex);
}

/**
 * @brief Unlock the mutex
 * 
 */

void Mutex::unlock() {
    pthread_mutex_unlock(&mutex);
}

/**
 * @brief Get the mutex object
 * 
 * @return pthread_mutex_t* 
 */

pthread_mutex_t* Mutex::get_mutex() {
    return &mutex;
}
