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
//
//处理awaiter
//step1
//Awaitable promise.await_transform() {return Awaitable{}}
//step2
//Awaiter Awaitable.operator co_await() { return Awaiter{}}
struct Awaiter {
    std::coroutine_handle<> m_handle;
    std::string m_name;

    Awaiter(const std::coroutine_handle<>& handle)
    {
        m_handle = handle;
    }
    Awaiter(const std::string& name)
    {
        m_name = name;
    }
    bool await_ready() const noexcept
    {
        std::cout << __func__ << "\n";
        //false 暂停执行
        return false;
    }

    std::coroutine_handle<> await_suspend(std::coroutine_handle<> handle) const noexcept
    {
        if (m_handle)
            return m_handle;
        else
            return handle;
    }
    
    // std::coroutine_handle<> await_suspend(std::coroutine_handle<> handle) const noexcept
    // {
    //     std::cout << __func__ << "\n";
    //     return handle;//暂停目前的handle, 继续执行返回的handle
    // }

    // void await_suspend(std::coroutine_handle<> handle) const noexcept
    // {
    //     std::cout << __func__ << "\n";
    //     handle.resume();//继续执行
    // }
    // bool await_suspend(std::coroutine_handle<> handle) const noexcept
    // {
    //     std::cout << __func__ << "\n";
    //     return false;//协程不会暂停
    // }

    // void await_resume() const noexcept
    int await_resume() const noexcept
    {
        std::cout << __func__ << "\n";
        return m_name.length();
    }
};
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

                std::suspend_always initial_suspend()
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
                
                Awaiter await_transform(const std::string& name)
                {
                    return Awaiter{name};
                }
                std::suspend_always await_transform(std::suspend_always&& always)
                {
                    return std::move(always);
                }
        };
        handle_type m_handle;
};
