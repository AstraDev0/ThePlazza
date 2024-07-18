/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_
    #include "Getorder.hpp"
    #include "Stock.hpp"

    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 3,
        Fantasia = 4
    };
    
    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 3,
        XL = 4,
        XXL = 5
    };

    struct pizza_t;

    class Pizza {
        public:
            Pizza(float cookingTime);
            ~Pizza();
            void pack(const pizza_t& PizzaOrder);
            void useIngredient(Stock *stock);
            std::string unpack(pizza_t& PizzaOrder);
            float getBakingTime() const;
            bool checkIngrenient(Stock *stock);
        protected:
        private:
            int multiplier;
            float _cookingTime;
            PizzaSize _size;
            PizzaType _type;
    };

#endif /* !PIZZA_HPP_ */
