/*************************************************************************
	> File Name: test.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月17日 星期五 10时49分20秒
 ************************************************************************/
//用位运算实现两数相加
#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int c, d;
        while(b != 0) {        //b=0时代表没有需要进位的了
            c = a ^ b;
            d = (a & b) << 1;  //a&b代表需要进位的位
            a = c;
            b = d;             
        }
    printf("%d\n", a);
    }
    return 0;
}

