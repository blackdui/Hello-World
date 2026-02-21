#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string s1;

  s1 = "say hello to this world.";

  cout << s1 << endl;

  string s2 = "say hello to maria.";

  cout << s2 << endl;

  cout << "after swap." << endl;
  s1.swap(s2);
  cout << "now s1:" << s1 << endl;
  cout << "s2:" << s2 << endl;

  // replace every character in s1 with s.
  for (int i = 0; i < s1.size(); i++)
    s1.at(i) = 's'; 

  cout << "print after replace." << endl;
  cout << s1 << endl;

  cout << "print size and capacity of s1." << endl;
  cout << "size:" << s1.size() << endl;
  cout << "capacity:" << s1.capacity() << endl;

  s1.resize(5);
  cout << "print everthing after resize." << endl;
  cout << s1 << endl;
  cout << "size:" << s1.size() << endl;
  cout << "capacity" << s1.capacity() << endl;

  s1.shrink_to_fit();
  cout << "print everthing after shrink_to_fit." << endl;
  cout << s1 << endl;
  cout << "size:" << s1.size() << endl;
  cout << "capacity" << s1.capacity() << endl;
  

  return 0;
}
