//
// Created by blackdui on 2026/3/2.
//
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
void CountingSort(vector<int> &arr, vector<int> &sorted_arr)
{
    vector<int> count_arr(100);
    //1.统计频率
    for (int i = 0; i < arr.size(); i++)
        count_arr[arr[i]]++;
    //2.累加频率
    for (int i = 1; i < count_arr.size(); i++ )
        count_arr[i] += count_arr[i - 1];
    //3.按照2中数组的信息，把待排序数组的元素放到对应的位置上，反向填充，统计减一
    for (int i = arr.size(); i > 0; i--)
        sorted_arr[--count_arr[arr[i - 1]]] = arr[i - 1];
}
int main()
{
    vector<int> arr = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    vector<int> sorted_arr(std::size(arr));
    //计数排序和基数排序有关系
    CountingSort(arr, sorted_arr);
    return 0;
}