#include <coroutine>
#include <iostream>
#include "coroutine_awaiter.h"

//awaiters 
//suspend_always
//suspend_never:
//      bool await_ready() false
//      void await_suspend()
//      void await_resume()

// ReturnObject myCoroutine()
// {
//     auto value = co_await Awaiter{};
//     std::cout << value << "\n";
//     co_return;
// }
//
ReturnObject myCoroutine3(const std::coroutine_handle<>& handle)
{
    std::cout << __func__ << "\n";
    co_await Awaiter{handle};
}

ReturnObject myCoroutine2(const std::coroutine_handle<>& handle)
{
    std::cout << __func__ << "\n";
    co_await Awaiter{handle};
}

ReturnObject myCoroutine1(const std::coroutine_handle<>& handle)
{
    std::cout << __func__ << "\n";
    co_await Awaiter{handle};
}


int main()
{
    // auto returnObject = myCoroutine();
    // returnObject.m_handle();
    //
    auto returnObject3 = myCoroutine3(nullptr);
    auto returnObject2 = myCoroutine2(returnObject3.m_handle);
    auto returnObject1 = myCoroutine1(returnObject2.m_handle);

    returnObject1.m_handle();


    return 0;
}
