#### 用户权限

- id userA查看userA所属的组等信息
  useradd
  userdel -r
  su – userA 切换到userA
  创建用户的时候自动创建同名的组，一个用户可以属于多个组

chmod o-r,o-x /project　其他用户不能进入此目录

#### 文件定位

- which查找并显示给定命令的绝对路径

  环境变量PATH中保存 了查找命令时需要遍历的目录.

- whereis寻找特定文件

  -b 

  -m

  -s

  -u

- locate 模糊定位, 查找所有部分匹配的文件

  -i忽略大小写

  -r接正则表达式

updatedb 可以更新locate所需要的索引

#### find高级查找

- atime 读取时间

- ctime 状态改变时间

- mtime  修改时间

  -n n天以内

  +n n天以前

- -newer file 把比file还要新的文件列出来

- 用用户或组相关的参数

  -uid n

  -gid n

  -user name

  -group name

  no user

  no group

- 与文件权限及名称有关

  -name filename 按文件名来查找,用""括起来

  -size [+-] SIZE

  -type TYPE : f b c d l s p

  -perm mode : 　mode刚好等于的文件

  -perm -mode

- `find ... -exec ls -l {} \;`

  -exec开头 \结尾

  {}代表查找出的内容,一条条执行

-  可以使用混合查找方式查找文件

  ! -a -o

find / -type p -mtime -1 2>/dev/null

找到一天内新建的管道文件(标准错误输出重定向到空)

find / -mtime +365 -perm 666 2>/dev/null -exec cp {} ~ \;

rm \\*

找到一年前新建的mode666的文件,并移动到家目录下,然后在家目录下删除此文件.

注意,因为此文件名为*,要用\转义,否则删除的时候会发生悲剧(rm *).

#### 数据提取

- tr 对标准输入的字符替换,压缩,删除, 文件本身内容不会改变

  `cat test.log | tr 'A-Z' 'a-z' >> test.log `

  tr 'A-Z' 'a-z'

  当执行转换操作时,必须用参数"字符集2"制定转换的目标字符集,但删除操作时, 不需要参数"字符集2"

  -d 删除所有属于第一字符集的字符

  -c 取代 字符集1的补集

  -s 把连续重复的字符以单独一个字符表示

  -t 先删除第一字符集较第二字符集多出的字符.

从字符串中提取数字:echo "2014年7月21日" | tr -cd "[0-9]"

- cut 切分

  -d 自定义分隔符,默认为制表符

  -f 与-d一起使用,指定显示哪个区域.

- grep 检索

  -c 计数

  -i 忽略大小写

  -n 顺序输出行号

  -v 反向输出(反向输出) 输出以外的

- sort 排序 根据不同的数据类型进行排序并输出

  -f 忽略大小写

  -b 忽略最前面的空格

  -M 月份 如JAN小于FEB

  -n 纯数字

  -r 反向

  -t 分隔符

  -k 以哪个区间排序

-t搭配-k可以实现按某一列排序,例如:

`sort -n -k 3 -t ':' /etc/passwd` 取passwd的第三列(uid 纯数字),排序

- wc 统计字符,字数,行数

  -l 仅列出行号

  -w 仅列出多少字

  -m 仅列出多少字符

- uniq 去重　只有相邻的行才能去重

  -i 忽略大小写字符的不同

  -c 计数

- tee 双向重导向

- 切分

- xargs 参数代换

  -n num　每次执行command需要的参数个数

  -eEOF 当xargs读到EOF时停止

- last 显示用户登录情况 

  -x 将关机信息也显示出来

- `cat /etc/passwd` 显示所有的用户和组信息

- sed 分隔符可以用任意特殊字符

  - ``

#### 数据提取练习题

1.for i in   \`echo "1 2 3 4 5 s 你好 6 7 9 a 8" | tr -c -s "0-9" " " \`; do $[sum+=$i] echo $sum done

2.`echo $PATH | awk -F ":" '{print $NF}'`

	awk中,NF表示字段数, $NF表示最后一个字段

`echo $PATH | tr ":" "\n" | tail -n 1` 也可以输出,更为简单

3.`export | cut -c 12-`

将export命令的第12个字符之后输出

4.`last -x|grep shutdown`查看关机信息

7`w -h | wc -l`查看当前登录的用户数

	`who | wc -l`who命令可以返回当前登录用户的信息

去除输出中的空行可用:

`last | tr -s '\n'`

`awk NF test.txt`

NF代表当前行的字段数, 空行的话字段数为0,被awk解释为假,因此不能输出.

也可用grep只显示行里带有特定字符集的

`last | grep "[A-Za-z0-9]" | grep -v "wtmp" | grep -v "boot" | wc -l`

8.`last | cut -d ' ' -f 1 | sort | uniq -c | sort-rn`



9.

10. `cat /etc/passwd | head -n 20 | tail -n 10 | cut -d ":" -f 1 | xargs -n 1 id`

11. `cut -d ":" -f 1 /etc/passwd | xargs -e"sync" -n 1 id`

12. `awk NF a.txt | sort | uniq -c | sort -rn`

    ``

如何判断一个命令是否支持标准输入

看一个命令是取了文件名还是文件里面的内容



- w 命令查看登录用户正在使用的进程信息,显示已经登录系统的用户的名称

  -h 忽略头文件信息

- who 查看登录用户名及所启动的进程 

  `为何与who am i 显示的一样` 

- users 打印输出登录服务器的用户名称

- whoami 查看你所使用的登录名称

- who am i 显示当前登录的用户名称,以及当前所使用的tty信息

#### 过滤掉字符串中的非数字

`tr -cd "[0-9]"`

#### AWK

- -F参数 指定分隔符 

  不指定分隔符则默认以" "空格作为分隔符

- 内置变量

  NF 列个数 $NF为最后一列

  $n 第n列

  NR 行数 已经读出的记录个数

- 输出第20到30行内容

  `awk '{if(NR>=20 && NR<=30) print $1}' test.txt   `





#### EVAL

- eval可读取一连串的参数, 然后再按照参数本身的特性来执行 注意中间要用;分号隔开!
- 例如:eval `free -m | grep "Mem" | awk '{printf("total=%d;used=%d;free=%d",$2,$3,$4)}'`



#### 查看系统信息

###### df　查看磁盘信息

- -T显示文件系统类型
- -x 不显示指定类型的文件系统
- -m 以MB的形式显示各文件系统

###### free -m 查看内存信息

###### uptime 查看CPU信息(显示了1/5/15分钟的负载)

- top可以查看当前CPU的运行情况
- /proc/cpuinfo
- /proc/stat

###### 系统信息

- `hostname`主机名
- `uname -a` 查看内核版本

#### proc文件系统

- 伪文件系统, 只存在内存中.

- proc文件系统是动态从系统内核读出所需信息并提交的

- /proc/stat文件

  包含了所有CPU活动的信息,该文件中的所有值都是从系统启动开始累计到当前时刻.

  第一行数值表示的是CPU总的使用情况.

#### sleep + 时间 暂停

#### shell 内置命令

- source cd

#### 



#### 作业

```bash



```

uptime

cpu信息可从文件中找到

uptime也可从文件中找到