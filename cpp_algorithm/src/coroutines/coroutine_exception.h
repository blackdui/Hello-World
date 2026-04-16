#include <coroutine>
#include <exception>
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
struct Awaiter {
    std::string m_name;

    Awaiter(const std::string& name)
    {
        m_name = name;
    }
    bool await_ready() const noexcept
    {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) const noexcept
    {

    }
    
    size_t await_resume() const noexcept
    {
        return m_name.length(); 
    }
};

struct Awaitable {
    Awaitable(const std::string& name)
    {
        m_name = name;
    }

    Awaiter operator co_await() const noexcept
    {
        return {"hello " + m_name};
    }

    std::string m_name;
};
// 左值右值是什么意思
// Awaiter operator co_await(Awaitable&& awaitable)
// {
//     return {"hello " + awaitable.m_name};
// }
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

                // std::suspend_always yield_value(size_t size)
                // {
                //     m_size = size;
                //     return {};
                // }

                Awaitable await_transform(const std::string& name)
                {
                    return {"world " + name};
                }
                size_t m_size;
        };
        handle_type m_handle;
};
