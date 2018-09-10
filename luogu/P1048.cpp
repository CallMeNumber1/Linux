/*************************************************************************
	> File Name: P1048.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月05日 星期三 16时23分47秒
 ************************************************************************/
// 动态规划
// dp[i][j] 代表在时间i内,前j种物品时,可拿的最大价值
// dp[i][j] = max(dp[i - time[j]][j - 1] + value[j], dp[i][j - 1]) 
// 状态转移方程中,分别代表拿不拿第j种物品
#include <stdio.h>
#define MAXT 1005
#define MAXM 105
int T, M;
int time[MAXM];
int value[MAXM];
int dp[MAXT][MAXM];
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    scanf("%d%d", &T, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &time[i], &value[i]);
    }
    for (int i = 1; i <= M; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= T; i++) {
        dp[T][0] = 0;
    }
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= M; j++) {
            // 有时间采第j种药时 
            if (i >= time[j]) {
                dp[i][j] += max(dp[i - time[j]][j - 1] + value[j], dp[i][j - 1]);
            } else { 
                // 没时间采第j种药时
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    printf("%d\n", dp[T][M]);
    return 0;
}


