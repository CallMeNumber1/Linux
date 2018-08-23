/*************************************************************************
	> File Name: P1031.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 17时19分54秒
 ************************************************************************/

#include <stdio.h>
#define MAX 100
int max_loc(int *num, int n) {
    int max = 0, ans = -1;
    for (int i = 0; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
            ans = i;
        }
    }
    return ans;
}
int main() {
    int N, sum = 0, ans = 0;
    int num[MAX + 5];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    sum /= N;   //每个位置应该放的牌数
    int loc = max_loc(num, N);
    while (num[loc] > sum) { 
        printf("loc = %d\n", loc);
        if (loc == 0) {
            ans++;
            num[loc] = num[loc] - (num[loc] - sum);
            num[loc + 1] += (num[loc] + sum);

        } else if (loc == N - 1) {
            ans++;
            num[loc] = num[loc] - (num[loc] - sum);
            num[loc - 1] += (num[loc] + sum);
        } else {
            num[loc] = num[loc] - (num[loc] - sum);
            int sum_left = 0, sum_right = 0;
            for (int i = 0; i < loc; i++) {
                sum_left += num[i];
            }
            for (int i = loc + 1; i < N; i++) {
                sum_right += num[i];
            }
            //求出ｌｏｃ左半部分和右半部分分别需要的牌数
            sum_left = (loc - 0) * sum - sum_left;  
            sum_right = (N - loc - 1) * sum - sum_right;
            if (sum_left) ans++;    //sum_left不为0表示需要向左传
            if (sum_right) ans++;
            num[loc + 1] += sum_right;
            num[loc - 1] += sum_left;
        }
        loc = max_loc(num, N);
    }
    printf("%d\n", ans);
    return 0;
}

