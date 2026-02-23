#include <iostream>

using std::cout;
using std::endl;

template <typename T, typename U>
U sum(T a, U b)
{
  return a + b;
}
int main()
{
  cout << sum<int, int>(1,3) << endl;
  return 0;
}
