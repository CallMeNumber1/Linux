/*************************************************************************
	> File Name: P1803.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月21日 星期二 09时05分29秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef struct Node {
    int left;
    int right;
}Node;
bool cmp(Node a, Node b) {
    return a.right < b.right;
}

int main() {
    int n;
    Node num[MAX + 5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &num[i].left, &num[i].right);
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
        printf("l = %d r = %d\n", num[i].left, num[i].right);
    }
    Node temp = num[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (temp.right <= num[i].left) {
            ans++;
            temp = num[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}

