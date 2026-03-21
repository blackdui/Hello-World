//
// Created by blackdui on 2026/3/1.
//
#include <iostream>

using std::cout;
using std::endl;
void selection_sort(int *arr, int num)
{
    int temp;
    for (int i = 0; i < num - 1; ++i)
    {
        int min_pos = i;
        for (int j = i; j < num; ++j)
        {
            if (arr[min_pos] > arr[j])
                min_pos = j;
        }
        temp = arr[min_pos];
        arr[min_pos] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[10] = {3, 1, 2, 14, 8,
        11, 7, 10, 9, 21};
    selection_sort(arr, 10);

    return 0;
}