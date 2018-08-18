#### SHELL编程

#!/bin/bash 用bash语法写的

- 执行脚本 bash + filename

  chmod(change mode改变权限) a+x  +filename

  执行时直接./filename.sh

  权限顺序：用户->用户组->其他人

- 变量与局部变量

  **赋值号两边不许有空格**

  弱类型语言

  ``命令替换符

  ​	`pwd` 代替命令的输出

  `a = $a:a`字符串拼接，$后面跟变量名

- 位置变量

  $0：当前执行shell脚本的文件名，包括路径

  $n：获取当前执行脚本的第n个参数

  $*：输出一个整体字符串

  $# 当前执行脚本的参数个数	

  $@ 获取这个程序的所有参数，并保留参数之间的任何空白，输出各个独立部分，与*相对应

- 状态变量

  $?：判断上一个指令是否成功执行，0为成功。

- 变量，参数展开

  ${a}：{}可以限定变量的作用范围。

  ${!prefix*}：匹配prefix开头的所有变量

  Linux下两个垃圾桶：/dev/zero /dev/null

- 输入输出

  `read  [ -options ][variable]`

  `echo string`

  ​	-e 开启转义

  ​	-n 不输出回车

  `printf format-string [arguments]`

- 函数

  三种定义方式：

  ```shell
  function _printf_() {
      echo $1
      return
  }
  _printf_() {
  	echo $1
  	return
  }
  ```

- 流程控制

  condition两端必须有空格

  ```shell
  #if
  if [[ condition ]]; then
  
  fi
  #表达式两端要有空格
  ##如果是数值类型的数据，使用let(())进行判断，对于字符串等使用test[[]]进行判断。(())中变量可以不用$来引用。
  
  #case 
  case word in
  	pattern )
  		;;
  esac
  
  #while
  while [[ condition ]]; in
  	
  	
  #until
  
  #for
  for i in 'seq 1 100'; do  #生成1～100的数字序列
  	#staements
  done
  
  for (( i = 0; i < 10; i++)); do
  	#statements
  done
  ```

  

- 数组

  数组的声明：`declare -a array`

  输出数组内容：`${array[*]} ${array[@]}`

  取数组长度：`${#array[*]}`

  数组的访问：`${array[ind]}`	

  数组追加：`array+=(1 2 3)`

  删除数组元素：`unset`

  数组排序：`sort`

  ```shell
  #生成1到100的一个数组
  a=('seq 1 100')
  #当不加括号时，生成的是一个从1到100连起来的字符串
  a='seq 1 100'
  ```

- 运算符

  ```shell
  #算术表达式赋值
  可以写在(())中，且不用加 $ 符号
  也可以：a=1 b=$[$a+1] 写在中括号里
  #整数比较运算符（浮点型数值不能使用）
  -eq -gt -lt -ge -le -ne
  #字符串运算符
  = != -n（判断是否不为空） -z（是否为空）
  #逻辑运算符
  ! -a -o 
  #算术运算符（可以与=连用，称为算术复合运算符）
  #使用let命令来执行算术运算，使用算术运算符无法对字符串、文件、浮点型进行计算（浮点型操作，需要用到专门的函数）
  let "a=5+{++num}"
  #自增运算符
  #数字常量
  #bc运算器，使用其进行浮点数运算需要使用命令替换的方式。
  #bc运算器定义了内建变量scale用于设定除法运算的精度（默认为0）
  var1=20
  var2=3.14159
  var3=`echo "scale=5; $var1^2 | bc"`
  var4=`echo "scale=5; $var3*$var2" | bc`
  
  ```

- Linux中挂起(ctrl+z)，然后输入fg即可回去，若挂起多个，可以用jobs查看，并用fg+数字回去

- 获取单个文件大小`ls -l filename | awk '{print $5}' `

- 显示当前目录下的文件（夹）`ls dirname`

- `mkdir -p` 可以是一个路径名称。此时若路径中的某些目录尚不存在,加上此选项后,系统将自动建立好那些尚不存在的目录,即一次可以建立多个目录

- rm

  -r 递归删除目录及其子目录

  -f 当文件为空时不输出错误信息

  -rf 

#### 定时任务

- find命令`find pathname -options [-exec]`

  pathname 是find命令所查找的目录路径

  -exec 对匹配的文件执行该参数所给出的shell命令

  -options 选项参数

  ​	-name 按照文件名查找文件

  ​	-mtime -n +n 按照文件的更改时间来查找文件，+n表示n天前

  ​	-type 查找某一类型的文件

  找两种类型的文件 -type 

- crontab

  格式：分钟 小时 日 月 星期 命令

  参数:
  -e [UserName]: 执行文字编辑器来设定时程表，内定的文字编辑器是 VI，如果你想用别的文字编辑器，则请先设定 VISUAL 环境变数来指定使用那个文字编辑器(比如说 setenv VISUAL joe)
  -r [UserName]: 删除目前的时程表
  -l [UserName]: 列出目前的时程表
  -v [UserName]:列出用户cron作业的状态	

#### 作业一

- 查找一个目录下所有文件中最长的字符串

  ~/task.sh

#### 作业二

- 垃圾箱

## `which` 
- `type`



文件类型
7种类型

## 普通文件又可以分为三种：
	纯文本文件
	二进制文件(不能用cat读取）
	数据文件(只能用特定软件读出）
## 文件权限rwx
权限包括三组：用户 用户组 其他用户
与文件权限有关的命令
chmod
chmod a+x file
chmod o-x file
chmod 755 file
chown修改文件所属的用户
chown suyelu:haizei file
chown -R wuyelu:haizei directory
chown suyelu file
chgrp修改文件所属的组
chgrp root file
- sudo 临时获取管理员权限
- su 切换用户
- sudo -i切换到root

## shell terminal console

#### man
-f
-k 

## bash
- 通配符 ？单个字符 ×任意多个字符
[list]匹配list其中一个字符
[!list]匹配除list外的所有字符
[0-9][a-z]
{string1},string}匹配字符串
### 任务管理
- command & 后台执行
- command;command 顺序执行
- command && command 第一个成功执行第二个才执行
- command || command
- ``命令中包含另一个命令时，用符号包括起来
- 结束进程
	可用pkill ping根据进程名字杀死进程
	或者用kill + pid
### 管道 重定向
- >> 追加
- << ?
### 转义符

### shell元字符
- =
- ``取命令的执行结果
- $变量值替换 $[]整数计算
- | 管道命令 先进先出，出去就消失了
- !+序号可以执行history里面的指令
- ctl + r 可以检索历史命令
- .当前目录
- -上次工作目录
- -根目录

### 目录结构
- /mnt来挂载优盘

### 配置文件
- /etc/fstab 查看文件系统
- 用户系统
	/etc/passwd
	/etc/group
- shell
	/etc/profile 用户首选项
	/etc/bashrc bash配置文件
- 系统环境（所有用户通用）
	/etc/issue 发行信息
- 网络 （所有用户通用）
	/etc/hostname 主机名
	/etc/hosts 主机列表
- 环境变量
	env
- 常见环境变量（可通过man手册查看）
~/.bashrc
~/.bash_profile
~.bash_logout
bash.bashsrc

#### date 查看当前时间
date +"%..." 以什么格式输出
