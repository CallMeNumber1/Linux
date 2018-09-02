/*************************************************************************
	> File Name: P1118.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月29日 星期三 21时54分20秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#define MAX 12
using namespace std;
int main() {
    int n, sum;
    int num[MAX + 5];
    int ans[MAX + 5];
    scanf("%d%d", &n, &sum);
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            ans[i] = num[i];
        }
        // 进行n-1次
        for (int i = 0; i < n - 1; i++) {  
            for (int j = 0; j < n - i - 1; j++) {
                ans[j] = ans[j] + ans[j + 1];
            }
        }
        if (ans[0] == sum) {
            for (int i = 0; i < n; i++) {
                printf("%d ", num[i]);
            }
            printf("\n");
            break;
        }
    } while (next_permutation(num, num + n));
    return 0;
}
