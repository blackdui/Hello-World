#include <coroutine>
#include <iostream>
#include "coroutine_lifecycle.h"

//co_await co_yield co_return关键字
//函数中如果存在，编译器会有特殊处理
// function被改写成
// {
//      create coroutine state
//      copy parameters to coroutine frame
//      ReturnObject::promise_type promise;
//      ReturnObject return_object = promise.get_return_object();
//
//      try {
//              co_await promise.initial_suspend();
//              promise.return_void(); //function body
//      } catch (...) {
//              promise.unhandled_exception();
//      }
//
//      promise.final_suspend();
//      destruct promise p
//      destruct parameters in coroutine frame
// }
// 实现5个函数
// ReturnObject名字可以任意，内部类必须是promise_type
using namespace std::string_literals;
struct promise;

struct coroutine : std::coroutine_handle<promise> {
    using promise_type = ::promise;
};

struct promise {
    coroutine get_return_object()
    {
        std::cout << __func__ << "\n";
        //需要初始化,才能使用函数
        return {coroutine::from_promise(*this)};
    }

    std::suspend_always initial_suspend()
    {
        std::cout << __func__ << "\n";
        return {}; 
    }

    std::suspend_always final_suspend() noexcept
    {
        std::cout << __func__ << "\n";
        return {};
    }

    void unhandled_exception()
    {
        std::cout << __func__ << "\n";
    }

    void return_void()
    {
        std::cout << __func__ << "\n";
    }
};

struct Student {
    ~Student()
    {
        std::cout << __func__ << "\n";
    }
    std::string m_name;
    coroutine name()
    {
        std::cout << m_name << "\n";
        co_return;
    }
};

coroutine func2()
{
    Student reiam{ "reiam" };
    return reiam.name();
}

void func3()
{
    //匿名成员变量s
    auto returnObject = [ s = "string"s]() -> coroutine
    {
        std::cout << s << "\n";
        co_return;
    } ();

    returnObject.resume();
    returnObject.destroy();
}

void good()
{
    //注意传值
   auto returnObject = [](std::string name) -> coroutine
   {
        std::cout << name << "\n";
        co_return;
   } ("marisa"); 
   returnObject.resume();
   returnObject.destroy();
}
int main()
{
    // auto returnObject = Student{"marisa"}.name();
    //1.Student destroyed.
    //两个生命周期不一样
    //
    // auto returnObject = func2();
    //2.函数调用结束，reiam销毁
    // returnObject.resume();
    // returnObject.destroy();
    //
    //3.匿名函数
    // func3();
    //
    good();
    return 0;
}
