/*************************************************************************
	> File Name: 6.twoWay.c
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年10月13日 星期六 22时59分00秒
 ************************************************************************/

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct List {
    int length;
    Node head;
} List;

int main() {
    int n;
    List *l = (List *l)malloc(sizeof(List));
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
            
    }


    return 0;
}
