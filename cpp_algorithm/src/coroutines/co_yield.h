#include <coroutine>
#include <iostream>

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

                void return_void()
                {

                }
                
                void unhandled_exception()
                {

                }
                
                template <typename T>
                auto yield_value(T value)
                {
                    std::cout << __func__ << " " << value << "\n";
                    return std::suspend_never {};
                }
        };
};
