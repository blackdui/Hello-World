#include <iostream>
#include <typeinfo>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

double multiply(double a, double b)
{
  return a * b;
}
int main()
{
  auto integer = 18;
  cout << "type of " << integer << " is " << endl;
  cout << typeid(integer).name() << endl; 

  auto result = multiply(3.3, 3.3);
  cout << "multiply type is " << typeid(result).name() << endl;

  vector<int> vec_int(5, 1);
  
  auto iterator = vec_int.begin();
  cout << "vec_int type is " << typeid(vec_int).name() << endl;
  
  return 0;
}
