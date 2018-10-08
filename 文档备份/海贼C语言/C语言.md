#### 编程范式

面向结构,面向对象,函数式

#### 函数

函数是一种映射关系

- 数组是展开的函数,函数是压缩的数组.
- 函数是计算式结构,数组是记录式结构,因此算法优化时可考虑将记录式结构转化为计算式结构,可大大节省存储空间

#### scanf函数

- 返回值:成功读入的参数个数

#### fprintf(文件)

`fprintf(filename, "%d", n)`

- fprintf()函数根据指定的format(格式)发送信息(参数)到由stream(流)指定的文件.因此fprintf()可以使得信息输出到指定的文件.
- 返回值同pirntf一样,是输出的字符数.

#### sprintf(字符串)

sprintf(str, "%d", n)

存疑问

#### scanf

- 输入带空格的字符串`%[^\n]s`, 除了回车外都输入

- 格式化字符串 详见维基百科

### 第二章

#### 数学运算

- %4 = &3 %8 = &7 %6不能转化为位运算

```c
math.h
log(n) 以e为底
求以2为底的时用换底公式:log(n)/log(2)
acos(n) 求出的是弧度制
	acos(-1)是精确的PI
	x * acos(-1)/180 将角度制转化为弧度制
stdlib.h
abs(n)
```

#### 实现sqrt函数

```c
二分

牛顿迭代

在求函数零点这个问题上,牛顿迭代比二分查找要块
```

g++ -pg可以统计代码中每段函数的执行时间

## 第三章 流程控制

#### 关系运算符

- !!: 归一化 `int x = 123; int y = !!(x)`

- 表达式都有返回值
  - 条件表达式返回值只有0和1
  - 普通的表达式如`a=5`返回值为`5`
- switch case
  - 其中不允许定义变量.

```c
#define likely(x) _builtin_expect(!!(x), 1)
#define unlikely(x) _builtin_expect(!!(x), 0)
// likely 代表x经常成立
// unlikely 代表x不经常成立
cpu在执行分支条件时,会随机选择一个去执行,如果不对,再随机找到另一个分支
因此根据实际写上上面的会提高执行效率.
```

- 快速读入

```c

```

## 函数

- K&R风格函数

```c

```



- 递归程序设计
  - 明确递归函数的语义信息
  - 设置边界条件
  - 实现递归过程和处理过程
  - 设置结果返回

- 函数指针
  - 可执行程序运行时全部装入内存,只要在内存中的数据,就有地址.
  - 函数过程的执行逻辑以二进制数据的形式也放在内存中
- 变参函数
  - 参数列表中:(...)代表任意数量,任意类型

```c
获得a往后的参数列表va_list
定位a后面第一个参数的位置va_start
// num为变参列表的前一位
var_start(arg, num)
获取一个可变参数列表中的参数va_arg
// 第二个参数为要取的参数类型
var_arg(arg, int)
结束va_end
va_end(arg)
```

注:va_arg()仍然不能实现,因为它不是函数!

- `gcc -c function.c` 生成对象文件
- `gcc a.o b.o` 进行链接,将对象文件链接为可执行文件.

#### 负数的表示

- 负数是对应正数的补码(按位取反再+1)

## 数组

:date::9.25

- 数组是展开的函数(如素数筛)

#### 大端小端

- 小端系统
  - 存储时从低地址向高地址存,读取时从高地址往低地址读
  - 低位存在低地址位

- 数据类型只是程序看待内存的一种方式

***

#### 预处理命令-宏定义

- 定义符号常量
- 定义傻瓜表达式
- 定义代码段

```c

```

- 预处理命令 预定义的宏

```c
__DATE__ 程序的编译时间,可作为此程序的指纹
__TIME__
__LINE__ 行号
__FILE__
```

- 预处理命令 条件编译

```c
#ifdef DEBUG
#ifndef DEBUG
```

g++ -E a.cpp > output.cpp 预处理后的文件,编译源码.

- 宏定义中#与##的区别
  - #变成字符串
  - ##连接

![宏定义与函数区别](/home/chongh/下载/宏定义与函数区别.png)

## 作业

#### 实现MAX函数

```c
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
// 当表达式中带有副作用,则比较大小时会计算一次,在后面计算值时也会计算一次
例如:MAX(a++, b)
// 同时,这个宏定义没有考虑传入不同类型的参数情况
    
```



## 复杂类型与指针

#### 结构体

:date: 10.04

- 内存对齐方式:存放结构体中的类型时,默认4字节一个存储单元,内存单元是不可分的,如果排列不开则新申请一个单元
- 因此合理安排结构体中变量的位置,可以节省存储空间.
- 可以用#pragma pack(1)改变程序的对齐方式,改变默认存储单元的大小.

```c
struct node1 {
    char a;
    char b;
    int c;
} 占2个单元,8个字节
struct node2 {
	char a;
	int c;
	char b;
} 占3个单元,12个字节
```

- 除了对齐方式外,结构体在存储占据不同字节的类型时,能存储的字节位置也不同

```c
struct test {
    char b;
    short a;
    int c;
    double d;
}
则b在0号地址,a在2号地址
short为2个字节,只能占据0, 2, 4.....之类的字节位置
```



#### 共用体

- 以不同的方式看待同一个字节的内容

```c
// 应用,将ip地址转化为一个数
#include <stdio.h>
union IP {
    struct { 					//匿名结构体类型,因为之后不再需要
        unsigned char arr[4];   //无符号的字符型能存的最大数字为255
    };
    unsigned int num;
};

int main() {
    int a, b, c, d;
    IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.arr[0] = a;
        ip.arr[1] = b;
        ip.arr[2] = c;
        ip.arr[3] = d;
        printf("%d\n", ip.num);
    }

    return 0;
 }
```

- 内存中存储的信息是相同的,不同类型代表着解析信息的方式不同而已.

```c

```

- 共用体结合结构体可以实现一个数组中存储不同类型

#### 指针

- 指针变量也是变量
- 指针变量占8个字节的存储空间
- 指针变量本身占用的存储空间与指针类型无关
- 指针变量的类型用来告知系统用几个字节作为基本操作单元
  - 如p+1,跳几个字节是由指针类型定的

``` c
//等价形式转换
*p <-> a
p+1 <-> &p[1]
p->filed <-> (*p).filed <-> a.filed
```

- 函数指针

```c
int (*add)(int, int) 			//变量
typedef int (*add)(int, int) 	//类型
//注意,函数指针的语法较为特殊
```

- main函数参数

```c
int main()
int main(int argc, char *argv[])
int main(int argc, char *argv[], char**env)
argv[1]里面存第一个参数
```



传入参数与传出参数,对于传出参数,一般是个地址,在函数里面将值写到这个地址里面,从而改变参数的.

## 简易测试框架

#### 编写测试框架(测试人员)

- `TEST(test, function)`是一个测试用例
- `EXPECT()`是测试用例中的一个测试点
  - 比较两个值,函数实际返回值和期望值		

- `RUN_ALL_TEST()`运行所有测试用例

```c
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}
```

- 多重定义错误,在两个.o文件链接过程中出错
  - 因此.h文件里只能放声明,定义放在.c里.
  - 凡是发生链接错误,都要make clean再重新编译.
  - static类型变量只在原文件中可以访问,而跨源文件不能访问.
- 解决多重定义问题
  - 在.h文件里仅仅存放声明,定义都放在.c文件.
  - extern 可以将全局变量的声明和定义分开.
- 提供自己写好的测试框架

```makefile
提供一个工程目录的zip文件供使用者下载.
例如本框架的使用方式:
testcase即为测试框架的目录
其中包含include(存放test.h),src(存放test.c),output三个子目录和一份makefile文件
运行make和make install,根据.c和.h文件生成对应的动态/静态链接库.
其中输出的内容存放在output/include和output/libs

开发人员在自己的项目目录下新建thirdpart目录,用来存放所有外部文件
将output目录下所有文件拷贝到thirdpart下
然后改变makefile,在链接产生a.out的文件后面加上thirdpart/libs/libtest.a

之后,即可编写测试用例,testcase.h,愉快的使用测试框架.
```

附录:运用测试框架时使用链接库而非.c和.h文件的好处

	当测试框架中的.c文件特别多时,将带来很大方便

#### 使用测试框架(开发人员)

测试框架不应该对原工程代码产生污染(想用就用)

- .so动态链接库  编译: -shared
- .a静态链接库 编译: -static

INCLUDES用来增加查找路径

- 开发人员通过头文件和静态链接库来用测试框架
  - 静态链接库存放的就是所要使用的函数定义.
  - 而.h文件中存放的是声明,用来告诉程序有某些函数的存在.

# 作业

具备以下条件才能运行

	可执行文件名为haizeix
	
	运行的用户为你自己

#### 使用C语言获取Linux系统相关信息

```c
#include <stdlib.h>
char *getenv(const char *name) 	//可以获取环境变量各项参数
例如:getenv("USER");getenv("LOGNAME")
```

#### 字符串处理函数

- 查找某个字符在字符串中出现的位置

```c
//查找某字符在字符串中最后一次出现的位置,否则返回NULL
char *strrchr(const char *str, char c)
//查找某字符在字符串中第一次出现的位置
char *strchr(const char *str, char c)
```

- 查找子串在字符串中首次出现的位置

```c
char *strstr(char *str, char *substr)
//没有检索到则返回NULL
```

本机的PATH`/home/chongh/bin:/home/chongh/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin`



#### C语言工程开发

`gcc -c只编译不链接,产生目标文件.o`

- makefile 

  - 当写的工程文件特别多时要用makefile
  - make命令自动寻找当前目录下的makefile文件去执行
  - make clean,没有任何依赖性,删除.o和.out文件
    - 开头要写上.PHONY: clean 使得clean变为虚拟(防止存在clean文件时报错)

- 写法示范

  `目标文件 : 所依赖的文件`

  `tab+编译命令`

```makefile
CC = gcc
CFLAGS = -std=c11 -Wall -g
.PHONY: clean

a.out : main.o is_prime.o add.o test.o
	$(CC) $(CFLAGS) main.o is_prime.o add.o test.o

main.o : main.c
	$(CC) -c $(CFLAGS) main.c

is_prime.o : is_prime.c is_prime.h
	$(CC) -c $(CFLAGS) is_prime.c

add.o : add.c add.h
	$(CC) -c $(CFLAGS) add.c

test.o : test.c test.h
	$(CC) -c $(CFLAGS) test.c
clean : 
	rm -rf *.o a.out
```



## 可以作为项目的东西

- print()占位符的自己实现,已经实现了%d,自己实现%f等
- 简易测试的框架扩展