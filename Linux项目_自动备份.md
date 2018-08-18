## Linux项目-自动备份

#### 项目要求

1. 具备配置文件
2. 每天定时打包代码目录，并详细记录日志（打包时间、操作、文件大小等信息）
3. 保留３天的备份数据

#### 配置文件

1. 包含需要备份的路径形式：path1:path2:path3......
2. 目标目录：要打包到的安全目录

#### 日志

```bash
时间	　			操作　	   对象　　　	                        在磁盘上的数据变化
2018-8-17 12:10   backup   /home/chongh/luogu   				+32M
2018-8-17 12:12   delete   home_chongh_luogu_2018_8_14.tar.gz   -123M
```



#### 代码实现:

- 核心代码`~/shell/auto_back.sh`

```bash
#!/bin/bash 
source ~/.back.rc #引入要备份的路径与目标路径
TIME=`date +"%Y_%m_%d_%H_%M_%S"`
SUF=.tar.gz     
echo "$TIME backup start!"
for path in `echo $backup_path | tr ":" "\n"`; do
    NAME=`echo $path | tr "/" "_"`$TIME$SUF
    cd $path
    tar -czf $dest_dir/$NAME *.cpp
    #cp $NAME $dest_dir     报错不存在目录？？
    cd --
    a=`du -m $dest_dir/$NAME`       #输出文件大小
    SIZE=`echo $a | cut -d " " -f 1`
    echo -e "$TIME \033[32m backup \033[0m $path +$SIZE"M"" >> $log 
done

DEL=`find $dest_dir -name "*.tar.gz" -mmin +3`
for file in $DEL; do
    a=`du -m $file`
    SIZE=`echo $a | cut -d " " -f 1`
    echo -e "$TIME \033[31m delete \033[0m $file -$SIZE"M"" >> $log 
    rm -f $file
done
```

- 配置文件`~/back.rc`

```bash
backup_path=/home/chongh/dir1/:/home/chongh/dir2/ #要备份的路径
dest_dir=/home/chongh/backup 					  #目标路径
log=/var/log/mylog.log 							　#写到标准日志文件里
```

## 技术要点

#### shell脚本获取配置文件的内容

- 在脚本里面加上`source ~/back.rc`，即可获取配置文件中的变量等，在脚本中直接使用

#### 以指定字符分割字符串`cut`

- `echo $i | cut -d " " -f 1` 用空格分割字符串i，取分割后的第一部分。
- 使用时要求知道要取字符串的第几部分。

#### 将字符串中指定字符替换为另一字符`tr`

- `echo $backup_path | tr ":" "\n"`本项目中使用，可以使备份路径字符串变成一个个独立的路径

#### 打包

- `tar -czf 包名　待打包文件`

#### 计算文件大小

- `du -m 文件名`以Ｍ为单位
- `du -k 文件名`以KB为单位

#### 输出带颜色的内容`echo -e`

- `echo -e "\033[32m 绿色文字 \033[0m 还原默认"` 

#### 设置定时任务

- `crontab -e`进入编辑页面
- `crontab -l`显示定时任务列表
- `*/1 * * * * command`代表每分钟执行一次

#### 系统标准日志文件

- `/var/log/`，可在下面创建自己的日志文件`name.log`

#### 追踪日志文件的变化

- `tail -f 日志名`

#### 在某个路径下寻找指定文件名的文件`find`

- 例如：`find $dest_dir -name "*.tar.gz" -mtime +3`在路径下寻找3天前的后缀为.tar.gz的文件
- `-name ""`后面的字符串要用双引号括上