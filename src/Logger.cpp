/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Logger
*/

/**
 * @file Logger.cpp
 * @brief Logger class file.
 * @date 2023-05-29
 */

#include "../include/Logger.hpp"

/**
 * @brief Construct a new Logger:: Logger object
 * 
 * @param logFileName 
 */

Logger::Logger(const std::string& logFileName)
{
    m_logFile.open(logFileName, std::ios::out | std::ios::app);
}

/**
 * @brief Destroy the Logger:: Logger object
 * 
 */

Logger::~Logger()
{
    if (m_logFile.is_open())
        m_logFile.close();
}

/**
 * @brief Log a message
 * 
 * @param message 
 */

void Logger::log(const std::string& message)
{
    if (m_logFile.is_open())
        m_logFile << message << std::endl;
}
