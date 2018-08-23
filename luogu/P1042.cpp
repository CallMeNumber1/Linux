/*************************************************************************
	> File Name: P1042.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 18时06分36秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 63000
int is_valid(char *num) {
    for (int i = 0; num[i]; i++) {
        if (num[i] == 'E') return 0;
    }
    return 1;
}
int main() {
    char num[MAX] = {0};
    char temp[30];
    int W = 0, L = 0, count = 0;
    do {
        scanf("%s", temp);
        strcat(num, temp);
        temp[0] = '\0';
    } while (is_valid(num));
    for (int i = 0; num[i]; i++) {
        if (num[i] == 'W') {
            W++;
        } else if (num[i] == 'L') {
            L++;    
        }
        count++;
        //并且要保证分差大于２
        if (W >=11 && W - L > 1 || L >= 11 && L - W > 1|| num[i] == 'E') {
            printf("%d:%d\n", W, L);
            count = 0;
            W = 0;
            L = 0;
            if (num[i] == 'E') break;
        } 
    }
    W = 0, L = 0, count = 0;
    printf("\n");
    for (int i = 0; num[i]; i++) {
        if (num[i] == 'W') {
            W++;
        } else if (num[i] == 'L') {
            L++;    
        }
        count++;
        if (W >= 21 && W - L > 1|| L >= 21 && L - W > 1|| num[i] == 'E') {
            printf("%d:%d\n", W, L);
            count = 0;
            W = 0;
            L = 0;
            if (num[i] == 'E') break;
        } 
    }

    
    return 0;
}

