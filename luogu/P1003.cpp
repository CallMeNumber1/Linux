/*************************************************************************
	> File Name: P1003.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月15日 星期三 17时06分00秒
 ************************************************************************/

#include <stdio.h>
#define MAX 10000
typedef struct area{
    int x, y;  // 左下角坐标
    int lenx, leny; 
    
}Area;
int main() {
    int n, x, y;
    int ans = -1;
    scanf("%d", &n);
    Area areas[MAX + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &areas[i].x, &areas[i].y, &areas[i].lenx, &areas[i].leny);
    }
    scanf("%d%d", &x, &y);
    for (int i = n - 1; i >= 0; i--) {
        if (x >= areas[i].x && x <= areas[i].x + areas[i].lenx) {
            if (y >= areas[i].y && y <= areas[i].y + areas[i].leny) {
                ans = i + 1;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

