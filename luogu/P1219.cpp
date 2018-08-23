/*************************************************************************
	> File Name: P1219.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 10时00分26秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 13
int a[MAX + 5] = {0};
int count = 0;
int place(int i, int j) {    //第i行j列能否放置皇后
    for (int m = 1; m < i; m++) {
        if (a[m] == j || fabs(i - m) == fabs(a[m] - j)) {
            return 0;
        }
    }
    return 1;
}
void dfs(int step, int N) {  //已经放了step个棋子,一共要放n个棋子
    if (step > N) {
        count++;
        if (count <= 3) {
            for (int i = 1; i <= N; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        return ;
    }
    for (int i = 1; i <= N; i++) {
        if (place(step, i)) {
            a[step] = i;
            dfs(step + 1, N);
            a[step] = 0;
        }
    }   
}

int main() {
    int n;
    scanf("%d", &n);
    dfs(1, n);
    printf("%d\n", count);
    return 0 ;
}

