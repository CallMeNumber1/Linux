/*************************************************************************
	> File Name: P1057.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月07日 星期五 15时31分43秒
 ************************************************************************/
// 超时6个点
#include <stdio.h>
int n, m;
int ans = 0;
int dist(int pre) {
    int cnt1 = 0, cnt2 = 0;
    int temp = pre;
    while (temp > 0) {
        temp = (temp + 1) % n;
        cnt1++;
    }
    while (pre > 0) {
        pre = (pre + n - 1) % n;
        cnt2++;
    }
    return cnt1 < cnt2 ? cnt1 : cnt2;
}
void dfs(int step, int pre) {
    // 剪枝,如果剩下的步数不足以将球传回去
    if (dist(pre) > m - step) return;
    if (step == m) {
        if (pre == 0) {
            ans++;
        }
        return ;
    }
    // 因为n个人围城一个环,所以可用取余的方式来模拟
    // 因为从0开始容易模拟环,将问题转换成从0开始传,最后传到0
    dfs(step + 1, (pre + 1) % n); 
    dfs(step + 1, (pre + n - 1) % n);
}
int main() {
    scanf("%d%d", &n, &m);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}


