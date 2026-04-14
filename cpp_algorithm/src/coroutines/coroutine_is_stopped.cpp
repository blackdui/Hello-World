#include <iostream>
#include "coroutine_is_stopped.h"

ReturnObject myCoroutine()
{
    std::cout << __func__ << "\n";
    co_yield 1;

    std::cout << __func__ << "\n";
    co_yield 2;
}
int main()
{
    std::cout << __func__ << "\n";
    auto returnObject = myCoroutine();
    // 1. 获取promise_type的实例
    // auto value = returnObject.m_handle.promise().m_value;
    // std::cout << value << "\n";
    //
    // 2. 判断协程是否结束
    // final_suspend()需要返回suspend_always();
    while (!returnObject.m_handle.done()) {
        int value = returnObject.m_handle.promise().m_value;
        std::cout << value << "\n";
        // resume();
        returnObject.m_handle();
    }

    // returnObject.m_handle();
    // returnObject.m_handle();
    return 0;
}
