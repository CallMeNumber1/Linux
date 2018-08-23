/*************************************************************************
	> File Name: P1067.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 17时22分53秒
 ************************************************************************/
//第一项单独输出，其他项循环输出
//第一项前无+号
//当系数、指数为1时，不显示系数，指数显示为x
//当系数为0时，此项的指数部分不显示
//注意常数项为1时要照常显示
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
char ans[MAX*100000] = {0};
char * get_string(int x) {
    if (x == 0) {
        char * num = (char *)malloc(sizeof(char) * 10);
        num[0] = '\0';
        return num;
    }
    if (x == 1) {
        char *num = (char *)malloc(sizeof(char) * 10);
        num[0] = 'x';
        return num;
    }
   /* if (x < 0) {
        x = (int)fabs(x);
        int digit = (int)floor(log10(x)) + 1;
        char *num = (char *)malloc(sizeof(char) * (digit + 2));
        int i = digit;
        while (x) {
            num[i] = (char)((x % 10) + '0');
            x /= 10;
            i--;           
        }
        num[0] = '-';
        return num;
    } */
        int digit = (int)floor(log10(x)) + 1;
        char *num = (char *)malloc(sizeof(char) * (digit + 3));
        int i = digit + 1;
        while (x) {
            num[i] = (char)((x % 10) + '0');
            x /= 10;
            i--;
        }
        num[0] = 'x';
        num[1] = '^';
        return num;
}

void get(char *temp, int i) {
    if (temp[0] == '0') {
        temp[0] = '\0';
    }
    else if (temp[0] == '-') {
        if (strlen(temp) == 2 && temp[1] == '1') {
            if (i != 0) {
            temp[0] = '-';
            temp[1] = '\0';
            strcat(temp, get_string(i));
            }   
        } else {
            strcat(temp, get_string(i));
        }
    } else {
        if (temp[0] == '1' && strlen(temp) == 1) {
            if (i != 0) {
                temp[0] = '+';
                strcat(temp, get_string(i));
            } else {
                temp[0] = '+';
                temp[1] = '1';
            }  
        } else {
            char *coef = (char *)malloc(sizeof(char) * 10);
            coef[0] = '+';
            strcat(coef, temp);
            strcat(coef, get_string(i));
            temp = coef;
        }
    }
    strcat(ans, temp);
}

int main() {
    int n;
    char num[MAX + 5][MAX + 5];
    //printf("%s", get_string(5));
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%s", num[i]);
    }
    if (strlen(num[0]) == 1 && num[0][0] == '1') {
        strcat(ans, get_string(n));
    } else if (num[0][0] == '-' && strlen(num[0]) == 2 && num[0][1] == '1'){
        ans[0] = '-';
        strcat(ans, get_string(n));
    } else {
         strcat(ans, num[0]);
            strcat(ans, get_string(n));
    }
    for (int i = 1; i < n + 1; i++) {
        get(num[i], n - i);
    } 
    printf("%s\n", ans);
    return 0;
}

