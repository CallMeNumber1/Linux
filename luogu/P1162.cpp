/*************************************************************************
	> File Name: P1162.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 19时31分50秒
 ************************************************************************/

#include <stdio.h>
#define MAX 30
int n;
int num[MAX + 5][MAX + 5];
int is_valid(int i, int j) {
    //分别标志,0所在行列的上下左右均有1出现,则说明0被围起来
    int flag1 = 0, flag2 = 0;
    int flag3 = 0, flag4 = 0;
    for (int k = 0; k < n; k++) {
        if (num[k][j] == 1 && k < i) flag1 = 1;
        if (num[k][j] == 1 && k > i) flag2 = 1;
        if (num[i][k] == 1 && k < j) flag3 = 1;
        if (num[i][k] == 1 && k > j) flag4 = 1;
    }
    if (flag1 && flag2 && flag3 && flag4) {
        return 1;
    }
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num[i][j] == 0 && is_valid(i, j)) {
                num[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
   return 0;
}

