#include <iostream>
template <typename T> int Partition1(T *arr, int low, int high)
{
    // 确定基准元素
    int pivot = arr[low];
    // 分区
    while (low < high)
    {
        while (low < high && arr[high] > pivot)
            --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    // 确定基准元素位置
    arr[low] = pivot;
    return low;
}

template <typename T> void QuickSort(T *arr, const int low, const int high)
{
    if (low < high)
    {
        int index = Partition1<T>(arr, low, high);
        QuickSort(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
    }
}
int main()
{
    int arr[15] { 3, 1, 2, 6, 5,
        10, 33, 7, 9, 11,
        21, 4, 84, 31, 40};

    QuickSort(arr, 0, 14);
    return 0;
}
