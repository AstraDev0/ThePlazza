/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** getorder
*/

/**
 * @file Getorder.cpp
 * @brief Getorder class file.
 * @date 2023-05-29
 */

#include "../include/Getorder.hpp"
/**
 * @brief Check the order of the sting
 * 
 * @param pizza 
 * @param tbl_value 
 */

void check_strings_order(pizza_t *pizza, std::vector<std::string> tbl_value)
{
    pizza->type = tbl_value[0] == "regina" ? Regina
    : tbl_value[0] == "margarita" ? Margarita : tbl_value[0] == "americana"
    ? Americana : tbl_value[0] == "fantasia" ? Fantasia : 0;
    pizza->size = tbl_value[1] == "S" ? S :  tbl_value[1] == "M" ? M
    : tbl_value[1] == "L" ? L : tbl_value[1] == "XL" ? XL :
    tbl_value[1] == "XXL" ? XXL : 0;
}
/**
 * @brief Check and set the order of the order
 * 
 * @param input 
 * @param Reception 
 * @return int 
 */

int check_and_set_order(std::string input, Reception *Reception)
{
    std::vector<std::string> tbl_value;
    pizza_t pizza;
    std::vector<pizza_t> tmp_orders;

    for (std::string order : split(input, ';')) {
        tbl_value = split(order, ' ');
        if (tbl_value.size() != 3)
            return 1;
        check_strings_order(&pizza, tbl_value);
        if (pizza.size == 0 || pizza.type == 0 || tbl_value[2][0] != 'x'
        || !check_number((char *)split(tbl_value[2], 'x')[0].c_str(), 0))
            return 1;
        pizza.quantity = atoi((char *)split(tbl_value[2], 'x')[0].c_str());
        pizza.id = GenerateID();
        tmp_orders.push_back(pizza);
    }
    for (pizza_t order : tmp_orders)
        Reception->orders.push(order);
    return 0;
}

/**
 * @brief Get the order object
 * 
 * @param reception 
 */

void getorder(Reception *reception)
{
    std::string input;
    std::vector<std::string> orders;

    std::cout << "> ";
    if (!std::getline(std::cin, input) || input == "exit") {
        reception->running = false;
        return;
    }
    if (input == "status") {
        reception->status = true; 
        return;
    }
    if (check_and_set_order(input, reception))
        std::cout << "Invalid command" << std::endl;
    return;
}