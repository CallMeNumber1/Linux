/*************************************************************************
	> File Name: P1223.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月20日 星期一 22时25分24秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef struct Node{
    int time;
    int ind;
}Node;
bool cmp(Node a, Node b) {
    return a.time < b.time;
}
int main() {
    int n;
    Node num[MAX + 5];
    double ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i].time);
        num[i].ind = i + 1;
    }
    sort(num, num + n, cmp);
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += num[j].time;
        }
        ans += sum;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i].ind);
    }
    printf("\n");
    printf("%.2lf\n", ans / n);
    return 0;
}
