#include <coroutine>
#include <iostream>
#include "coroutine_resume.h"

ReturnObject myCoroutine()
{
    co_await std::suspend_always{};
    std::cout << __func__ << "\n";
}
int main()
{
    auto returnObject = myCoroutine();
    //只有上面一行会产生内存泄露
    // returnObject.m_handle.resume(); 等价
    returnObject.m_handle();

    return 0;
}
