/*
** EPITECH PROJECT, 2023
** B-CNA-410-BER-4-1-groundhog-matthis.brocheton
** File description:
** main
*/

/**
 * @file main.cpp
 * @author B-CCP-400-BER-4-1-theplazza-lucine.balas
 * @brief Master file
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "include/Reception.hpp"

/**
 * @brief Main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
    Reception Reception;

    if (argc != 4 || !(check_number(argv[1], 1) && check_number(argv[2], 0)
    && check_number(argv[3], 0)))
        return 84;
    return Reception.run(atof(argv[1]), atoi(argv[2]), atoi(argv[3]));
}