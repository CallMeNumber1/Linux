/*************************************************************************
	> File Name: P1086.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月30日 星期四 21时16分46秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 25
int m, n, k;
int num[MAX][MAX];
// 找到最大值所在的坐标
void select(int &x, int &y) {
    int max = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (max < num[i][j]) {
                max = num[i][j];
                x = i, y = j;
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", num[i] + j);
        }
    }
    int x, y, tempx, tempy, ans = 0;
    select(x, y);
    // 特判 能否采到第一株植物
    if (k - 2 * x - 1 >= 0) {
        k = k - x - 1;
    } else {
        k = -1;
    }
    while (k >= 0) {
        ans += num[x][y];
        tempx = x, tempy = y;
        //选择完一次最大的要将其置为0, 选剩下的里面最大的
        num[x][y] = 0;
        select(x, y);
        //如果采完还能够回到大路上
        if(k - (int)fabs(x - tempx) - (int)fabs(y - tempy) - 1 - x >= 0) {
            k = k - (int)fabs(x - tempx) - (int)fabs(y - tempy) - 1;
        } else {
            break;
        }  
    }
    printf("%d\n", ans);
    return 0;
}

