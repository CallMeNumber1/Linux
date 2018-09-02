/*************************************************************************
	> File Name: P1433.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月01日 星期六 17时21分28秒
 ************************************************************************/
//dfs + 剪枝

#include <stdio.h>
#include <math.h>
#define MAX 15
struct node {
    double x, y;
}num[MAX];
int n;
int vis[MAX] = {0};
double min = 1231234424.0;
double temp = 0;
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void dfs(int step, double x, double y) {
    //剪枝,当前路径已经比当前最短的路径长了,就不必继续搜索
    if (temp > min) {
        return ;
    }
    if (step > n) {
        if (min > temp) {
            min = temp;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            temp += dist(x, y, num[i].x, num[i].y);
            dfs(step + 1, num[i].x, num[i].y);
            temp -= dist(x, y, num[i].x, num[i].y);
            vis[i] = 0;
        }
    }    
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &num[i].x, &num[i].y);
    }
    dfs(1, 0, 0);
    printf("%.2lf\n", min);
    return 0;
}

