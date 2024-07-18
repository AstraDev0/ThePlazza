/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** ConditionVar
*/

#ifndef CONDITIONVAR_HPP_
    #define CONDITIONVAR_HPP_
    #include <pthread.h>
    #include <stdexcept>
    class ConditionVar {
        public:
          ConditionVar();
          ~ConditionVar();
          void wait(pthread_mutex_t& mutex);
          void signal();
          void broadcast();
          private:
            pthread_cond_t condition;
    };

#endif /* !CONDITIONVAR_HPP_ */
