/*************************************************************************
	> File Name: P1177-1.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 11时40分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void swap(int *num, int i, int j) {
    int temp;
    temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}
void Quick_sort(int *num, int left, int right) {
    int i, pivot;
    if (left >= right)
        return;
    pivot = left;
    swap(num, left, (left + right) / 2);
    for (i = left + 1; i <= right; i++) {
        if (num[i] < num[left]) {
            swap(num, i, ++pivot);
        }
    }
    swap(num, left, pivot);
    Quick_sort(num, left, pivot - 1);
    Quick_sort(num, pivot + 1, right);
}
int main() {
    int n;
    int *num;
    scanf("%d", &n);
    num = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        scanf("%d", num + i);
    }
    sort(num + 1, num + n + 1);
    for (int i = 1; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[n]);
    return 0;
}

