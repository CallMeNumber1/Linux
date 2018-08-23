/*************************************************************************
	> File Name: P1019.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 11时08分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define NUM 25
#define MAX 500
char str[NUM][MAX];
char start[MAX];
int vis[NUM] = {0};
int max = 0;
int temp = 0;
char maxstr[MAX] = {0};
char tempstr[MAX] = {0};
int min(int a, int b) {
    return a < b ? a : b;
}
int is_valid(char *temp, char *str) {  //如果重叠,返回重叠部分长度
    int lena = strlen(temp), lenb = strlen(str);
    for (int i = 1; i <= min(lena, lenb); i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            //printf("%c %c\n", temp[lena - i + j], str[j]);
            if (temp[lena - i + j] != str[j]) flag = 0;
        }
        if (flag) {
            return i;
        }
    }
    return 0;
}
void merge(char *a, char *b, int k) {   //k为重叠部分长度
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0; i < lenb - k; i++) {
        a[lena + i] = b[k + i];                   
    }
    a[lena + lenb - k] = '\0';
}
void dfs(int step, int n) {
    if (strlen(maxstr) < strlen(tempstr)) {
        strcpy(maxstr, tempstr);
        max = strlen(tempstr);
    }
    for (int i = 1; i <= n; i++) {
        char t[MAX];
        strcpy(t, tempstr);
        if (vis[i] >= 2) continue;  //每个单词最多用两次
        int k = is_valid(tempstr, str[i]);
        if (k) {
            vis[i]++;
            merge(tempstr, str[i], k);
            dfs(step + 1, n);
            vis[i]--;
            strcpy(tempstr, t);  //回溯
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
    }
    scanf("%s", start);
    strcpy(tempstr, start);
    strcpy(maxstr, start);
    dfs(1, n);
    printf("%d %s\n", max, maxstr);
    return 0;
}

