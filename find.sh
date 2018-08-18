#!/bin/bash
max=""      #保存最长的字符串
maxlen=0    #保存最长字符串的长度 
path=""     #保存最长字符串所在文件的路径
function traverse() {    
    file=$1
    if [[ -f $file ]]; then
        #echo $file is a file
        for i in `cat $file`; do          #列出文件中的所有字符串
            if [[ ${#i} -gt $maxlen ]]; then  #找到了比当前字符串长的就更新
                (( maxlen=${#i} ))
                max=$i
                path=$file
            fi
        done
    elif [[ -d $file ]]; then    #如果是目录，则递归进入目录继续查找
        for i in `ls $1`; do
            traverse $1"/"$i
        done
    fi

}
if [[ $# -ne 0 ]]; then
    if [[ -e $1 ]]; then
        traverse $1
        echo "maxlen: "$maxlen
        echo "max string: "$max
        echo "file path: "$path
    else
        echo "file not exists"
    fi
else
    echo "please input file/directory" #当未输入参数时，提示输入参数
fi

