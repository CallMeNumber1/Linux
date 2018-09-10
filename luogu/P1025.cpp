/*************************************************************************
	> File Name: P1025.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月06日 星期四 08时38分05秒
 ************************************************************************/

#include <stdio.h>
#define MAXN 201
#define MAXK 7
int dp[MAXN][MAXK];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 2; i <= k; i++) {
        dp[1][i] = 0;
        dp[0][i] = 0;
    }
    // 分成两种情况: 至少有一个1和没有1
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i >= j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            } else {
                //当j大于i时,dp[i][j]实际上为0了已经
                dp[i][j] = dp[i - 1][j - 1];   
            }
            //printf("%d ", dp[i][j]);
        }
       // printf("\n");
    }
    printf("%d\n", dp[n][k]);
    return 0;
}

