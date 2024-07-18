/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Utils
*/
/**
 * @file Utils.cpp
 * @brief Utils class file.
 * @date 2020-04-11
*/

#include "../include/Utils.hpp"

/**
 * @brief Check if the string is a number
 * 
 * @param value 
 * @param add_dot 
 * @return int 
 */

int check_number(char *value, int add_dot)
{
    for (int i = 0; value[i]; i++) {
        if ((add_dot ? value[i] != '.' : 1)
        && (value[i] < '0' || value[i] > '9'))
            return 0;
    }
    return 1;
}

/**
 * @brief Check if the string is a letter
 * 
 * @param value 
 * @return int 
 */

int check_letters(char *value)
{
    for (int i = 0; value[i]; i++) {
        if (!((value[i] >= 'a' && value[i] <= 'z')
        || (value[i] >= 'A' && value[i] <= 'Z')))
            return 0;
    }
    return 1;
}

/**
 * @brief Split a string with a delimiter
 * 
 * @param str 
 * @param delim 
 * @return std::vector<std::string> 
 */

std::vector<std::string> split(std::string str, char delim)
{
    std::vector<std::string> result;
    size_t pos = 0;

    while ((pos = str.find(delim)) != std::string::npos) {
        std::string pizzaStr = str.substr(0, pos);
        if (pizzaStr.length() != 0)
            result.push_back(pizzaStr);
        str.erase(0, pos + 1);
    }
    if (str.length() != 0)
        result.push_back(str);
    return result;
}

/**
 * @brief Generate an ID
 * 
 * @return int 
 */

int GenerateID()
{
    static int lastId = 0;

    return ++lastId;
}
/**
 * @brief Get the Type object (of the pizza)
 * 
 * @param type 
 * @return const char* 
 */
const char *getType(int type)
{
    return (type == 1
    ? "Regina" : type == 2
    ? "Margarita" : type == 3
    ? "Americana" : "Fantasia");
}
/**
 * @brief Get the Size object (of the pizza)
 * 
 * @param size 
 * @return const char* 
 */
const char *getSize(int size)
{
    return (size == 1
    ? "S" : size == 2
    ? "M" : size == 4
    ? "L" : size == 8
    ? "XL" : "XXL");
}