#!/bin/bash
flag=0 #标记传递的命令参数
sum=0 #参数个数
if [ ! -d ~/.trash ]; then
    mkdir ~/.trash
fi
if [ "$1" = "-f" ] || [ "$2" = "-f" ]; then
    flag=1
    ((sum++))
fi
if [ "$1" = "-r" ] || [ "$2" = "-r" ]; then
    flag=2
    ((sum++))
fi
if [ $sum -eq 2 ]; then
    flag=3
fi
#echo $flag
if [ $# == 0 ]; then       #当未传入参数时
    echo "Usage: delete file1 [file2 file3...]"
else
    if [ $flag -eq 1 ]; then
        for file in "$@"; do
            if [ $file = "-f" ]; then   #-f时忽略警告信息
                continue
            fi
            if [ ! -e "$file" ] || [ -d "$file" ]; then
               # echo "$file"
                continue
            fi
            if [ -f "$file" ]; then
                mv -b "$file" ~/.trash/
            fi
        done
    elif [ $flag -eq 0 ]; then
        for file in "$@"; do
            if [ ! -e "$file" ]; then
                echo "$file not exits"
            elif [ -f "$file" ]; then
                mv -b "$file" ~/.trash/
            elif [ -d "$file" ]; then
                echo "can not remove a directory"
            fi
        done
    elif [ $flag -eq 2 ]; then
        for file in "$@"; do
            if [ $file = "-r" ]; then
                continue
            elif [ ! -e "$file" ]; then
                echo "$file not exits"
            elif [ -f "$file" ] || [ -d "$file" ]; then
                mv -b "$file" ~/.trash/
            fi
        done
    elif [ $flag -eq 3 ]; then
        for file in "$@"; do
            if [ $file = "-r" ] || [ $file = "-f" ]; then
                continue
            elif [ ! -e "$file" ]; then
                continue
            elif [ -f "$file" ] || [ -d "$file" ]; then
                mv -b "$file" ~/.trash/
            fi
        done
    fi
   # echo "You are about to delete these files:"
   # echo $@
fi

