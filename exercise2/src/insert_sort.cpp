//
// Created by blackdui on 2026/3/1.
//
#include <iostream>

using std::cout;
using std::end;

void InsertSort(int *arr, int num)
{
    //1.分堆，已排序和未排序
    for (int i = 1; i < num; i++)
    {
        //2.找到已排序最后一个元素和未排序第一个元素
        //未排序
        int key = arr[i];
        //已排序
        int j = i - 1;
        //3.未排序依次和已排序元素比较
        while ( j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[10] = {3, 1, 2, 14, 8,
    11, 7, 10, 9, 21};
    InsertSort(arr, 10);
    return 0;
}