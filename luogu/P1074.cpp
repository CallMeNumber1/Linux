/*************************************************************************
	> File Name: P1074.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年09月02日 星期日 16时23分25秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
// 先从0少的行开始搜,能大量减少dfs的层数
// 因为一行中填过的数字越多,需要填的数越少
//将行号与0的个数对应
struct f{
    int rank, sum;
}cou[10];
//s用来保存未填的点,s[][0],s[][1]为坐标,s[][2]为分值,s[][3]为所在的宫
//hang用来保存当前行是否填过某个数,gong来表示当前宫是否填过某个数
int a[10][10], hang[10][10], lie[10][10], gong[10][10];
int s[100][4], num, ok, most = -1, have;
bool cmp(f a , f b) {
    return a.sum < b.sum;
}
//正在搜s[p],score为目前分数
void dfs(int p, int score) {
    if (p == num) {
        if (score > most) most = score;
        return ;
    }
    for (int i = 1; i <= 9; i++) {
        // 判断是否能填
        if(!hang[s[p][0]][i]&&!lie[s[p][1]][i]&&!gong[s[p][3]][i]) {
            // 将所在行列和宫进行标记
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=1;
            dfs(p+1,score+(s[p][2]*i)); 
            // 回溯
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=0;
                    
        }
    }
}
int which(int i, int j) {
    if (i <= 3) {
        if (j <= 3) return 1;
        else if (j <= 6) return 2;
        else return 3;
    }
    else if (i <= 6)
    {
        if (j <= 3) return 4;
        else if (j <= 6) return 5;
        else return 6;

    }
    else
    {
        if (j <= 3) return 7;
        else if (j <= 6) return 8;
        else return 9;
    }
}
int point(int i, int j) {
    if (i == 1 || j == 1|| i == 9 || j == 9) return 6;
    if(i==2||j==2||i==8||j==8)     return 7;
    if(i==3||j==3||i==7||j==7)   return 8;
    if(i==4||j==4||i==6||j==6)   return 9;
    return 10;
}

int main () {
    // 存初始化行号, 排序时不会丢失
    for (int i = 1; i <= 9; i++) cou[i].rank = i;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0) {
                hang[i][a[i][j]] = 1;
                lie[j][a[i][j]] = 1;
                gong[which(i, j)][a[i][j]] = 1;
                have += a[i][j] * point(i, j);
            } else {
                cou[i].sum++;
            }
        }
    }
    sort(cou + 1, cou + 10, cmp);
    //整理s数组
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            //先搜0少的行
            if (a[cou[i].rank][j] == 0) {
                s[num][0] = cou[i].rank;
                s[num][1] = j;
                s[num][2] = point(cou[i].rank, j);
                s[num][3] = which(cou[i].rank, j);
                num++;
            }
        }
    }
    dfs(0, have);
    printf("%d\n", most);
    
    return 0;
}

