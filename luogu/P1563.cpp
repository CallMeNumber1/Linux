/*************************************************************************
	> File Name: P1563.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 16时01分52秒
 ************************************************************************/

#include <stdio.h>
#define MAX 100000
typedef struct toy {
    int face;
    char name[11];
} Toy;
int dir[2][2] = {
    -1, 1,
    1, -1
};   //分别存储了朝内和朝外的左右方向
int main() {
    Toy toys[MAX + 5];
    int n, m, a, s;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%s", &toys[i].face, toys[i].name);
    }
    int loc = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &s);
        loc = (loc + dir[toys[loc].face][a]*s + n) % n;
    }
    printf("%s", toys[loc].name);
    return 0;
}

