## 认识BASH

#### 系统的合法shell与/etc/shells功能

- /etc/shells中列出了系统中可以使用的shell
- 默认是bash

#### bash的功能

- history命令编修能力
  - `~/.bash_history`

- tab命令与文件补全功能
- alias命令别名配置功能
- 工作控制,前景背景控制
  - `jobs fg bg`
- shell scripts程序化脚本
- 通配符

#### bash shell的内建命令

- 使用type可以知道每个命令是否为bash的内建命令
  - 也可以用来作为类似which命令的用途,找命令用

#### 命令的下达

- 命令太长时,可以用`\[Enter]`来跳过回车,继续在下一行输入命令

#### shell的变量功能

- 环境变量

  - 通常以大写字符表示

  - `env/export`来查阅环境变量

  - `set`观察所有变量(含环境变量和自定义变量)

    $:本shell的PID

    ?:上个运行命令的回传值, 成功返回0, 否则非0.

  - `export`自定义变量转成环境变量

    **子程序仅继承父程序的环境变量**

- 变量的取用与配置

  - 取用`echo ${name}/$name`
  - 配置`name=chongh`
  - 配置守则:等号两边不能有空格
  - 变量中若有空格符可使用双引号`""`或者单引号`''`将变量内容括起来.
  - 双引号中的特殊字符如$等, 可以保持原本的特性, 单引号中的特殊字符则为一般字符

  ```bash
  var="lang is $LANG"
  echo $var --> lang is en_US
  var='lang is $LANG'
  echo $var --> lang is $LANG
  ```

  - 在一串命令中,借由其他命令提供的信息,可用\`\`或`$()`
  - 为一个变量扩增变量时

  ```bash
  PATH="$PATH":/home/bin
  或
  PATH=${PATH}:/home/bin
  ```

  - 若该变量需要在其他子程序运行,则需要以`export`来使变量变成环境变量

    `export PATH`

  - 取消变量:`unset`

    `unset name`

- 命令下达过程中, ``的含义

  **在``之内的命令将会被先运行, 而其运行出来的结果将作为外部的输入信息.**

- 影响显示结果的语系变量(locale)

  `locale -a`显示所有支持的语系.

- 变量键盘读取,数组与声明

```bash
# read
1.read -p "Please keyin your name" -t 30 name
2.read + 变量名
# declare/typeset
# 默认情况下,bash对变量有几个基本的定义
1. 变量类型默认为[字符串]
2. bash环境中的数值计算,默认最多能达到整数形态.
declare [-aixr] variable
-a 数组 -i 整型 -x环境变量 -r只读
# 变量默认为字符串
sum=100+300+50
echo $sum --> 100+300+150
# 整数
declare -i sum=100+300+50
echo $sum --> 450
```

- ulimit与文件系统及程序的限制关系

  bash可以限制用户的某些系统资源,包括开启的文件数量,可以使用的CPU时间,可以使用的内存总量等

- 变量内容的删除,取代与替换.

  ```bash
  # 删除字符
  # #/##代表从变量内容的最前面开始删除,%/%%从后面
  # #/%代表符合取代文字的最短的一个, ##/%%代表符合取代文字的最长的一个
  ${variable##/*:} # 删除/与:之间的所有内容
  # 只保留路径最后哪个文件名 /var/spool/mail/root
  echo ${MAIL##/*/} --> root
  # 只保留目录的名称,拿掉文件名
  echo ${MAIL%/*} --> /var/spool/mail
  
  # 变量的测试与内容替换
  ```

#### 子程序

- 我们在原本的bash底下运行另一个bash`bash`, 操作的环境借口会跑到第二个bash去, 即子程序,原本的bash就sleep,若要回到原本的bash去, 则将第二个bash结束掉`exit/logout`

- 在我目前这个 shell 的情况下，去激活另一个新的 shell ，新的那个 shell 就是子程序.
- 父程序的自定义变量无法在子程序内使用,export将变量变为环境变量后,就能够在子程序使用了.

#### 通配符与特殊符号

- *代表0到无穷个任意字符
- ?代表一个单个字符
- []代表一定有一个在括号内的字符(非任意字符) 
  - [abcd]代表一定有一个字符,可能是a,b,c,d中的任何一个
- [-]代表在编码顺序中的所有字符 
  - [0-9]
- [^] 若中括号中的第一个字符为指数符号(^), 则表示反向选择.
  - [^abc]代表一定有一个字符,只要不是a,b,c的其他字符都接受

#### Bash shelll的操作环境

- 路径与命令搜寻顺序,先alias再builtin再由$PATH找到第一个

- bahs的进站与欢迎信息:/etc/issue, /etc/motd

- bash的环境配置文件

  - login 与 non-login shell
  - login shelll 取得bash时要完整的登录流程, 需要输入用户的账户与密码
  - non-login shell 在原本的bash环境下再次下达bash命令,第二个bash(子程序)也称为non-login shell 

  ```bash
  # 一般来说,login shell只会读取这两个配置文件
  1./etc/profile 系统整体的配置
  2.~/.bash_profile或~/.bash_login或~/.profile 使用者个人配置
  # 其实bash的login shell只会读取上面三个文件中的一个,读取顺序为上面顺序.
  # 其中这个文件中会判断~/.bashrc是否存在,若存在则读入~/.bashrc的配置
  ```

  - source 读入环境配置文件的命令

  ```
  利用source或.都可以将配置文件的内容读进来目前的shell环境中
  ```

  - ~/.bashrc (non-login shell会读), 当取得non-login shell时,该bash配置文件仅会读取~/.bashrc而已
  - ~/.bash_logout当注销bash后,系统再完成什么动作后才离开.

#### 命令别名与历史命令

```bash
# 命令别名配置alias, unalias
alias lm='ls -al | more'
unalias lm
# 查看目前的命令别名
alias
```

```bash
# 列出最近的几个命令
history + num
# 运行第number个命令
!number
# 运行上一个命令
!!
# 运行最近的command开头的命令
!command
```

#### 数据流重导向

- 1标准输出 2标准错误输出

```bash
# 重导向可以实现一些运行命令的可能已知错误信息时,用下面的方式来丢掉
2> /dev/null
```

- /dev/null垃圾桶
- 命令运行的判断依据: `; && ||`

```bash
# 不考虑命令相关性的连续命令下达
cmd;cmd
# $?回传值与&&,||
cmd1 && cmd2 # 若cmd1运行完毕且正确运行, 则开始运行cmd2
cmd1 || cmd2 # 若cmd1运行完毕且正确运行,则cmd2不运行
```

#### 管道命令

- grep

```bash
grep可以解析一行文字,取得关键字,	若该行有存在关键字,就会整行列出来
```



- 参数代换:xargs, 产生某个命令的参数
- xargs可以读入stdin的数据,并以空格符或断行字符作为分辨,将stdin的数据分隔成为arguments.

```bash
xargs [-0epn] command
-e 后面接一个字符串(紧跟着,中间无空格),当xargs分析到这个字符串时,就会停止工作.
-n 后面接次数,每次command命令运行时,要使用几个参数的意思
当xargs后面没有接任何命令时,默认以echo进行输出
```

- 很多命令不支持管道命令,可以通过xargs来提供该命令引用stdin.

#### awk

`awk '{pattern + action}' {filenames}`

```bash
# 搜索含root关键字的所有行,没有action时默认输出每行的内容
awk -F: '/root/{print$7}' /etc/passwd

```

awk内置变量

- NR已读的记录数
- NF浏览记录的域的个数
-  FS域分隔符 FILENAME(awk浏览的文件名)
- $0指整条记录

printf语法与C语言中相同

awk编程

- 除了awk的内置变量, awk还可以自定义变量

- 条件 循环语句 数组