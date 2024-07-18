/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** getorder
*/

#ifndef GETORDER_HPP_
    #define GETORDER_HPP_
    #include <stack> 
    #include <iostream>
    #include <string>
    #include <vector>
    #include "Utils.hpp"
    #include "Reception.hpp"
    #include "Pizza.hpp"
    #include "Processes.hpp"

    class IPC;
    class Process;

    struct pizza_t
    {
        int type;
        int size;
        int quantity;
        int id;
    };

    struct orderFinished
    {
        int quantityFinished;
        int idKitchen;
        int idOder;
        int exit;
    };

    struct ordersProcess
    {
        pizza_t order;
        bool finished;
        int quantityFinished;
    };

    struct orderPizza
    {
        pizza_t order;
        bool status;
    };

    struct KitchenInfo {
        int idKitchen;
        std::vector<pizza_t> _PizzaProcess;
        std::vector<pizza_t> _PizzaFinished;
        IPC *ipc;
        Process *process;
    };

    class Reception;

    int check_and_set_order(std::string input, Reception *Reception);
    void check_strings_order(pizza_t *pizza, std::vector<std::string> tbl_value);
    void getorder(Reception *reception);
#endif /* !GETORDER_HPP_ */
