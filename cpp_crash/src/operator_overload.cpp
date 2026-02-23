#include <iostream>
#include "operator_overload.h"
using std::cout;
using std::endl;

int main()
{
  Person person1(8);
  Person person2(9);

  cout << (person1 + person2).age() <<endl;
  return 0;
}
