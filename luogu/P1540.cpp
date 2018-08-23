/*************************************************************************
	> File Name: P1540.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 19时17分14秒
 ************************************************************************/

#include <stdio.h>
#define MAX 1000
int dic[MAX + 5] = {0};
int dic_len = 0;
int num, len, ans = 0;
int is_valid(int x) {
    for (int i = 0; i < len; i++) {
        if (dic[i] == x) return 1;
    }
    return 0;
}
int main() {
    int word;
    scanf("%d%d", &len, &num);
    for (int i = 0; i < len; i++) {
        dic[i] = -1;
    }
    for (int i = 0; i < num; i++) {
        scanf("%d", &word);
        if (!is_valid(word)) {
            ans++;
            dic[dic_len] = word;
            dic_len = (dic_len + 1) % len;
        }
    }
    printf("%d\n", ans);
    return 0;
}

