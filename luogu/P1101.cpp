/*************************************************************************
	> File Name: P1101.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 15时31分15秒
 ************************************************************************/
//方向数组即可解
#include <stdio.h>
#define MAX 100
char str[MAX + 5][MAX + 5];
int mark[MAX + 5][MAX + 5] = {0};
char word[] = "yizhong";
int dir[8][2] = {  //八个方向
    0, 1,
    0, -1,
    1, 0,
    -1, 0,
    -1, -1,
    -1, 1,
    1, -1,
    1, 1
};

int main() {
    int n;
    scanf("%d", &n);
    //输出时用%c读入会莫名WA
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 8; k++) {
                int flag = 1;
                for (int step = 0; step < 7 && flag; step++) {
                    int xx = i + dir[k][0] * step;
                    int yy = j + dir[k][1] * step;
                    if (xx < 1 || xx > n || yy < 1 || yy > n) {
                        flag = 0;
                    }
                    if (str[xx][yy] != word[step]) {
                        flag = 0;
                    }
                }
                if (flag) {  //成立,则做上标记
                    for (int step = 0; step < 7; step++) {
                        int xx = i + dir[k][0] * step;
                        int yy = j + dir[k][1] * step;
                        mark[xx][yy] = 1;
                    }
                }
            }
        }    
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mark[i][j] == 1) printf("%c", str[i][j]);
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}

