/*************************************************************************
	> File Name: P1605.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 16时36分01秒
 ************************************************************************/

#include <stdio.h>
#define MAX 5
int map[MAX + 5][MAX + 5] = {0};
int vis[MAX + 5][MAX + 5] = {0};
//上下左右四个方向
int dir[4][2] = {
    0, -1,
    0, 1,
    1, 0,
    -1, 0
};
int cnt = 0;
int n, m, t;
void dfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        cnt++;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x1 + dir[i][0];
        int yy = y1 + dir[i][1];
        //越界的情况,则换方向
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        //能走通且没有走过
        if (map[xx][yy] == 0 && vis[xx][yy] == 0) {
            //走过的地方标记上
            vis[x1][y1] = 1;  //标记x1而非xx, x1还未标记过
            dfs(xx, yy, x2, y2);
            vis[x1][y1] = 0;
        }
    }
}
int main() {
    int x1, y1, x2, y2;
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y] = -1;  
    }
    dfs(x1, y1, x2, y2);
    printf("%d\n", cnt);
    return 0;
}

