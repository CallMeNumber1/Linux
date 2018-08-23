/*************************************************************************
	> File Name: P1208.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月20日 星期一 22时02分19秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#define MAX 5000
using namespace std;
typedef struct Node{
    int price;
    int num;
}Node;
bool cmp(Node a, Node b) {
    return a.price < b.price;
}
int main() {
    Node milk[MAX + 5];
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &milk[i].price, &milk[i].num);
    }
    sort(milk, milk + m, cmp);
    int total = n;
    int i;
    for (i = 0; i < m; i++) {
        if (total > milk[i].num) {
            total -= milk[i].num;
            sum += milk[i].price * milk[i].num;
        } else {
            break;
        }
    }
    sum += milk[i].price * total;
    total = 0;
    printf("%d\n", sum);
    return 0;
}

