- 根据文件内容查找所在	的文件
  - `find Homework/ -name "*.c" -mtime -300 | xargs -n 1 grep --color -H "get_conf_value" `
    - -H是显示文件名
    - --color可以显示颜色
    - 对于命令的参数,--后面加详细名,-后面加简称.

####  免密登录

- ssh链接树莓派时,若不输入用户名,默认以本机的名称为用户名

  - 因此想要实现`ssh pi2`此类的命令,只需当前系统用户名为ChongH即可(同树莓派相同).

- 实现`ssh ChongH@pi2`

  - 改变`/etc/hosts`中的内容
    - 添加`192.168.1.41 pi2`即可

- 实现到多台树莓派上免密登录

  ```bash
  for i in `seq 1 10`; do
      scp -r ~/.ssh ChongH@pi$i:.;
  done;
  即让多个树莓派共用同一份authorized_keys文件(文件中放上主机和所有树莓派的公钥即可)
  即可实现互相的免密访问.
  ```

  - **`scp`中远程主机后的`:.`代表家目录的当前位置,必须加上.**



file a.out 查看文件属性

- 判断含有executable
  - `file a.out | grep "executable > /dev/null`
  - `echo $?`

grep a -I a.out

- -I是直接忽略的意思

test -x a.out

ssh pi@pi1 << EOF

pwd

使脚本在远端执行`ssh pi@pi2 < a.sh`

	或者scp a.sh pi@pi1:.
	
	ssh pi@pi1 ./a.sh
	
	ssh pi@pi1 "bash a.sh > out.log"

- 在所有的树莓派上执行脚本并将输出文件拷贝到本地后

  - 通过`cat pi?.log`可以同时显示所有文件的内容 

- 查找内容出现在哪个文件,从而确定是哪个树莓派

  `grep aaaaaaaa * 2>/dev/null | cut -d "." -f 1`

  例如:出现在pi1.log 则得到结果为pi1







- `arp -a` 显示所有通信过的主机的MAC地址
  - ping一下即可建立通信



-m 自动创建家目录

change shell

passwd

usermode

考题3

	根据uid能判断用户是谁创建的
	
	管理员,系统用户,管理员新建的用户
	
	用户名 uid 家目录 shell 可以在passwd中获取
	
	tty可以用w或who
	
	上次登录时间,用last
	
	用sar计算CPU使用率 sar 1 -C 5 每秒采集1次,采集5次

考题4

	`grep -n "while" a.c`

 	查看a.c中的while出现在第几行



所有管道后面可以写的,都可以在命令后面加个文件(作为标准输入)





`ls -A`输出除了.和..外的所有文件(包含隐藏文件)

chattr +a 文件只能追加,不能删除,不能修改

chattr +i 无法修改,也无法追加

OLDIFS=$IFS

- 默认以空格\tab\回车为分隔符
- 会造成当文件名含有空格时用ls -A命令不能正确显示



- `<tab>`

  `echo -e "a\tb"` -t即tab键

  -e即打开转义