#include <iostream>
#include <vector>
#include <ranges>
#include <format>

int main()
{
    std::vector<int> prime = { 1, 2, 3, 4 , 5, 6, 7, 8 };

    auto result = prime | std::views::filter([](int n) { return n % 2 == 0; })
                | std::views::transform([](int n) { return n*2; });
    //| 为函数组合 前面的东西的返回值作为后面函数的参数传入
    // 惰性求值，用到的时候才处理数据

    // begin迭代器， end哨兵，决定的range，表示可迭代的项目
    for (auto value : result) {
        std::cout << value << "\n";
    }
    return 0;
}
