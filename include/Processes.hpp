/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** Processes
*/

#ifndef PROCESSES_HPP_
    #define PROCESSES_HPP_
    #include <iostream>
    #include <functional>
    #include <unistd.h>
    #include <sys/wait.h>

    class Process {
    public:
        Process();
        ~Process();
        bool create(std::function<void()> function, std::function<void()> function2, int modeWait);
        void remove();
    private:
        pid_t pid;
    };

#endif /* !PROCESSES_HPP_ */
