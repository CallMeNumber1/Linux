/*************************************************************************
	> File Name: main.c
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年10月07日 星期日 11时25分13秒
 ************************************************************************/

#include <stdio.h>
#include "is_prime.h"
#include "add.h"
#include "test.h"
#ifdef TEST_FUNC
    #include "testcase1.h"
    #include "testcase2.h"
#endif

int main() {
    printf("hello world\n");
    is_prime(5);
    add(2, 2);
    RUN_ALL_TEST();
}
