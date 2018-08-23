/*************************************************************************
	> File Name: P1067-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 18时59分25秒
 ************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n, a;
    cin>>n;
    for (int i = n ; i >= 0; i--) {
        cin>>a;
        if (a) {
            if (i != n && a > 0) cout<<"+";
            if ((int)fabs(a) > 1 || i == 0) cout<<a;
            if (a == -1 && i) cout<<"-";
            if (i > 1) cout<<"x^"<<i;
            if (i == 1) cout<<"x";
        }
    }
    return 0;
}

