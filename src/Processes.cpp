/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas (copy)
** File description:
** Processes
*/


/**
 * @file Processes.cpp
 * @brief Processes class file.
 * @date 2023-05-29
 */

#include "../include/Processes.hpp"


/**
 * @brief Construct a new Process:: Process object
 * 
 */

Process::Process() : pid(-1)
{
}
/**
 * @brief Destroy the Process:: Process object
 * 
 */

Process::~Process()
{
}

/**
 * @brief Create a Process object
 * 
 * @param function 
 * @param function2 
 * @param modeWait 
 * @return true 
 * @return false 
 */

bool Process::create(std::function<void()> function, std::function<void()> function2, int modeWait)
{
    pid = fork();
    int status = 0;

    if (pid < 0) {
        return false;
    } else if (pid == 0) {
        function();
        exit(0);
    } else {
        function2();
        if (modeWait)
            waitpid(pid, &status, 0);
    }
    return true;
}

/**
 * @brief Remove a Process object
 * 
 */

void Process::remove()
{
    if (pid != -1)
        kill(pid, SIGKILL);
}
