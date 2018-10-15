#### 切换用户

- su - user 切换用户后，同时切换到新用户的工作环境中
- su user 切换用户后，不改变用户的工作目录，及其他环境变量目录。
- sudo -i 切换为root

#### 添加用户

- `useradd -m userA`自动创建家目录

#### 环境变量

- ~/.bashrc 存储专属个人bash shell的信息，当登录时以及打开每一个新的shell时，执行这个文件。
- /etc/bashrc(Ubuntu为bash.bashrc) 为每一个运行bah shell的用户执行此文件。
- ~/.bash_profile 每个用户都可以使用该文件输入专用于自己使用的shell信息，当用户登录时，该文件仅仅执行一次。
- /etc/profile对所有用户都生效。
- ~/.bash_logout 每次退出系统（退出bash shell）时，执行该文件

另外：/etc/profile中设定的变量（全局）可以作用于任何用户，而~/.bashrc等中设定的变量（局部）只能继承/etc/profile中的变量，他们是父子关系。

- login在登入时，会读取的配置文件：
  - /etc/profile 全局配置
  - ~/.bash_profile ~/.bash_login ~/.profile 其中一个（不同shell命名不同）

bashrc往往用来初始化操作。

- `man bash`用来查看这些文件的具体名称和用途。
- `source　bash.bashrc   .等价于source`可以让对bashrc的修改立即生效。

#### 命令替换

shell可以先执行命令，将输出结果暂时保存，在适当的地方输出。

- `command``

### whoami

显示用户名称

#### 重定向

- ` >>`代表在文件末尾追加
- `cat >> file << EOF`代表从标准输入中读取，遇到EOF结束，写入file中

#### 判断字符串

- 判断空：`$ix == x`
- 判断相等：`$i == x`

#### 配置vim 

- 用户自己的vim配置文件在家目录下的`.vimrc`里面。
- 可以在`.vimrc`里面写`command WQ wq`给命令写别名。

#### vim基本使用

- 控制缩进

  `n + >>`

  `v选中 >`

#### 项目

`cut -d ":" -f` 1字符串分割，要知道有几项

`tr [:] [\n]`替换

source .back.rc

日志用`echo >>`追加即可，用４个空格分割。

日志文件记录在`var/log/my.log`

`date +%Y%m%d%H%M`

- tar打包命令

  -f 要操作的归档文件

  -c 创建归档文件

  -r 增加文件到归档文件中

  压缩 gzip bzip xz

  将所有.png的文件打包并压缩成一个名为allpic.tar.gz文件
  tar -czf allpic.tar.gz *.png

- `tail -f（强制）/var/log/mylog.log` 追踪日志文件的变化。
