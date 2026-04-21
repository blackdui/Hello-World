#include <iostream>

//concept为bool型编译期常量

template<typename T>
constexpr bool myType = sizeof(T) < sizeof(void *);

// template<typename T>
//函数上面的是返回值类型
// std::enable_if_t<myType<T>, void>
// myFunc(T t) {}

// template<typename T>
// requires true
// void myFunc(T t) {}

// template<typename T>
// requires false
// void myFunc(T t) {}

// template<typename T>
// requires myType<T>
// void myFunc(T t) {}

// template<typename T>
// requires requires {
//     std::is_trivial_v<T>;
//     myType<T>;
// } || true
// void myFunc(T t) {}

template<typename T>
concept ableToCopy = requires {
    requires std::is_trivial_v<T>;
    requires myType<T>;
};
template<typename T>
concept nested = requires {
    ableToCopy<T>;
    std::is_pod_v<T>;
};

template<typename T>
requires ableToCopy<T>
void myFunc(T t) {}

struct Test {
    int arr[10];
};

int main()
{

    Test t;
    myFunc<Test>(t);
    return 0;
}
