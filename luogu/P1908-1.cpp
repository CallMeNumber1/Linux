/*************************************************************************
	> File Name: P1908-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月05日 星期三 15时41分45秒
 ************************************************************************/
// 不能通过?? 待解决

// 此题使用树状数组要离散化,因为数字过大时,对应数组下标很大
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 500005
int n;
int c[MAX] = {0},a[MAX] = {0},b[MAX] = {0};
long long ans = 0;
int lowbit(int x) {
    return x & (-x);
}
// 更新
void add(int x, int k){
    for (; x <= n; x += lowbit(x)) c[x] += k;
}
// 求和
long long sum(int x) {
    long long ret = 0;
    for (; x > 0; x -= lowbit(x)) ret += c[x];
    return ret;
}
bool cmp1(const int &x, const int &y) { //离散化用的
    return b[x] > b[y];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        a[i] = i;
    }
    sort(a + 1, a + n + 1, cmp1); // 处理后,a数组中存的是元素为第几大
    for (int i = 1; i <= n; i++) {
        add(a[i], 1);
        ans += sum(a[i] - 1);
    }
    printf("%lld\n", ans);
    return 0;
}

