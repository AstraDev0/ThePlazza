/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** main
*/

#ifndef MAIN_HPP_
    #define MAIN_HPP_
    #include <vector>
    #include <string>
    #include <iostream>
    #include <random>
    #include <sstream>
    #include <iomanip>
    #include "Getorder.hpp"

    struct Threadpool;
    struct ordersProcess;

    int check_number(char *value, int add_dot);
    int check_letters(char *value);
    std::vector<std::string> split(std::string str, char delim);
    int GenerateID();
    const char *getType(int type);
    const char *getSize(int size);

#endif /* !MAIN_HPP_ */
