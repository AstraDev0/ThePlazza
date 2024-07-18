/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Pizza
*/


/**
 * @file Pizza.cpp
 * @brief Pizza class file.
 * @date 2023-05-29
 */

#include "../include/Pizza.hpp"


/**
 * @brief Construct a new Pizza:: Pizza object
 * 
 * @param cookingTime 
 */

Pizza::Pizza(float cookingTime) : multiplier(cookingTime)
{
}
/**
 * @brief Destroy the Pizza:: Pizza object
 * 
 */

Pizza::~Pizza()
{
}
/**
 * @brief   Pack the pizza order
 * 
 * @param PizzaOrder 
 */


void Pizza::pack(const pizza_t& PizzaOrder)
{
    _type = (PizzaType)PizzaOrder.type;
    _size = (PizzaSize)PizzaOrder.size;
}

/**
 * @brief Unpack the pizza order
 * 
 * @param PizzaOrder 
 * @return std::string 
 */

std::string Pizza::unpack(pizza_t& PizzaOrder)
{
    std::string ret;

    ret = std::to_string(PizzaOrder.quantity)
    + "," + std::to_string(PizzaOrder.size)
    + "," + std::to_string(PizzaOrder.type);
    return ret;
}

/**
 * @brief GUse different ingredients for the pizza
 * 
 * @param stock 
 */

void Pizza::useIngredient(Stock *stock)
{
    if (PizzaType::Margarita == _type || PizzaType::Regina == _type
    || PizzaType::Americana == _type|| PizzaType::Fantasia == _type) {
        stock->_products[Doe].quantity--;
        stock->_products[Tomato].quantity--;
    }
    if (PizzaType::Margarita == _type || PizzaType::Regina == _type
    || PizzaType::Americana == _type)
        stock->_products[Gruyere].quantity--;
    if (PizzaType::Regina == _type) {
        stock->_products[Ham].quantity--;
        stock->_products[Mushrooms].quantity--;
    }
    if (PizzaType::Americana == _type)
        stock->_products[Steak].quantity--;
    if (PizzaType::Fantasia == _type) {
        stock->_products[Eggplant].quantity--;
        stock->_products[GoatCheese].quantity--;
        stock->_products[ChiefLove].quantity--;
    }
}

/**
 * @brief Check if the ingredient is available
 * 
 * @param stock 
 * @return true 
 * @return false 
 */

bool Pizza::checkIngrenient(Stock *stock)
{
    if ((stock->_products[Gruyere].quantity == 0
    || stock->_products[Doe].quantity == 0)
    && ((PizzaType::Margarita == _type
    && stock->_products[Tomato].quantity == 0)
    || (PizzaType::Regina == _type
    && (stock->_products[Gruyere].quantity == 0
    || stock->_products[Ham].quantity == 0
    || stock->_products[Mushrooms].quantity == 0))
    || (PizzaType::Americana == _type
    && (stock->_products[Gruyere].quantity == 0
    || stock->_products[Steak].quantity == 0))
    || (PizzaType::Fantasia == _type
    && (stock->_products[Eggplant].quantity == 0
    || stock->_products[GoatCheese].quantity == 0
    || stock->_products[ChiefLove].quantity == 0))))
        return false;
    return true;
}

/**
 * @brief Get the Baking Time object
 * 
 * @return float 
 */

float Pizza::getBakingTime() const
{
    int baseTime = 0;

    switch (_type) {
        case PizzaType::Margarita:
            baseTime = 1;
            break;
        case PizzaType::Regina:
        case PizzaType::Americana:
            baseTime = 2;
            break;
        case PizzaType::Fantasia:
            baseTime = 4;
            break;
    }
    return baseTime * multiplier;
}
