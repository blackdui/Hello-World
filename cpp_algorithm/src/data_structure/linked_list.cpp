//
// Created by blackdui on 2026/3/4.
//

#include <iostream>
using std::cout;
using std::endl;
//静态链表
const int kNodeNum = 100;
struct Node {
  int id;
  int data;
  int next_id;
} nodes[kNodeNum];

void Delete(Node nodes[], int id) {
  //pre不一定是上一个元素
  nodes[id - 1].next_id = id + 1;
}
void Initialize(Node nodes[], int len) {
  nodes[0].next_id = 1;
  for (int i = 1; i < len - 1; i++) {
    nodes[i].id = i;
    nodes[i].next_id = i + 1;
  }
  //循环链表
  nodes[len - 1].next_id = 1;
}
void Show(Node nodes[], int len) {
  int now = nodes[0].next_id;
  for (int i = 0; i < len ; i++) {
    cout << nodes[now].data << " ";
    now = nodes[now].next_id;
  }
  cout << endl;
}
int main() {
  // 初始化
  // 零号索引的下一个为开始节点 
  Initialize(nodes, 10);
  //遍历链表
  Show(nodes, 10); 
  //删除节点
    
  // Delete(nodes, 8); 
  // 插入节点
  // Insert();
  
  return 0;
}
