## 软件安装

- 源 ubantu官方的copy

  `apt-get update`

  `apt-get upgrade`

  sudo !! 在上一条命令前加上管理员权限

  `apt-get install + name`

  `apt-cache search + name`：检索包含name的软件

  `dpkg -i`：输出错误信息

  `cd etc/apt/` -> ls：其中source.list是源，带.d后缀的是目录

## 简单命令

- `cd`

  `-`回到上次工作的目录

  `../`上层目录

  `$HOME`家目录

  不加选项，默认回到家目录 

- `ls`：列出所有文件

  -a：列出包括隐藏文件

  .是当前目录，..是父目录

  -l：长列表形式

  ll：是个别名（简称）

  ​	`alias` 可以查看存在的别名

- `cp`

  可以将多个文件拷贝到一个目录中

- `touch` 创建空白文件

- `mkdir` 创建目录

- `echo`输出

  也可以打印变量

  变量赋值时：HOME=/ 中间不能加空格，且赋值仅终端内有效

- `cat`强制读出文件的内容

- `pwd`打印当前目录

- `rm`一定要注意当前目录

  `-r`递归

  `-f`强制

  `/`目录树上也删除

- `mv`

- man

- tldr

  python3 pip

  `|` 管道：将前面的标准输出作为标准输入给后面

  `grep + "name"`检索文本信息name

  ​	例如：`apt-cache search pip | grep "python3"| grep pip`

  安装python3-pip：`sudo apt-get install python3-pip`

  利用pip安装tldr：`pip3 install name`

  卸载：unistall

- 进入树莓派：`ssh ChongH@192.168.1.40` 

  密码:`haizei`

## 免密登录

oepnssh-client用来实现本地登录远程，openssh-server用来实现本地被远程访问。本地自带client，需要安装server(否则访问时会出现port22: Conneciton refused)，当两者版本不一致时会报依赖错误。只需重新安装client的对应版本即可。

- 本地免密登录远程

  执行命令`ssh-keygen`生成公钥，按回车，默认存到`ssh/id_rsa.pub`中，用户根目录会出现.ssh目录，在.ssh目录下执行命令`cat id_rsa.pub`，将打印出的公钥强制复制。

  然后登录远程，进入.ssh目录，如果没有authorized_keys文件，则新建此文件并授予权限600，`chmod 600 ~/.ssh/autorized_keys`，然后此文件，将公钥复制在里面即可。

- 本地免密被远程登录

## Github

- 访问网站css不正确加载解决方案:

  `sudo vim /etc/hosts`在后面添加几行内容。

  详见https://blog.csdn.net/qq_36589706/article/details/80573008

- 添加ssh

- 安装GIt

- 配置用户名与邮箱（本地的，只需知道是谁做的）

  `git config --global user.name ""`

  user.email ""

#### 基本使用

- 克隆仓库到本地

  `git clone + "仓库名"`

- `git status`查看工作区状态（是否有未提交的）

- `git add`(将新建的文件添加到提交队列)

  `git add *`

  `git add .`

  `git reset HEAD 路径名/文件名` 撤销添加

- `git commit -m "info"`（提交修改并且添加说明信息）

  `git commit -a`可以结合add

- `git push`将更改push到github

- `git pull`将本地与远程同步

- `git log`查看版本信息

  `git reset --hard HEAD^`回退到上一个版本

  `HEAD^^`  `$HEAD^{100}$`

  `git reflog`查看所有操作的提交id

  `git reset --hard "id"`回到对应状态。（id只需写前7位，其他的git版本库会自动匹配）

- 如何写一个脚本每天做这些事情

#### 本地仓库项目push到Github远程仓库

- 首先在本地新建一个仓库，一般是要push哪个工程，就在那个工程目录下新建仓库。

  `cd 工程目录` `git init`

  初始化后，工程当前目录下会出现一个名为.git的目录，该目录会记录和存放所有Git需要的数据和资源。

- 目前新的仓库还是空的，要注意的是只有仓库所在目录或者其子目录下的文件可添加至仓库中，其他目录下的文件Git无法找到

  `git add .` `git commit -m ""`

- 在本地仓库push到远程仓库之前，要关联本地仓库和远程仓库

  `git remote add origin git@github.com:yourName/yourRepo.git`

  命令执行后，origin即为远程仓库的名字

- 将本地仓库的文件push到远程仓库

  `git push -u origin master`

  注意：第一次推送master分支（Git默认分支），最好加上-u参数。该参数会将本地的master分支和远程的master分支关联起来，之后本地仓库和远程仓库之间的推送和拉取就可以简化为 `git push` `git pull`

- 注意:当push后报错：更新被拒绝，当前分支的最新提交落后于对应的远程分支。

  则可以用`git push origin master`合并。

#### 分支操作

- `git branch 分支名`创建分支，创建时需要是最新的环境，依然停留在当前分支。

- `git checkout`

  `git checkout 分支名`切换分支

  `git checkout 文件名`放弃单个文件的修改

  `git checkout .`放弃当前目录的修改

- `git branch -d dev`删除dev分支（-D为强制删除）

- `git merge `合并分支

#### 100台机器每两台之间互相免密访问

`scp`
