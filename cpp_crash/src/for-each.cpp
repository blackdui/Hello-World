#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
  for (int i : { 1, 2, 3, 4, 5})
    cout << i << " ";
  cout << endl;
  //create vector
  vector<int> v1;
  int temp;

  for (unsigned int i = 0; i < 10; i++)
  {
    temp = rand() % 100;
    cout << temp << " ";
    v1.push_back(temp);
  }
  cout << endl;

  for (auto &i : v1)
  {
    i++;
  }

  for (unsigned int i = 0; i < v1.size(); i++ )
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
