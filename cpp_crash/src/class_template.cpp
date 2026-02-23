#include <iostream>
#include <class_template.h>

using std::cout;
using std::endl;

int main()
{
  Point<int> p1(1,3);

  cout << "x:" << p1.x() << endl;
  cout << "y:" << p1.y() << endl;
  return 0;
}
