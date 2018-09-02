/*************************************************************************
	> File Name: P1141-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月29日 星期三 16时43分44秒
 ************************************************************************/
// bfs
#include <stdio.h>
char map[1001][1001];
int flag[1001][1001] = {0}, a[1000001] = {0};
struct mg {
    int x, y;
}q[1000001];
int main() {
    int n, m, head, tail;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", map[i] + 1);   
    }
    int d = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!flag[i][j]) {
                d++;       //记录所在的连通图
                head = 1;  //队首指针
                tail = 1;  //队尾指针
                q[head].x = i;
                q[head].y = j;
                flag[i][j] = d;
                int sum = 1;
                while (head <= tail) {
                    for (int k = 0; k < 4; k++) {
                        int xx = q[head].x + dx[k];
                        int yy = q[head].y + dy[k];
                        if (!flag[xx][yy] && xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] != map[q[head].x][q[head].y]) {
                            tail++;
                            sum++;   //能走到多少步
                            flag[xx][yy] = d;
                            q[tail].x = xx;
                            q[tail].y = yy;
                        }
                    }
                    head++;
                }
                a[d] = sum;  //保存当前连通图能走到多少格子
            }
        }
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", a[flag[x][y]]);
    }
    return 0;
}

