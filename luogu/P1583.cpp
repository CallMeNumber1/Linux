/*************************************************************************
	> File Name: P1583.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 19时57分11秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 20000
typedef struct Node{
    int weight;
    int number;
}Node;
bool cmp(Node a, Node b) {
    if (a.weight == b.weight) {
        return a.number < b.number;
    }
    return a.weight > b.weight;
}
int main() { 
    int n, k;
    Node people[MAX + 5];
    int E[11];
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &E[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &people[i].weight);
        people[i].number = i;
    }
    sort(people + 1, people + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        people[i].weight = people[i].weight + E[(i - 1) % 10 + 1];
    }
    sort(people + 1, people + 1 + n, cmp);
    for (int i = 1; i <= k; i++) {
        printf("%d ", people[i].number);
    }
    return 0;
}

