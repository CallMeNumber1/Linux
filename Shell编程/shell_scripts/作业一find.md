## 作业一

#### 题目说明

找出当前文件或文件夹中所有文件内容的最长字符串，并且输出字符串大小以及文件所在路径。

#### 代码说明

```bash
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
        echo "file not exists"    #当输入参数不合法时给出错误提示
    fi
else
    echo "please input file/directory" #当未输入参数时，提示输入参数
fi

```

- max、maxlen、path分别用来记录最长字符串、长度、所在文件路径。
- traverse函数即为用来查找的函数，当判断输入的参数合法且为目录时，递归进入目录继续查找。
- 执行前先对参数合法性进行判断，若未输入参数或者输入的参数不存在则给出提示。

#### 难点记录

- 递归搜索目录及其子目录和文件
- `strings filename`将文件内容分割成一个个字符串的形式。
- `((  ))`整型值赋值的问题。

#### 执行结果

使用`./find.sh ~/shell`搜索shell目录

![1534258738696](/tmp/1534258738696.png)

#### 改进方法

- 遍历时去除特殊字符，只计算合理字符的长度

