/*************************************************************************
	> File Name: P1056.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 10时02分14秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000
#define MAX_N 2000
int stu[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    int M, N, K, L, D;
    int x1, x2, y1, y2;
    int row[MAX_N + 5] = {0};
    int col[MAX_N + 5] = {0};
    int ansx[MAX_N + 5] = {0};
    int ansy[MAX_N + 5] = {0};
    scanf("%d%d%d%d%d", &M, &N, &K, &L, &D);
    int pair = 1; //当两个位置的ｐａｉｒ相等且不为０，则两者为一对
    for (int i = 0; i < D; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
        stu[x1][y1] = pair;
        stu[x2][y2] = pair;
        pair++;
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            if (stu[i][j] != 0 && stu[i + 1][j] == stu[i][j]) {
                row[i]++;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (stu[j][i] != 0 && stu[j][i + 1] == stu[j][i]) {
                col[i]++;
            }
        }
    }
    int j, max, ans = 0, len = 0;
    for (int i = 0; i < K - 1; i++) {
        max = -1;
        for (j = 1; j < M; j++) {
            if (row[j] > max) {
                max = row[j];
                ans = j;
            }
        }
        ansx[len] = ans;
        len++;
       // printf("%d ", ans);
        row[ans] = 0;
    }
    max = -1;
    for (j = 1; j < M; j++) {
        if (row[j] > max) {
            max = row[j];
            ans = j;
        }
    }
    ansx[len] = ans;
    len++;
    sort(ansx, ansx + len);
    len = 0;
    //printf("%d\n", ans);
    for (int i = 0; i < L - 1; i++) {
        max = -1;
        for (j = 1; j < N; j++) {
            if (col[j] > max) {
                max = col[j];
                ans = j;
            }
        }
        ansy[len] = ans;
        len++;
       // printf("%d ", ans);
        col[ans] = 0;
    }
    max = -1;
    for (j = 1; j < N; j++) {
        if (col[j] > max) {
            max = col[j];
            ans = j;
        }
    }
    //printf("%d\n", ans);
    ansy[len] = ans;
    len++;
    sort(ansy, ansy + len);
    for (int i = 0; i < K - 1; i++) {
        printf("%d ", ansx[i]);
    }
    printf("%d\n", ansx[K - 1]);
    for (int i = 0; i < L - 1; i++) {
        printf("%d ", ansy[i]);
    }
    printf("%d\n", ansy[L - 1]);
    return 0;
}

