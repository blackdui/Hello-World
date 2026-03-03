//
// Created by blackdui on 2026/3/2.
//
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const int kBucketNum = 10;

struct ListNode {
  int data;
  ListNode *next;
  //explicit防止隐式转换
  explicit ListNode(int i = 0) : data(i), next(NULL) {}
};

ListNode *Insert(ListNode *head, int data) {
  ListNode dummy_node;

  dummy_node.next = head;
  // dummy_node
  ListNode *pre = &dummy_node;
  ListNode *current = head;
  // 分配内存，避免临时变量销毁
  ListNode *new_node = new ListNode(data);

  // 移动指针，给data让位
  //curren不为空即可，pre无关，否则循环会一直进行下去
  //错误代码 while(NULL != pre && NULL != current)

    while (NULL != current && current->data <= new_node->data) {
      pre = current;
      current = current->next;
    }
  pre->next = new_node;
  new_node->next = current;
  // 第一个节点大于new_node时，pre就是dummy，下一个节点为new_node，返回new_node作为头结点
  return dummy_node.next;
}

ListNode *Merge(ListNode *head1, ListNode *head2) {
  ListNode dummy_node;
  ListNode *dummy = &dummy_node;

  //和归并排序的合并有点像，两两比较然后放到对应位置
  while (NULL != head1 && NULL != head2) {
    if (head1->data <= head2->data) {
      dummy->next = head1;
      head1 = head1->next;
    } else {
      dummy->next = head2;
      head2 = head2->next;
    }
    dummy = dummy->next;
  }

  //剩余元素放到链表中
  if (NULL != head1) dummy->next = head1;
  if (NULL != head2) dummy->next = head2;

  //返回临时变量的next，也就是第一个元素的地址
  return dummy_node.next;
}

void BucketSort(int arr[], int len) {
  // 1.初始化桶
  vector<ListNode *> buckets(kBucketNum, (ListNode *)0);
  // 2.用映射函数把元素均匀分配到每个桶中
  for (int i = 0; i < len; i++) {
    int index = arr[i] / kBucketNum;
    ListNode *head = buckets.at(index);
    //head可能会变
    buckets.at(index) = Insert(head, arr[i]);
  }
  // 3.对每个桶的元素排序
  // 4.合并桶
  ListNode *head = buckets.at(0);
  for (int i = 1; i < kBucketNum; i++) {
    head = Merge(head, buckets.at(i));
  }
  // 5.把每个元素按顺序放回arr中

  //该方法少复制了一个元素
  //判断改成head应该可以
  // int j = 0;
  // while (head->next) {
  //   arr[j] = head->data;
  //   j++;
  //   head = head->next;
  // }

  int j = 0;
  while (head) {
    arr[j] = head->data;
    j++;
    head = head->next;
  }
  // for (int i = 0; i < len; i++) {
  //   arr[i] = head->data;
  //   head = head->next;
  // }
}

int main() {
  // 桶排序是计数排序的优化版本
  int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,
               0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
  BucketSort(arr, std::size(arr));
  return 0;
}
