/*************************************************************************
	> File Name: P1056-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 11时06分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std; 
int m,n,k,l,d;
int x[1005],y[1005];
int c[1005],o[1005];
int main() {
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d); 
    for(int i=1;i<=d;i++) { 
        int xi,yi,pi,qi; 
        scanf("%d%d%d%d",&xi,&yi,&pi,&qi); 
        if(xi==pi) 
            x[min(yi,qi)]++;
        else 
            y[min(xi,pi)]++; //过道与前一个坐标保持一致 
    } 
    for(int i=1;i<=k;i++){ 
        int maxn=-1;//为了求出每次的最大值，需要每次扫一遍 
        int p; 
        for(int j=1;j<m;j++){ 
                ``if(y[j]>maxn){ 
                maxn=y[j]; 
                p=j; 
            } 
        } 
        y[p]=0;//求出max之后一定要记得清零，来求下一个max 
        c[p]++;//ｃ数组可以实现过道的从小到大输出
    } 
    for(int i=1;i<=l;i++){ 
        int maxn=-1; 
        int p; 
        for(int j=1;j<n;j++){ 
            if(x[j]>maxn){ 
                maxn=x[j]; 
                p=j; 
            } 
        } 
        x[p]=0; //同上 
        o[p]++; 
    } 
    for(int i=0;i<1005;i++)// 
    { 
        if(c[i])//c[i]为０时表示不存在此过道 
            printf("%d ",i); 
    } 
    printf("\n"); 
    for(int i=0;i<1005;i++) 
    { 
        if(o[i]) 
            printf("%d ",i); 
    }
    printf("\n");
    return 0; 
}

