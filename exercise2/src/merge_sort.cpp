//
// Created by blackdui on 2026/3/1.
//
#include <iostream>
#include <limits>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
void Merge(vector<int> &v1, int first, int mid, int end)
{
    //分组的具体实现
    //v1是同一个数组
    vector<int> left_arr(v1.begin() + first, v1.begin() + mid + 1);
    vector<int> right_arr(v1.begin() + mid + 1, v1.begin() + end + 1);

    //使下面的for循环可以把左右数组的所有元素放入v1中
    left_arr.insert(left_arr.end(), std::numeric_limits<int>::max());
    right_arr.insert(right_arr.end(), std::numeric_limits<int>::max());

    int idx_left = 0, idx_right = 0;

    for (int i = first; i <= end; i++)
    {
        if (left_arr[idx_left] < right_arr[idx_right])
        {
            v1[i] = left_arr[idx_left];
            idx_left++;
        } else
        {
            v1[i] = right_arr[idx_right];
            idx_right++;
        }
    }


}

void MergeSort(vector<int> &v1, int first, int end)
{
    //1.分成两部分
    if (first >= end)
        return;

    int mid = (first + end) / 2;
    //2.两部分分别归并排序
    MergeSort(v1, first, mid);
    MergeSort(v1, mid + 1, end);

    //3.合并有序数组
    Merge(v1, first, mid, end);
}
int main()
{
    vector<int> v1 = {3, 1, 2, 14, 8,
    11, 7, 10, 9, 21};
    MergeSort(v1, 0, 9);
    return 0;
}