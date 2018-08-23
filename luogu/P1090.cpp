/*************************************************************************
	> File Name: P1090.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月20日 星期一 14时01分06秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX 20000
int64_t ans = 0;
void select_min(int64_t *num, int i) {
    //m n分别为最小的两个数的下标
    int64_t min1 = INT64_MAX, min2 = INT64_MAX, m = -1, n = -1;
    for (int j = 0; j < i; j++) {
        if (num[j] == -1) continue; //已经寻找过
        if (num[j] < min1) {
            min1 = num[j];
            m = j;
        }
    }
    //printf("i = %d m = %"PRId64"\n", i, num[m]);
    num[i] += num[m];
    num[m] = -1;
    for (int j = 0; j < i; j++) {
        if (num[j] == -1) continue;
        if (num[j] < min2) {
            min2 = num[j];
            n = j;
        }
    }
   // printf("i = %d m = %"PRId64"\n", i, num[n]);
    num[i] += num[n];
    ans += num[i];
    num[n] = -1;
}
int main() {
    int n;
    int64_t num[MAX + 5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%"PRId64"", &num[i]);
    }
    for (int i = n; i < 2 * n - 1; i++) {
        select_min(num, i);
    }
    //ans为新合并所耗费体力的累加
    printf("%"PRId64"\n", ans);
    return 0;
}

