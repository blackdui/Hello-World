#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void PrintVector(vector<int> &v)
{
  for (int i = 0; i < v.size(); i ++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main()
{
  vector<int> v1;
  // vector<int> v1(4, 5)
  // four numbers, default value is 5
  
  for (int i = 0; i < 10; i++)
  {
    v1.push_back(i);
  }

  PrintVector(v1);

  //first element
  // cout << v1.front() << endl;
  // cout << v1[0] << endl;
  //last element
  // cout << v1.back() << endl;
  
  // clear
  v1.clear();
  cout << "print after clear.";
  PrintVector(v1);
  
  v1.resize(10);
  
  cout << "initialize." << endl;
  for (int i = 0; i < 10; i++)
  {
    v1.at(i) = i;
  }
  PrintVector(v1);

  // insert not replace
  v1.insert(v1.begin() + 4, 15);
  cout << "print after insert v1.begin + 4" << endl;
  PrintVector(v1);

  v1.erase(v1.begin() + 4);
  cout << "print after erase." << endl;
  PrintVector(v1);

  v1.pop_back();
  cout << "print after delete the last element." << endl;
  PrintVector(v1);
  return 0;
}
