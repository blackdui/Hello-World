#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::shared_ptr;

int main()
{
  // free heap memory when no need.
  // reference count

  shared_ptr<int> shared_ptr1(new int(5));
  shared_ptr<int> shared_ptr2 = shared_ptr1;

  // print the count
  cout << "the count is " << shared_ptr2.use_count() << endl;

  // weak pointer 
  // is pointer null or deallocated.
  // count will not increase.It is not the owner of this piece of memory.cyclic
  std::weak_ptr weak_ptr1 = shared_ptr1;

  cout << "weak_ptr count is " << weak_ptr1.use_count() << endl;

  //upgrade weak to shared_ptr1

  auto shared_ptr3 = weak_ptr1.lock();

  cout << "shared_ptr3 count is " << shared_ptr3.use_count() << endl;
  
  shared_ptr1.reset();
  shared_ptr2.reset();

  cout << "free shared_ptr1 and 2" << endl;
  cout << "shared_ptr3 count is " << shared_ptr3.use_count() << endl;
  cout << "shared_ptr3 unique " << shared_ptr3.unique() << endl;

  shared_ptr3.reset();

  // check if valid
  cout << "free shared_ptr3 " << shared_ptr3.get() << endl;

  // unique_ptr is the only owner.
  std::unique_ptr<int> unique_ptr1(new int(5));
  return 0;
}
