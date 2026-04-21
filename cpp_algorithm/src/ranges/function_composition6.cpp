#include <iostream>
#include <ranges>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, int> m{{"jack",    10086},
        {"black",   10010},
        {"fdasjkh", 10010},
        {"dfsjhb",  10010},
        {"trump",   12345},
        {"job",     143235}};

    auto bAtZero = [](const std::string& name) {
        return name[0] == 'b';
    };

    for (const auto& name: std::views::keys(m) 
            |std::views::reverse 
            |std::views::take(4) 
            |std::views::filter(bAtZero)
        )
    {
        std::cout << name << " ";
    }
    std::cout << "\n";


    //unordered_map不支持双向访问
    //显示no match
    // auto rev1 = std::views::reverse(std::views::keys(m));
    return 0;
}
