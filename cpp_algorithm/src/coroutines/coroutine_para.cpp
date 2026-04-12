#include <iostream>
#include "coroutine_para.h"

ReturnObject myFunc(int n)
{
    co_return;
}

ReturnObject multiArgs(auto... args)
{
    co_return;
}
int main()
{

    //传值给promise_type
    //member function
    //static member funcion
    //lambda function
    // k.memberFunc(0, "hello");
    // memberFunc(k, 0, "hello");
    auto returnObject = myFunc(3);
    multiArgs(1, 3, 4, 7);

    return 0;
}
