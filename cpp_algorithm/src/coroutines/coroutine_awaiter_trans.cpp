#include <coroutine>
#include <iostream>
#include "coroutine_awaiter_trans.h"

ReturnObject myCoroutine()
{
    auto length = co_await "hello world";
    //需要重载await_transform
    co_await std::suspend_always{};
    std::cout << length << "\n";
}
int main()
{
    auto returnObject = myCoroutine();
    returnObject.m_handle();
    return 0;
}
