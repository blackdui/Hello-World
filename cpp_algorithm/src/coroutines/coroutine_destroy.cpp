#include <iostream>
#include "coroutine_destroy.h"

ReturnObject myCoroutine()
{
    co_await std::suspend_always{};
    std::cout << __func__ << "\n";
    co_return;
}
int main()
{

    std::cout << __func__ << "\n";
    ReturnObject returnObject = myCoroutine();
    returnObject.m_handle();
    // returnObject.m_handle.destroy();
    // 析构方法自动销毁 rii机制
    return 0;
}
