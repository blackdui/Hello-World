#include <exception>
#include <iostream>
#include "coroutine_awaitable.h"

ReturnObject myCoroutine()
{
    co_return;
}
int main()
{
    try {
        auto returnObject = myCoroutine();
        returnObject();
    } catch (const std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }
    return 0;
}
