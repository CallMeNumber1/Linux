/*************************************************************************
	> File Name: P1192.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月05日 星期三 20时03分30秒
 ************************************************************************/

#include <stdio.h>
#define MAX 100005
int keep[MAX] = {0};
int N, K;
int dfs(int n) {
    if (n < 0) return 0;
    if (keep[n]) return keep[n];
    if (n == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= K; i++) {
    // dfs返回的是搜索到一个解的结果,为1
        ans = (dfs(n - i) + ans) % 100003;
    }
    keep[n] = ans;
    return ans;
}

int main() {
    scanf("%d%d", &N, &K);
    printf("%d\n", dfs(N));
    return 0;
}

