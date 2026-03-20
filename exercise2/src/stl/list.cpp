#include <list>
#include <iostream>

using std::cout;
using std::endl;
int main()
{
  std::list<int> list1 = {1, 2, 3, 4}; 
  std::list<int>::iterator it = list1.begin();

  it++;
  for(auto item : list1)
  {
    cout << item << endl;
  }
}
