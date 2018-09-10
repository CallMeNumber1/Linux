/*************************************************************************
	> File Name: P1226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月02日 星期日 20时40分17秒
 ************************************************************************/

#include <stdio.h>
typedef long long ll;
int main() {
    ll b, p, k;
    scanf("%lld%lld%lld", &b, &p, &k);
    ll ans = 1, temp = b, pp = p;
    while (pp) {
        if (pp & 1) ans = ((ans % k) * (temp % k)) % k;
        temp = ((temp % k) * (temp % k)) % k;
        pp = pp >> 1;
    }
    //当p为0时, 要做特殊处理,即再取一次余数
    ans = ans % k;
    printf("%lld^%lld mod %lld=%lld", b, p, k, ans);
    return 0;
}

