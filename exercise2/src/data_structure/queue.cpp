//
// Created by blackdui on 2026/3/5.
//
#include <iostream>

using std::cout;
using std::endl;

const int kArraySize = 100;

struct MyQueue {
  int arr[kArraySize];
  int head = 0;
  int tail = -1;
  
  int size() {return tail - head + 1;}
  void push(int item) {arr[++tail] = item;}
  void pop() {head++;}
  int front() {return arr[head];}
};
int main()
{

  MyQueue queue;
  for(int i = 0; i < 10; i++)
  {
    queue.push(i);
  }

  return 0;
}
