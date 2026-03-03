//
// Created by blackdui on 2026/3/1.
//
#include <iostream>

using std::cout;
using std::endl;

void ShellSort(int *arr, int len)
{
    //1.选择递增序列
    int gap = 1;
    while (gap < len / 2)
    {
        gap = gap * 2 + 1;
    }
    //2.对每个序列进行插入排序
    while ( gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            for (int j = i; j >= gap&& arr[j] < arr[j - gap]; j-=gap)
            {
               std::swap(arr[j], arr[j - gap]);
            }
        }
        //3.缩小增量
        gap = gap / 2;
    }

}
int main()
{
    int arr[10] = {3, 1, 2, 14, 8,
     11, 7, 10, 9, 21};
    //希尔排序优化了插入排序
    ShellSort(arr, 10);
    return 0;
}