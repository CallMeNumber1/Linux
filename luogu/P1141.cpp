/*************************************************************************
	> File Name: P1141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月24日 星期五 22时58分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
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
int max = 0, temp = 0;
void dfs(int x, int y) {
    if (max < temp) {
        max = temp;
    }
    for (int k = 0; k < 4; k++) {
        int xx = x + dir[k][0];
        int yy = y + dir[k][1];
        if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
        if (map[xx][yy] != map[x][y] && !vis[x][y]) {
            vis[x][y] = 1;
            temp++;
            dfs(xx, yy);
            temp--;
            vis[x][y] = 0;
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        max = temp = 0;
        memset(vis, 0, sizeof(vis));
        dfs(x, y);
        printf("%d\n", max);
    }
    return 0;
}

