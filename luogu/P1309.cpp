/*************************************************************************
	> File Name: P1309.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月18日 星期六 18时27分17秒
 ************************************************************************/
//本题目用快速排序会超时，快速排序在数据随机排布时表现良好
//本题目中相邻的分数，有些是不会改变位置的。
//每轮比赛结束后，胜利者和失败者两个集合的内部顺序是不会被打乱的
//因此使用归并排序，每一轮比赛后用O(N)的时间归并一次，时间就够了
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 200000
typedef struct player {
    int number; //选手编号
    int score;  //当前分数
    int power;  //实力值
} Player;
int n, r, q;
Player persons[MAX + 5];
Player win[100001];
Player lose[100001];

bool cmp(Player p1, Player p2) {
    if (p1.score > p2.score) {
        return true;
    } else {
        if (p1.score == p2.score) {
            if (p1.number < p2.number) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
void Merge() {
    //分别用来在win lose persons 中移动的指针
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (win[i].score > lose[j].score || (win[i].score == lose[j].score && win[i].number < lose[j].number)) {
            persons[k++] = win[i++];
        } else {
            persons[k++] = lose[j++];
        }
    }
    //两数组大小可能不同，将剩余元素放入persons里
    while (i < n) {
        persons[k++] = win[i++];
    }
    while (j < n) {
        persons[k++] = lose[j++];
    }
}

int main() {
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &persons[i].score);
        persons[i].number = i;  //输出时编号记得加1
    }
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &persons[i].power);
    }
    sort(persons, persons + 2 * n, cmp);
    for (int i = 0; i < r; i++) {
        int t = 0;
        for (int j = 0; j < 2 * n; j += 2) {
            if (persons[j].power > persons[j + 1].power) {
                persons[j].score++;
                win[t] = persons[j];
                lose[t] = persons[j + 1];

            } else {
                persons[j + 1].score++;
                win[t] = persons[j + 1];
                lose[t] = persons[j];
            }
            t++;
        }
        Merge();
    }
    printf("%d\n", persons[q - 1].number + 1);
    //for (int i = 0; i < 2 * n; i++) {
      //  printf("score = %d number = %d\n", persons[i].score, persons[i].number + 1);
   // }
    return 0;
}


