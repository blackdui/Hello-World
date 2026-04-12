#include <iostream>
#include "basic_coroutine.h"

ReturnObject coroutineFunc()
{
    std::cout << __func__ << "\n";
    co_return;
}
int main()
{
    std::cout << __func__ << "\n";
    auto returnObject = coroutineFunc();
    std::cout << __func__ << "\n";
    return 0;
}
