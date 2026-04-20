#include <iostream>
#include <ranges>
#include <unordered_map>

int main()
{
   std::unordered_map<std::string, int> m{{"jack",    10086},
                                        {"black",   10010},
                                        {"fdasjkh", 10010},
                                        {"dfsjhb",  10010},
                                        {"trump",   12345},
                                        {"job",     143235}};

   auto bAtZero = [](const std::string& name) {
       return name[0] == 'b';
   };

   /*for (const auto& name: std::views::keys(m)|
                   std::views::reverse |
                   std::views::take(4) |
                   std::views::filter(bAtZero)) {
       std::cout << name << " ";
   }*/
    auto keys = std::views::keys(m);
    auto reverse_view = std::views::reverse(keys);
    return 0;
}
