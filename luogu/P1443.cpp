/*************************************************************************
	> File Name: P1443.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月29日 星期三 17时16分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 405
int map[MAX][MAX];
int dir[8][2] = {  // 马的八个方向
    1, 2,
    2, 1,
    -1, 2,
    -2, 1,
    -2, -1,
    -1, -2,
    1, -2,
    2, -1
};
struct node {
    int x, y;
}que[MAX * MAX];
int main() {
    int n, m, sx, sy;
    int head, tail;
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    head = 1, tail = 1;
    que[head].x = sx;
    que[head].y = sy;
    memset(map, -1, sizeof(map));
    map[sx][sy] = 0;
    while (head <= tail) {
        int xx, yy;
        for (int k = 0; k < 8; k++) {
            xx = que[head].x + dir[k][0];
            yy = que[head].y + dir[k][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && map[xx][yy] == -1) {
                tail ++;
                que[tail].x = xx;
                que[tail].y = yy;
                map[xx][yy] = map[que[head].x][que[head].y] + 1;
            }
        }
        head++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

