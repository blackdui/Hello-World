#include <iostream>
#include "coroutine_awaitable.h"

ReturnObject myCouroutine()
{
    auto length = co_await "marisa";
    std::cout << "length: " << length << "\n";
}
int main()
{
    auto returnObject = myCouroutine();
    returnObject.m_handle();
    return 0;
}
