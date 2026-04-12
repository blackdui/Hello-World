#include <coroutine>
#include <iostream>

//co_await co_yield co_return关键字
//函数中如果存在，编译器会有特殊处理
// function被改写成
// {
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
// }
// 实现5个函数
// ReturnObject名字可以任意，内部类必须是promise_type
class ReturnObject {
    public:
        class promise_type {
            public:
                ReturnObject get_return_object()
                {
                    return {};
                }

                std::suspend_never initial_suspend()
                {
                    return std::suspend_never();
                }

                std::suspend_never final_suspend() noexcept
                {
                    return std::suspend_never();
                }

                void unhandled_exception() {

                }

                // void return_void()
                // {
                //     std::cout << __func__ << "\n";
                // }

                void return_value(int n)
                {
                    std::cout << __func__ << "\n";
                }

        };

};
