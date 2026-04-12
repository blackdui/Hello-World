#include <iostream>
#include "co_return.h"

void func()
{
    std::cout << "hello\n";
}
ReturnObject myCoroutine()
{
    // co_return func();
    // 只能提供return_void 和 return_value中的其中一个
    // return_value可以重载
    co_return 1;
}
int main()
{
    using std::cout;

    //控制协程的暂停、恢复和释放
    auto returned_object = myCoroutine();
    // cout << "hello world.\n";
    return 0;
}
