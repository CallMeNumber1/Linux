/*************************************************************************
	> File Name: P1071.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 20时48分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 105
int main() {
    char sec[MAX], trans[MAX], txt[MAX];
    int vis[27] = {0}, sign = 1;
    scanf("%s%s%s", sec, trans, txt);
    int lena = strlen(sec), lenb = strlen(txt);
    for (int i = 0; i < lena && sign; i++) {
        for (int j = 0; j < lena && sign; j++) {
            if (sec[i] == sec[j] && trans[i] != trans[j] || trans[i] == trans[j] && sec[i] != sec[j]) {
                sign = 0;
            }     //明文和密码下标是对应的
            vis[trans[i] - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (vis[i] == 0) sign = 0;
    }
    if (sign) {
        for (int i = 0; i < lenb; i++) {
            for (int j = 0; j < lena; j++) {  //解码
                if (txt[i] == sec[j]) {
                    printf("%c", trans[j]);
                    break;
                }
            }
        }
    } else {
        printf("Failed");
    }
}
