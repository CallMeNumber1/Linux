/*************************************************************************
	> File Name: P1434.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月29日 星期三 22时36分02秒
 ************************************************************************/
// 记忆化搜索版
#include <stdio.h>
#define MAX 105
int map[MAX][MAX];
int keep[MAX][MAX];
int dir[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1
};
int r, c;
int max(int a, int b) {
    return a > b ? a : b;
}
int search(int i, int j) {
    // 不需要对为1时的情况单独判断, 否则会导致和1相邻的最终结果都为2
    if (keep[i][j]) return keep[i][j];
    int max_left = 0, max_right = 0;
    int max_up = 0, max_down = 0;
    if (j > 1 && map[i][j] > map[i][j - 1]) max_left = search(i, j - 1);
    if (j < c && map[i][j] > map[i][j + 1]) max_right = search(i, j + 1);
    if (i > 1 && map[i][j] > map[i - 1][j]) max_up = search(i - 1, j);
    if (i < r && map[i][j] > map[i + 1][j]) max_down = search(i + 1, j);
    int max1 = max(max_left, max_right);
    int max2 = max(max_up, max_down);
    keep[i][j] = max(max1, max2) + 1;
    return keep[i][j];
}
/* 记忆化搜索第二种写法
int search(int i, int j) {
    int t = 1, xx, yy;
    if (keep[i][j]) return keep[i][j];
    for (int i = 0; i < 4; i++) {
        xx = x + dir[i][0];
        yy = y + dir[i][2];
        if (check(xx, yy) && map[i][j] > map[xx][yy]) {
            temp = search(xx, yy) + 1;
            if (temp > t) t = temp;
        }
    }
    f[i][j] = t;
    return f[i][j];
} */
int main() {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", map[i] + j);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            search(i, j);
        }
    }
    int max = keep[1][1];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (max < keep[i][j]) max = keep[i][j];
        }
    }
    printf("%d\n", max);
    return 0;
}

