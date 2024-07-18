/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
    #define LOGGER_HPP_
    #include <fstream>

    class Logger {
    public:
        Logger(const std::string& logFileName);
        ~Logger();
        void log(const std::string& message);
    private:
        std::ofstream m_logFile;
    };

#endif /* !LOGGER_HPP_ */
