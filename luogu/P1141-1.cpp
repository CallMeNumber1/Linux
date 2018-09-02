/*************************************************************************
	> File Name: P1141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月24日 星期五 22时58分22秒
 ************************************************************************/
// dfs
// 此种方法会有一组数据超时
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1005
int n, m;
int dir[4][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};
int vis[MAX][MAX] = {0};
char map[MAX][MAX];
int f[MAX][MAX];
int ans[1000005][2];  //防止整张图就是一个联通块的情况
int now;
void dfs(int x, int y) {
    now++;
    ans[now][0] = x, ans[now][1] = y;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !vis[xx][yy] && map[x][y] != map[xx][yy]) {
            vis[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
}
int res;
char ch;
int read() {
    res = 0;
    while(isspace(ch = getchar()));
    do res = res * 10 + ch - '0'; while (isdigit(ch = getchar()));
    return res;
}
void write(int n) {
    if (n == 0) return ;
    write(n / 10);
    putchar(n % 10 + '0');
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);        //从数组第一个位置开始读
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                vis[i][j] = 1;
                now = 0;
                dfs(i, j);
                for (int k = 1; k <= now; k++) {
                    f[ans[k][0]][ans[k][1]] = now;
                }
            }
        }
    }
    /* for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\n", f[i][j]);
        }
    } */
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", f[x][y]);
    } 
    return 0;
}

