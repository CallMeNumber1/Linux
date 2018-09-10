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

- 队列

```c
// 初始化
#include <queue>
queue<int>que;
// 成员函数
q.empty()判空
q.pop()删除第一个元素
q.front()返回第一个元素
q.push()在末尾添加一个元素
q.size()返回队列中元素的个数
```

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

#### 离散化

用来减小数据量??

```c
// 得到每个数在数组中是第几大
bool cmp1(const int &x,const int &y)
{
    return b[x]>b[y];  //对编号进行排序
}
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);  //读入
        a[i]=i;//顺便初始化一下
    }
      sort(a+1,a+n+1,cmp1);  //排序
    //这里略过接下来的部分，a[]就是我们要用的"第几大"数组
}
// a[i]的值代表b[i]是第几大的元素
// 例如b =  5 4 2 6 3 1 则 a = 2 3 5 1 4 6
```

#### 树状数组

- 也被成为二叉索引树,查询和修改的时间复杂度都是logn,空间复杂度为O(n),通常用于高效的计算数列的前缀和,区间和.

 ```c
// 问题模型
// 有一个数组a,下标从0到n-1,现在给你w次修改，q次查询，修改的话是修改数组中某一个元素的值；查询的话是查询数组中任意一个区间的和，w + q < 500000.
lowbit()函数,求某一个数的二进制表示中最低的一位1
例如:x=6(110)  则lowbit(6)=(10)=2
int lowbit(x) {
    return x & -x; 
}
树状数组的思想
arr是原数组,c是新开的一个数组,代表后缀和.
// 二进制的视角:一个数n，假设n = 6，它的二进制为110，我们把它表示成累加的形式110 = 100 + 10，那么我们要求前6(110)项的和是不是可以这样求：4(100)个加2(10)个,即110=100+10, 而10是lowbit(110)的结果,100是lowbit(110-10)的结果,求和的时候我们总是把1~n的和拆分成这样的几段区间的和来计算,区间的起点和长度就是根据n的二进制来的.二进制怎么拆,你就怎么拆.拆分二进制用lowbit().
// 这里也可以顺理成章给出c数组的表示,c[i]表示从第i个元素向前数lowbit(i)个元素,这一段的和.
树状数组的实现
查询:查询任一区间的和,由于区间和具有可加减性,故转化为求前缀和.
修改:修改后要更新c数组,不然查询的时间复杂度变高.
更新的时候只要更新修改这个点会影响到的那些后缀和(c数组)，假设现在修改6(110)这个点，依据树状数组的性质三，它影响的直系父层就是c[6(110) + lowbit(6(110))] = c[8(1000)]，但是它肯定不是只影响直系父层，上面所有包含这一层和的层都要更新，但是我们把这个更新传递给直系父层c[8],8这个点的直系父层是c[16]，依次类推地更新就行.
注:直系父层包含子层的和
// 查询前缀和
int sum(int x, Array c, int n) {
	int ret = 0;
	for (; x > 0; ret += c[x], x -= lowbit(x));
	return ret;
}
x代表位置,val代表增加的值
// 更新后缀和
void update(int x, int val, Array c, int n) {
	for (; x <= n; c[x] += val, x += lowbit(x));
}
// 初始化c数组
for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    update(i, arr[i], c, n);
}
 ```

- 树状数组能快速求任意区间的和,设sum(k)=A[1] + ... + A[k].

  则A[i] + ... + A[j] = sum(j) - sum(i - 1)

- 优缺点:
  - 代码短小,实现简单
  - 只能用于求和,不能求最值
  - 不能动态插入
  - 数据多时,空间压力大
- 应用

```c
// 求逆序对个数
// 方案一:
假设给定的序列为 4 3 2 1，我们从左往右依次将给定的序列输入，每次输入一个数temp时，就将当前序列中大于temp的元素的个数计算出来，并累加到ans中，最后ans就是这个序列的逆序数个数
// 假设一个数组A[i],记录每一个数出现的次数,当A[n]=0时代表数字n在序列中没有出现过,非0则出现过.
以数字为下标,每来一个新的数就让他对应数字为下标的数加1.
// update(i, 1)即将A[i]的值加1(A数组初始化为0),即将数字i加入序列.
// sum(i)函数用于求序列中小于等于数字i的元素个数.
// 要求序列中比元素a大的数的个数,可以用i-sum(i),i是序列中元素的个数
    for (int i = 1; i <= n; i++) {
        int num;
        cin>>num;
        update(num, 1);
        ans += i - sum(a);
    }
// 方案二
将数列倒序做一遍树状数组,那么当前数字的前一个数的前缀和即为以该数为较大数的逆序对的个数
int update(int x, int k) {
	for (; x <= n; x += lowbit(x), c[i] += k);
}
int sum(int x) {
	int ret = 0;
	for (; x > -; x -= lowbit(x), ret += c[i]);
	return ret;
}
for (int i = n; i > 0; i--) {
	update(a[i], 1);
	ans += sum(a[i] - 1);
}
```



#### 状压DP

- 可通过二进制位运算将状态压缩(用整数表示集合)作为动态规划的状态来解决问题的办法