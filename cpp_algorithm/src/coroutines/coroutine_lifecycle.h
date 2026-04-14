#include <coroutine>
#include <exception>
#include <iostream>

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
// }
// 实现5个函数
// ReturnObject名字可以任意，内部类必须是promise_type
class ReturnObject {
    public:
        class promise_type;
        using handle_type = std::coroutine_handle<promise_type>;
        ReturnObject(handle_type handle)
        {
            std::cout << __func__ << "\n";
            m_handle = handle;
        }
        ~ReturnObject()
        {
            std::cout << __func__ << "\n";
            m_handle.destroy();
        }
        class promise_type {
            public:
                promise_type()
                {
                    std::cout << __func__ << "\n";
                }
                ~promise_type()
                {
                    std::cout << __func__ << "\n";
                }
                ReturnObject get_return_object()
                {
                    std::cout << __func__ << "\n";
                    return { handle_type::from_promise(*this) };
                }

                std::suspend_never initial_suspend()
                {
                    std::cout << __func__ << "\n";
                    // throw std::exception{};
                    // 进程不正常结束，控制权交给main
                    return {};
                }

                std::suspend_always final_suspend() noexcept
                {
                    //如果传递suspend_always
                    //资源不会自动释放
                    std::cout << __func__ << "\n";
                    return {};
                }

                void unhandled_exception() {

                    std::cout << __func__ << "\n";
                }

                void return_void()
                {
                    std::cout << __func__ << "\n";
                }
        };
        handle_type m_handle;
};
