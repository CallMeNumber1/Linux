/*************************************************************************
	> File Name: P1059.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 11时51分32秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100
int is_valid(int *num, int len, int temp) {
    for (int i = 0; i < len; i++) {
        if (temp == num[i]) return 0;
    }
    return 1;
}
int main() {
    int n, temp;
    int num[MAX + 5], len = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (is_valid(num, len, temp)) {
            num[len] = temp;
            len++;
        }
    }
    printf("%d\n", len);
    sort(num, num + len);
    for (int i = 0; i < len; i++) {
        printf("%d ", num[i]);
    }
    return 0;
}

