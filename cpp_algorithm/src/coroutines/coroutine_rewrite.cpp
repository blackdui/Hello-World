#include <coroutine>
#include <iostream>
#include "coroutine_rewrite.h"
#include <vector>

//改写标准库的函数，使其可以使用协程的功能
struct Student {
    struct _Student {
        int age;
        std::string name;
    }_stu;
};

//特化模板
template <>
class std::vector<Student> : public std::vector<Student::_Student> {
    using std::vector<Student::_Student>::push_back;
    using std::vector<Student::_Student>::size;

    public:
        //原本没有返回值 void
        ReturnObject push_back(const Student& stu)
        {
            co_await std::suspend_always{};
            //也许是通过传递的参数确定调用父类的push_back();
            push_back(stu._stu);
        }

        ReturnObject size()
        {
            co_await std::suspend_always{};
            co_yield vector<Student::_Student>::size(); 
        }
};
int main()
{
    std::vector<Student> students;
    auto returnObject = students.push_back(Student{18, "marisa"});
    auto returnObject1 = students.size();
    
    returnObject.m_handle();
    returnObject1.m_handle();
    auto size = returnObject1.m_handle.promise().m_size;
    std::cout << size << "\n";
    
    return 0;
}
