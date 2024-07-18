/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_
    #include <pthread.h>

    class Mutex {
    public:
        Mutex();
        ~Mutex();
        void lock();
        void unlock();
        pthread_mutex_t* get_mutex();
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    private:
    };

#endif /* !MUTEX_HPP_ */
