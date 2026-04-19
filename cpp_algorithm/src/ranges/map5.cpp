#include <iostream>
#include <ranges>
#include <unordered_map>
int main()
{
    std::unordered_map<std::string, int> m{{"jack",  10086},
                                        {"black", 10010},
                                        {"trump", 12345},
                                        {"job",   143235}};
    //1keys
    auto names = std::views::keys(m);
    for (const auto& name: names) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    auto values = std::views::values(m);
    for (const auto& value: values) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
