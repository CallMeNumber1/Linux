/*************************************************************************
	> File Name: P1135.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月07日 星期五 22时15分35秒
 ************************************************************************/

#include <stdio.h>
#define MAX 201
int n, a, b;
int num[MAX];
int vis[MAX];
int min(int a, int b) {
    return a < b ? a : b;
}
int dfs(int pre) {
    if (pre == b) {
        return 1;
    }
    int ans = 10000;
    if (pre + num[pre] <= n && pre - num[pre] >= 1) {
        ans = min(dfs(pre + num[pre]), dfs(pre - num[pre]));
    } else if (pre + num[pre] <= n) {
        ans = dfs(pre + num[pre]);
    } else if (pre + num[pre] >= 1) {
        ans = dfs(pre - num[pre]);
    }
    return ans + 1;
}
int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    printf("%d\n",dfs(1) - 1);

    return 0;
}
