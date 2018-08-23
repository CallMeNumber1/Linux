/*************************************************************************
	> File Name: P1219-1.cpp
	> Author: chongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年08月22日 星期三 10时58分27秒
 ************************************************************************/
//时间效率比我的做法高
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100],b[100],c[100],d[100];
//a数组表示的是行；
//b数组表示的是列；
//c表示的是左下到右上的对角线；
//d表示的是左上到右下的对角线；
int total;//总数:记录解的总数
int n;//输入的数，即N*N的格子，全局变量，搜索中要用
int print()
{
    if(total<=2)
    {
        for(int k=1;k<=n;k++)
        cout<<a[k]<<" ";
        cout<<endl;
    }
    total++;
}
void queen(int i)//搜索与回溯主体
{
    if(i>n)
    {
        print();
        return;
    }
    else
    {
        for(int j=1;j<=n;j++)//尝试可能的位置
        {
            //与(i, j)元素同一左对角线上的元素都有i+j相等
            //同一右对角线上的元素都有i-j+n相等
            if((!b[j])&&(!c[i+j])&&(!d[i-j+n]))//如果没有皇后占领，执行以下程序
            {
                a[i]=j;//标记i排是第j个
                b[j]=1;//宣布占领纵列
                c[i+j]=1;
                d[i-j+n]=1;
                //宣布占领两条对角线
                queen(i+1);//进一步搜索，下一个皇后
                b[j]=0;
                c[i+j]=0;
                d[i-j+n]=0;
                //（回到上一步）清除标记
            }
        }
    }
}
int main()
{    
    cin>>n;//输入N*N网格，n已在全局中定义
    queen(1);//第一个皇后
    cout<<total;//输出可能的总数
    return 0;
}

