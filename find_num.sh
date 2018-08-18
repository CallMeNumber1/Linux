#!/bin/bash
#传入一个目录，寻找当前目录下所有的文件个数和目录个数（包括隐藏文件）
file_num=0
dir_num=0
function find() {
    if [[ -d $1 ]]; then          
        (( dir_num++ ))
        for file in `ls -a $1`; do         
            if [[ $file = "."  ]]; then   # 特判，防止死循环
                continue
            elif [[ $file = ".."  ]]; then  # 字符串比较时，最好用""括起来
                continue                    #　防止空串
            else
                find $1"/"$file    #此种方法为保持工作目录不变
            fi                     #也可以先cd进去子目录,再cd--出来
        done
    else 
        (( file_num++ ))
    fi
}
find $1
echo "file_num="$file_num
echo "dir_num="$dir_num

#file_num=0
#dir_num=0
#for file in `ls -a $1`; do
#    echo $file
#    if [[ $file = "." ]]; then
#        continue
#    elif [[ $file = ".." ]]; then
#        continue

#    elif [[ -d $1"/"$file ]]; then
#        echo $file" is dir"
#        (( dir_num += 1 ))
#    elif [[ -f $1"/"$file ]]; then
#        echo $file" is file"
#        (( file_num += 1 ))
#    fi
#done
#echo "file_num = $file_num"
#echo "dir_num = $dir_num"
