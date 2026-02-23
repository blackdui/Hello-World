#include <iostream>
#include "polymorphism.h"

using std::cout;
using std::endl;

int main()
{
  Vehicle v1("maria", 19);
  cout << v1.GetDesc() << endl;

  Car car1("reia", 19, "fried chicken");
  Vehicle *v2 = &car1;

  cout << v2->GetDesc() << endl;
  return 0;
}
