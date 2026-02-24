#include <iostream>
// typeid
#include <typeinfo>
#include <string>
#include <vector>
// sort
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;

struct Fruits {
  string kind;
  int price;

  Fruits(string k, int p)
    : kind(k), price(p) {}
};
int main()
{
  [] {
    cout << "hello lambda." << endl;
  } ();
  // assign lambda to a value

  auto my_lambda = [] {
    cout << "assigned lambda" << endl;
  };

  // cout << "type of my_lambda " << typeid(my_lambda).name() << endl;

  my_lambda();
  // function_name para_list return_value function_body
  // be aware of the semicolumn
  auto para_lambda = [] (const string &name) -> int
  {
    cout << name << endl;
    return 8;
  };

  cout << para_lambda("marisa") << endl;

  int b = 8;
  int a = 1;
  // = means capture other variables read only.
  auto capture_lambda = [ =, &b] {
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    b++;
  };

  capture_lambda();
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  vector<Fruits> v1{
      Fruits("banana", 11),
      Fruits("strawberry", 18),
      Fruits("orange", 7),
      Fruits("peanuts", 13),
      Fruits("cocknut", 5),
  }; 

  // define sort function_body

  auto sort_lambda = [] (const Fruits &f1, const Fruits &f2) -> bool
  {
    return f1.price < f2.price;
  };

  std::sort(v1.begin(), v1.end(), sort_lambda);

  for (const auto &i : v1)
  {
    cout << i.kind << " " << i.price << endl;
  }
  return 0;
}
