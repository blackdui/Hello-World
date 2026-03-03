//
// Created by blackdui on 2026/3/2.
//
#include <iostream>

using std::cout;
using std::endl;
int MaxBit(int arr[], int len)
{
    //找到最大的数
    int idx_max = 0;
    for (int i = 0; i < len; i++) {
       if (arr[idx_max] < arr[i]) {
           idx_max = i;
       }
    }
    int max = arr[idx_max];
    //取得最大数的位数
    int count = 0;
    while (max) {
        max /= 10;
        count++;
    }
    //不知道为啥 不写return会报错 illegal instruction
    return count;
}

void RedixSort(int arr[], int len) {
    //1.确定最大数的位数，即排序的趟数
    int digit = MaxBit(arr, len);
    //2.利用计数排序，对每位数进行排序，并更新数组
    int *temp = new int[len];
    int *count = new int[10];
    int redix = 1;
    for (int i = 1; i <= digit; i++) {
        //清空count
        for (int j = 0; j < 10;j++) {
            count[j] = 0;
        }
        //统计频率
        for (int j = 0; j < len; j++) {
            //取一个数中的一位
            int k = (arr[j] / redix) % 10;
            count[k]++;
        }
        //频率自加
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        //根据自加结果，逆序赋值给temp
        //对应关系
        //j可以为零
        for (int j = len - 1; j >= 0; j--) {
            int k = (arr[j] / redix) % 10;
            //将对应位置的完整值赋值给temp
            temp[--count[k]] = arr[j];
        }
        //temp中的数复制给arr
        for (int j = 0; j < len;j++) {
            arr[j] = temp[j];
        }

        //排序第二个位
        redix = redix * 10;
    }

    //3.重复2，直到所有位都排序完成
    delete[] temp;
    delete[] count;
}
int main()
{
    int arr[15]{3, 1, 2, 6, 5, 10, 33, 7, 9, 11, 21, 4, 84, 31, 40};
    //基数排序只需要排0-9十个数
    RedixSort(arr, std::size(arr));
    return 0;
}