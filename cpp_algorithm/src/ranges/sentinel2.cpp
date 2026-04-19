// https://zhuanlan.zhihu.com/p/600126585
#include <iostream>
// 由于使用了<compare> 头文件，编译器会自动生成不等运算符。
#include <compare>
#include <algorithm>
#include <vector>

//哨兵
struct Space {
    bool operator==(auto pos) const
    {
        return *pos == ' ';
    }
};

struct Sum {
    void operator()(auto n)
    {
        sum+=n;
    }
    int sum{0};
};

struct NegativeNumber {
    bool operator==(auto pos) const
    {
        return *pos < 0;
    }
};
int main()
{
    const char *poet = "Never its mysteries are exposed To the weak human eye unclosed;";
    
    //algorithm
    //1
    std::ranges::for_each(poet, Space{}, [](char c ) { std::cout << c; });
    std::cout << "\n";

    //2
    for (auto c: std::ranges::subrange{ poet, Space{} })
        std::cout << c;
    std::cout << "\n";

    //3
    std::ranges::subrange subRange = std::ranges::subrange{ poet, Space{} };
    std::ranges::for_each(subRange, [](char c) { std::cout << c << " "; });
    std::cout << "\n";

    //4
    for (auto c: subRange) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    //5
    std::vector v1{1, 2, 3, 4, 5, 6, -7, 8, 9, 10};

    for (auto v: v1) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    //stuctured binding.
    //6
    //std::ranges::for_each 返回一对 (it, func)。it 是哨兵的后继，func 是应用于范围的函数对象。
    auto [tmp1, sum1] = std::ranges::for_each(v1, Sum{});
    std::cout << sum1.sum;
    std::cout << "\n";

    //7 1+2..+6
    auto [tmp2, sum2] = std::ranges::for_each(std::begin(v1), NegativeNumber{}, Sum{});
    std::cout << sum2.sum;
    std::cout << "\n";

    //8
    //1 4 9 16 25 36
    std::ranges::transform(std::begin(v1), NegativeNumber{}, std::begin(v1), [](auto num) { return num*num; });
    std::ranges::for_each(std::begin(v1), NegativeNumber{}, [](int num) { std::cout << num << " "; });
    std::cout << "\n";

    //9 
    //1 4 9 16 25 36
    for (auto n: std::ranges::subrange{ std::begin(v1), NegativeNumber{} })
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
