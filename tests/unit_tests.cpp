/*
** EPITECH PROJECT, 2023
** B-CCP-400-BER-4-1-theplazza-lucine.balas
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include "../include/Reception.hpp"
#include "../include/Utils.hpp"
#include "../include/Mutex.hpp"
#include "../include/Pizza.hpp"
#include  "../include/Stock.hpp"
#include "../include/Threadpool.hpp"

Test(PizzaTest, PackAndUnpack)
{
    Pizza pizza(1.0f);
    pizza_t order;
    pizza_t unpackedOrder;
    order.quantity = 2;
    order.size = PizzaSize::L;
    order.type = PizzaType::Regina;
    pizza.pack(order);
    pizza.unpack(unpackedOrder);
}

Test(PizzaTest, UseIngredient)
{
    Stock stock(3);
    Pizza pizza(1.0f);
    pizza.useIngredient(&stock);
    stock.close();
}

Test(PizzaTest, GetBakingTime)
{
    Pizza pizza1(1.0f);
    pizza1.getBakingTime();
}

Test(ConditionVarTest, WaitSignalBroadcast)
{
    ConditionVar conditionVar;
}

Test(LoggerTest, Log)
{
    Logger logger("logfile.txt");
    logger.log("test");
}

Test(ProcessTest, Create)
{
    Process process;

    process.create([](){}, [](){}, 0);
    process.remove();
}

Test(UtilsTest, CheckNumber)
{
    char value[] = "12345";
    int result = check_number(value, 0);
    cr_assert_eq(result, 1, "Expected check_number to return 1");
}

Test(UtilsTest, CheckLetters)
{
    char value[] = "abcd";
    int result = check_letters(value);
    cr_assert_eq(result, 1, "Expected check_letters to return 1");
}

Test(UtilsTest, Split)
{
    std::string str = "Hello,World";
    std::vector<std::string> result = split(str, ',');
    cr_assert_eq(result.size(), 2, "Expected split to return a vector of size 2");
}

Test(UtilsTest, GenerateID)
{
    int id1 = GenerateID();
    int id2 = GenerateID();
    cr_assert_neq(id1, id2, "Expected GenerateID to generate unique IDs");
}

Test(UtilsTest, GetType)
{
    const char* type = getType(2);
    cr_assert_str_eq(type, "Margarita", "Expected getType to return 'Margarita'");
}

Test(UtilsTest, GetSize)
{
    const char* size = getSize(4);
    cr_assert_str_eq(size, "L", "Expected getSize to return 'L'");
}

Test(ReceptionTest, SendOrderToKitchen)
{
    Reception reception;
    IPC ipc;

    reception.sendOrderToKetchen(&ipc);
}

Test(kitchen, managelentKitchens) {
    Kitchen kitchen;
    IPC ipc;

    kitchen.managelentKitchens(&ipc, 1.5f, 2, 3);
}

Test(MutexTest, LockAndUnlock)
{
    Mutex mutex;
    mutex.lock();
    mutex.unlock();
}

Test(ThreadpoolTest, Work)
{
    pizza_t pizza;
    IPC ipc;

    Threadpool threadpool(0, 0, 0 ,0, &ipc, &ipc);
    bool result = threadpool.work(pizza);
    cr_assert(result == false);
}
