/*************************************************************************
	> File Name: P1181.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月20日 星期一 21时42分24秒
 ************************************************************************/

#include <stdio.h>
#define MAX 100000
int main() {
    int N, M;
    int num[MAX + 5];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        sum += num[i];
        if (sum > M) {
            ans++;
            sum = num[i];
        }
    }
    if (sum != 0) {
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}

