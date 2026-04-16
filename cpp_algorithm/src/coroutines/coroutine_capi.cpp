#include <iostream>
#include "coroutine_capi.h"

void capi_resume(void* coroutine)
{
    auto handle = ReturnObject::handle_type::from_address(coroutine);
    handle.resume();
}

ReturnObject myCoroutine()
{
    std::cout << __func__ << "\n";
    co_return ;
}
int main()
{
    auto returnObject = myCoroutine();
    capi_resume(returnObject.m_handle.address());
    return 0;
}
