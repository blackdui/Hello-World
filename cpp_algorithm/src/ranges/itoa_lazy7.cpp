#include <ios>
#include <iostream>
#include <vector>
#include <ranges>

bool odd(int i)
{
    return i % 2 == 1;
}

bool isPrime(int i)
{
    //j*j 平方能整除，开根也能整除，优化
    //素数只能被1和自身整除，所以j从2开始
    for (int j = 2; j*j <= i; ++j) {
        if (i % j == 0) return false;
    }
    return true;
}
int main()
{
    std::cout << std::boolalpha;

    std::vector<int> vec1;
    std::vector<int> vec2;

    //iota范围工厂
    for (int i: std::views::iota(0, 10)) {
        // std::cout << i << " ";
        vec1.push_back(i);
    }

    for (int i: std::views::iota(0) | std::views::take(10)) {
        vec2.push_back(i);
    }

    //true
    std::cout << "vec1 == vec2 " << (vec1 == vec2) << "\n";

    //for each
    for (int i: vec1) std::cout << i << " ";
    std::cout << "\n";

    std::cout << "prime number: \n";
    //filter 返回true的保留
    for (int i: std::views::iota(0) | std::views::filter(odd)
                                    | std::views::filter(isPrime)
                                    | std::views::take(20)) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
