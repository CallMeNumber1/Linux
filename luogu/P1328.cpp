/*************************************************************************
	> File Name: P1328.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 11时18分12秒
 ************************************************************************/

#include <stdio.h>
#define MAX 200
int main() {
    int n, a, b, scorea = 0, scoreb = 0;
    int seqa[MAX + 5] = {0}; //出拳的顺序
    int seqb[MAX + 5] = {0};
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", &seqa[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &seqb[i]);
    }
    for (int i = 0; i < n; i++) {
        if (seqa[i % a] == 0) {
            if (seqb[i % b] == 1 || seqb[i % b] == 4) {
                scoreb++;
            } else if (seqb[i % b] == 0) {
                continue;
            } else {
                scorea++;
            } 
        } else if (seqa[i % a] == 1) {
            if (seqb[i % b] == 2 || seqb[i % b] == 4) {
                scoreb++;
            } else if (seqb[i % b] == 1) {
                continue;
            } else {
                scorea++;
            }
        } else if (seqa[i % a] == 2) {
            if (seqb[i % b] == 0 || seqb[i % b] == 3) {
                scoreb++;
            } else if (seqb[i % b] == 2) {
                continue;
            } else {
                scorea++;
            }

        } else if (seqa[i % a] == 3) {
             if (seqb[i % b] == 0 || seqb[i % b] == 1) {
                scoreb++;
            } else if (seqb[i % b] == 3) {
                continue;
            } else {
                scorea++;
            }
            
        } else {
              if (seqb[i % b] == 2 || seqb[i % b] == 3) {
                scoreb++;
            } else if (seqb[i % b] == 4) {
                continue;
            } else {
                scorea++;
            }
        }
    }
    printf("%d %d\n", scorea, scoreb);
    return 0;
}

