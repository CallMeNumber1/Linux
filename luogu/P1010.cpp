/*************************************************************************
	> File Name: P1010.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月03日 星期一 21时56分55秒
 ************************************************************************/

#include <stdio.h>
#define MAX 20
void print(int n) {
    // n存储这个数,之后递归传递幂次
    if (n == 1) {
        return ;
    } else if (n == 0) {
        printf("0");
        return ;
    } else if (n == 2) {
        printf("2");
        return ;
    }
    // num数组从0开始记录数字对应的二进制的各位,下标与位权一一对应
    // len代表二进制的位数,num1代表其中二进制位中1的个数
    int num[MAX] = {0};
    int len = 0, num1 = 0;
    while (n) {
        if (n % 2 == 1) num1++;
        num[len] = n % 2;
        n = n / 2;
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        // 如果当前二进制位为1
        if (num[i] == 1) {
            // 如果当前二进制位的位权为1,则不输出括号
            if (i != 1) {
                printf("2(");
                print(i);
                printf(")");
            } else {
                printf("2");
            }
            num1--;
            if (num1 > 0) printf("+");
            //最后一个1时后面不输出+号,输出结束
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    print(n);
    return  0;
}

