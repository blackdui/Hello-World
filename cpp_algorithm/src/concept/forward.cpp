#include <iostream>

//1.检查f函数是否存在
// template<typename T>
// constexpr bool hasMemF = std::is_void_v<std::void_t<decltype(std::declval<T>().f())>>;

//4. 检查函数返回值是否为int
// template<typename T>
// constexpr bool hasMemIntF = std::is_same_v<decltype(std::declval<T>().f()), int>;

//2.检查f函数是否存在
// template<typename T>
// concept hasMemF = requires {
//     std::declval<T>().f();
// };

//3.检查f函数是否存在
// template<typename T>
// concept hasMemF = requires(T t) {
//     t.f();
// };

template<typename T1, typename T2>
concept SameAs = requires {
    requires std::is_same_v<T1, T2>;
};

//5. 检查函数返回值是否为int
template<typename T>
concept hasMemIntF = requires(T t) {
    // std::is_same_v<decltype(t.f()), int>;
    {t.f()} -> std::same_as<int>;
};

// template<typename T>
// requires hasMemIntF<T>
// void func(T t) {}

//6.
// void func(hasMemIntF auto t) {}

//7.
void func(const hasMemIntF auto& t) {}
struct Student {
    int f() {return 1;};
};

int main()
{
    Student maria;
    func<Student>(maria);
    return 0;
}
