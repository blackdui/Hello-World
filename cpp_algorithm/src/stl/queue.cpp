#include <queue>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  std::queue<int> queue;
  for (int i = 0; i < 10; i++)
  {
    queue.push(i);
  }

  for (int i = 0; i < queue.size(); i++)
  {
    cout << queue.front() + i << endl;
  }
  return 0;
}
