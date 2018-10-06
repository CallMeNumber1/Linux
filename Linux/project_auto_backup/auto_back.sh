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
