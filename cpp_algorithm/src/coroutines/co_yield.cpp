#include <iostream>
#include "co_yield.h"

ReturnObject coroutineFunction()
{
    co_yield "hello";
    // co_await promise.yield_value(1);
}
int main()
{
    //1. 协程内不能有return
    //会自动调用co_return
    //2. 找不到promise_type 
    //3. 不能用不定长参数
    //void func(...) {}
    //void func(auto... arg) {} 可以通过
    //4. 不能用constexpr 和 consteval
    ReturnObject control = coroutineFunction();
    return 0;
}
