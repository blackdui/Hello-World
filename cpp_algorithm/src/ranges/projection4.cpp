 // template
 // <std::random_access_iterator I, std::sentinel_for<I> S,
 // class Comp = ranges::less, class Proj = std::identity >
 // requires std::sortable<I, Comp, Proj>
 // constexpr I
 // sort( I first, S last, Comp comp = {}, Proj proj = {} );
 // //(1) (since C++20)
 // template
 // <ranges::random_access_range R, class Comp = ranges::less,class Proj = std::identity >
 // requires std::sortable<ranges::iterator_t<R>, Comp, Proj>
 // constexpr ranges::borrowed_iterator_t<R>
 // sort( R&& r, Comp comp = {}, Proj proj = {} );
 //
 // 投影是将集合映射到子集的映射。
 //
 
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int id;
};
 
void printStudents(const std::vector<Student>& students)
{
    for (const auto& student: students) {
        std::cout << std::format("({} {})\n", student.name,
                student.id);
    }
    std::cout << "\n\n";
}
int main()
{
     std::vector<Student> studentCollection{{"jack",  10086},
                                        {"black", 10010},
                                        {"trump", 12345},
                                        {"job",   143235}};
     //printStudents(studentsCollection);
     //(jack 10086)
    // (black 10010)
    // (trump 12345)
    // (job 143235)
     std::ranges::sort(studentCollection, {}, &Student::name);
    // printStudents(studentCollection);
    // (black 10010)
    // (jack 10086)
    // (job 143235)
    // (trump 12345)
     std::ranges::sort(studentCollection, std::ranges::greater(), &Student::name);
     printStudents(studentCollection);
    // (trump 12345)
    // (job 143235)
    // (jack 10086)
    // (black 10010)
     std::ranges::sort(studentCollection, std::ranges::greater(), &Student::id);
     printStudents(studentCollection);
    // (job 143235)
    // (trump 12345)
    // (jack 10086)
    // (black 10010)
     std::ranges::sort(studentCollection, std::ranges::greater(), [](auto p) { return std::to_string(p.id) + p.name;});
     printStudents(studentCollection);
    // (job 143235)
    // (trump 12345)
    // (jack 10086)
    // (black 10010)
    return 0;
}
