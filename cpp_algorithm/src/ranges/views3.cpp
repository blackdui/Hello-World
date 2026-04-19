// https://zhuanlan.zhihu.com/p/600126585
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
int main()
{
    std::vector numbers{1, 3, 2, 7, 4, 0};

    // 视图不拥有数据。因此，视图不会延长其数据的生命周期。因此，视图只能对左值操作。
    //扔掉前四个元素
    //5 6
    // auto result1 = std::views::drop(numbers, 4);
    auto result1 = numbers | std::views::drop(4);
    //1
    // for (auto num: result1) {
    //     std::cout << num << " ";
    // }
    // std::cout << "\n";

    //2
    // std::ranges::drop_view(numbers, 4);

    //3
    //sort 
    // std::sort(numbers.begin(), numbers.end());
    std::ranges::sort(numbers);
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}
