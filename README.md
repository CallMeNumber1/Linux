## 简介
- 本仓库记录了在ubuntu系统上的重要文件和记录，用来描绘自己的学习轨迹。
#### Linux基础

- 包含了Linux初期学习阶段的文档
  - Linux基础及Git使用的笔记
  - Linux查看系统信息的笔记
  - Linux用户切换及环境变量的笔记
  - Linux定位的笔记

#### shell编程

shell：用户和Linux(Linux内核)的接口程序

此目录下包含：

1. `shell编程基础.md`

   介绍了shell基本语法、函数、数组、流程控制、定时任务、$的用法、字符串拼接操作

2. `shell浮点数处理.md`

   `浮点数处理`、`数字比较`的相关总结

3. `bash.md`

   bash shell相关笔记

4. `shell_scripts/`：用来存放一系列shell脚本

- shell初期学习阶段的脚本
  - `delete.sh`: 实现自己的,安全的rm（笔记见`作业二delete.md`）
  - `find.sh`: 当前目录下所有普通文件内容中最长的字符串并输出路径及长度（笔记见`作业一find.md`）
  - `find_num.sh`: 计算当前目录下所有文件及子目录的个数
- shell学习过程中的随堂作业
  - `ping.sh`:输出本地局域网内部所有被占用的IP地址
  - `sayhi.sh`:
- `find_three_max/`：在所有树莓派中寻找长度前三的字符串，过滤了图像、视频等格式的文件
- 查看系统信息的脚本文件,放在子目录`sysInfo/`下
  - 包括查看cpu信息、磁盘信息、内存信息、进程信息已经系统信息的shell脚本

5. `project_auto_backup`：包含了Linux下的[自动备份项目]()

#### LinuxC网络编程

1. `Socket编程.md`：socket概念、基本函数、网络IO操作、客户端与服务器端传文件相关笔记
2. `计算机网络.md`：计算机网络基础概念
3. `my_ls/`：用C实现自己的`ls`命令
4. `分布式服务器监控系统/`：网络编程项目，详细内容见仓库[Homework](https://github.com/CallMeNumber1/Homework)

#### R&Python入门

- R语言和Python基础语法的笔记

#### 文档

- ubuntu系统中家目录下文档的备份

