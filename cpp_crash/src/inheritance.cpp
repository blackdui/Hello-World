#include <iostream>
#include "inheritance.h"

using std::cout;
using std::endl;
int main()
{
  Car car1("zhk111", 2077, "school");
  cout << "print the car infomation:" << endl;
  cout << "license:" << car1.license() << endl;
  cout << "style:" << car1.style() << endl;


  return 0;
}
