/*************************************************************************
	> File Name: print-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月13日 星期四 18时59分23秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    char str[100];
    for (int i = 0, j = 0; ; i++) {
        scanf("%d", &n);
        j += sprintf(str + j, "%d", n);
        printf("%s", str);
    }
    return 0;
}
