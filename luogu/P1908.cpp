/*************************************************************************
	> File Name: P1908.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月03日 星期一 22时46分38秒
 ************************************************************************/
// 归并排序的思想
// 此题目有数据逆序对的数量超出int范围
#include <stdio.h>
#include <inttypes.h>
#define MAX 1008611
int n;
int64_t ans = 0;
int a[MAX], r[MAX];
//s,t分别为左右端点
void msort(int s, int t) {
    if (s == t) return ;
    int mid = (s + t) / 2;
    // 要使用归并排序首先将数据进行分解, 一直分解到每一个单位,然后就是进行合并
    msort(s, mid);
    msort(mid + 1, t);
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] <= a[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = a[j++];
            ans += (mid - i + 1); //加上本次的逆序对数目
        }
    }
    while (i <= mid) 
        r[k++] = a[i++];
    while (j <= t)
        r[k++] = a[j++];
    for (int i = s; i <= t; i++) {
        a[i] = r[i];
    }
    return ;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    msort(1, n);
    printf("%"PRId64"\n", ans);
    return 0;

}

