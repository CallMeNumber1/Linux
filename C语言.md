#### C语言标准库

- `#include <ctype.h>`

  头文件中包含了对字符测试的函数,如检查一个字符串中某一字符是否为数字,或者字母等.

```c
isalpha() 判断是否为字母
isdigit() 判断是否为数字
isspace()
islower() 是否为小写 isupper()
tolower() toupper()
strchr() 返回要查找的字符在字符串中第一次出现的位置, 返回指向该字符的指针
```

- `#include <bits/stdc++.h>`万能库

#### C++ STL

- 优先队列 `#include<queue> using namespace std`

```c
// 声明的基本格式
priority_queue<结构类型> 队列名;
// 最常用的情况
priority_queue<node> q;
// node是一个结构体,结构体里重载了<符号
priority_queue <int, vector<int>, greater<int> > q;
//不需要#include<vector>头文件
//注意后面两个“>”不要写在一起，“>>”是右移运算符
priority_queue<int, vector<int>, less<int> > q;
```

- 优先队列的基本操作

```c
q.size() q.empty()
q.pop() q.push(k)
q.top() q.back()
```

- 优先队列的特性:**自动排序**

  入队后元素自动排序, 队列中最大的元素总是位于队首．

- 自定义优先级：

```c
struct cmp{
    operator bool ()(int x, int y) {
    	return x > y;   // ｘ小的优先级高  
    }
}
priority_queue<int, vector<int>, cmp> q;
```

- 结构体声明方式:

```c
struct node {
    int x, y;
    friend bool operator < (node a, node b) {
        return a.x > b.x;  //ｘ小的优先级高
    }
}
priority_queue<node>q;
```

#### 搜索

```c
//dfs模板
void dfs(答案,搜索层数,其他参数){
    if(层数==maxdeep){
        更新答案;
        return; 
    }
    (剪枝) 
    for(枚举下一层可能的状态){
        更新全局变量表示状态的变量;
        dfs(答案+新状态增加的价值,层数+1,其他参数);
        还原全局变量表示状态的变量;
    }
}
```

#### 矩阵快速幂

- 让计算机很快的求出a的b次幂,暴力相乘的话,电脑计算b次
- 快速幂计算次数在log级别 

```c
//ans为答案,base为a^(2^n)
int quickPower(int a, int b) {
    int ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans *= base;  //若当前b的最后一位为1
        base *= base;           
        b >>= 1;
    }
    return ans;
}
```

#### 取余运算

取余运算有一些好用的性质，包括：

(A + B) mod b = (A mod b + B mod b) mod b

(A * B) mod b = (A mod b * B mod b) mod b

于是在快速幂过程就可以: 

```c
while(b > 0) {
        if(b & 1)
        {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b >>= 1;
}
// 能保证最终结果与"先乘到最后再取余"的结果一样
```



#### 状压DP

- 可通过二进制位运算将状态压缩(用整数表示集合)作为动态规划的状态来解决问题的办法