#include <iostream>
#include "precise_class_template.h"

using std::cout;
using std::endl;

int main()
{
  Container<char> c1('d');
  cout << c1.Upper() << endl;
  return 0;
}
