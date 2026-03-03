//
// Created by blackdui on 2026/3/2.
//
#include <algorithm>
#include <bits/std_thread.h>
#include <iostream>

using std::cout;
using std::endl;
void Heapify(int arr[], int start, int end)
{
    //确定父子节点
    //大顶堆的父节点都大于子节点
    //函数每次交换一个节点
    //end为最后一个元素的索引
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        if (son + 1 <=end && arr[son] < arr[son + 1])
        {
            son++;
        }
        //父节点更大就直接返回
        if (arr[dad] > arr[son])
            return;
        else
        {
            std::swap(arr[dad], arr[son]);
            //父节点继续和孙节点比较
            dad = son;
            son = dad * 2 + 1;
        }
    }

}
void HeapSort(int arr[], int len)
{
    //1.建立堆
    //len / 2 - 1是最后一个父节点, i是父节点索引, len - 1是最大索引
    for (int i = len / 2 - 1; i >=0; --i)
    {
        Heapify(arr, i, len - 1);
    }
    //2.交换堆顶和堆底，重新建立堆，从最后一个元素开始
    //交换后最后一个元素有序，不需要再参与建立堆
    for (int i = len - 1;i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        Heapify(arr, 0, i - 1);
    }

}
int main()
{
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = std::size(arr);

    //堆思想的选择排序
    HeapSort(arr, len);
    return 0;
}