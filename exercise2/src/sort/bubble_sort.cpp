//
// Created by blackdui on 2026/3/1.
//

#include <iostream>

using std::cout;
using std::end;
void BubbleSort(int *arr, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 -i; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }
}
int main()
{
    int arr[10] = {3, 1, 2, 14, 8,
        11, 7, 10, 9, 21};

    BubbleSort(arr, 10);

    for (int n : arr)
    {
        cout << n << " ";
    }
    cout << "\n";
    return 0;
}