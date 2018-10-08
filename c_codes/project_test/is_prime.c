/*************************************************************************
	> File Name: is_prime.c
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年10月07日 星期日 11时26分35秒
 ************************************************************************/

#include <stdio.h>
#include "is_prime.h"
#include "test.h"
FuncData *FuncData_head;

/* FuncData *getFuncData(
    const char *a,
    const char *b,
    test_func_t func,
    FuncData *next
)  {
    FuncData *p = (FuncData *)malloc(sizeof(FuncData));
    p->a_str = a;
    p->b_str = b;
    p->func = func;
    p->next = next;
    return p;
}*/


int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
