/*************************************************************************
	> File Name: P1048-1.cpp
	> Author: ChongH
	> Mail: 304451676@qq.com
	> Created Time: 2018年09月05日 星期三 19时59分08秒
 ************************************************************************/
// 一维dp
// 内层循环要倒着来,不然会重复拿
#include "stdio.h"
#include "iostream"
using namespace std;
int w[105], val[105];
int dp[1005];
int main()
{
        int t,m,res=-1;    
        scanf("%d%d",&t,&m);
        for(int i=1;i<=m;i++)
    {
                scanf("%d%d",&w[i],&val[i]);
            
    }
        for(int i=1;i<=m;i++) 
    {
                for(int j=t;j>=0;j--) 
        {
                        if(j>=w[i])
            {
                                dp[j]=max(dp[j-w[i]]+val[i], dp[j]);
                            
            }
                    
        }
            
    }    
        printf("%d",dp[t]);
        return 0;

}
