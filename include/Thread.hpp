/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** Thread
*/

#ifndef THREAD_HPP_
    #define THREAD_HPP_
    #include <iostream>
    #include <pthread.h>

    class Thread {
        public:
            Thread();
            ~Thread();
            void start(void *(*function)(void *), void *arg);
            void cancel();
            void join();
        protected:
        private:
            pthread_t threadId;
    };

#endif /* !THREAD_HPP_ */
