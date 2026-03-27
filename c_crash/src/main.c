#include <stdio.h>
typedef struct {
    int age;
} Student;

Student get_stud(const Student *stud)
{
    return (Student) {
        .age = stud->age
    };
}

int main(int argc, char *argv[])
{
      
    Student stud1 = { 8 };
    Student stud2 = get_stud(&stud1);

    printf("hello stud %d\n", stud2.age);
    return 0;
}
