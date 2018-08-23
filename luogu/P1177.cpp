/*************************************************************************
	> File Name: P1177.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 11时04分18秒
 ************************************************************************/
//普通快排

#include <stdio.h>
#define MAX 100000
//一趟快排
int Partition(int *num, int low, int high) {
    int pivot = num[low];  //选择第一个元素作为枢纽元
    while (low < high) {
        //从后向前找到第一个小于pivot的元素，放到low位置
        while (low < high && num[high] >= pivot) high--;
        num[low] = num[high];
        //从前往后找到第一个大于pivot的元素,放到high位置
        while (low < high && num[low] <= pivot) low++;
        num[high] = num[low];
    }
    //该元素归位
    num[low] = pivot;
    return low;
}
void Quick_sort(int *num, int low, int high) {
    if (low < high) {    //注意不要写成while
        int pivot = Partition(num, low, high);
        Quick_sort(num, low, pivot - 1);
        Quick_sort(num, pivot + 1, high);
    }
}
int main() {
    int num[MAX + 5];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    Quick_sort(num, 0, N - 1);
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[N - 1]);
}

