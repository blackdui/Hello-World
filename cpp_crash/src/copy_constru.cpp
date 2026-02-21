#include <iostream>
using std::cout;
using std::endl;
class TestCopy {
  public:
    TestCopy(int i);
    TestCopy(const TestCopy& tc);
    ~TestCopy();
    int get_value();
  private:
    int i;

};
TestCopy::TestCopy(int i)
{
  cout << "constructor is invoked." << endl;
  this->i = i;
}
int TestCopy::get_value()
{
  return i;
}
TestCopy::TestCopy(const TestCopy& tc)
{
  cout << "copy constructor is invoked." << endl;
  i = tc.i;
}
TestCopy::~TestCopy()
{
  cout << "destructor" << endl;
}
void Display(TestCopy tc)
{
  cout << "The value is " << tc.get_value() << endl;
}
TestCopy GetTestcopy(int i)
{
  TestCopy tc1(i);
  return tc1; 
}
int main()
{
  using std::cout;
  using std::endl;
  
  TestCopy tc1(10);
  Display(tc1);//copy constructor

  TestCopy tc2 = GetTestcopy(8);//copy constructor
  Display(tc2);
 
  TestCopy tc3 = tc2;//copy constructor
  return 0;
}
