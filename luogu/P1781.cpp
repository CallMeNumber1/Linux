/*************************************************************************
	> File Name: P1781.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 12时02分52秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 20
#define LEN 100
int max(char *a, char *b, int i, int j) {
    int lena = strlen(a), lenb = strlen(b);
    if (lena > lenb) {
        return i;
    } else if (lena < lenb) {
        return j;
    } else {
        for (int k = 0; k < lena; k++) {
            if (a[k] == b[k]) continue;
            if (a[k] > b[k]) {
                return i;
            } else {
                return j;
            }
        }
    } 
}
int main() {
    char str[MAX + 5][LEN + 5] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = max(str[ans], str[i], ans, i);
    }
    printf("%d\n%s\n", ans, str[ans]);
    return 0;
}

