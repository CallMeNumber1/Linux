#### 输入

`raw input`

#### 字符串

- 字符串前加r会使得字符不会被转义
  - `a = r'In\na line'`
- 字符串测试函数

```pyth
isalpha()判断是否全为字符
isdigit()判断是否全为数字
isspace()判断是否全为空格
startswith()
endswith()
replace('old', 'new')
调用方式
s.isalpha()
s.endswith('substring')
```

- 逆序索引(正序索引减去字符串长度)

#### 选择结构

- if后可以有任何类型的值, 数值0以及空字符串' '和其他空类型都代表了'假', 还有一种叫布尔类型的值.
- 对于字符串类型的情况,等号会判断两个字符串是否相等.
- 对于列表类型的情况,还有一个运算符in, 例如`'a' in list`
- and or not逻辑运算符

```python
if  1 and 2:
    do
elif 3 and 4:
    do
else:
    do
```



#### print

- `'%s %d %g' %(name, age, height)`字符串格式化
- s = s.encode('utf-8')

#### 列表

```python
列表像字符串一样,按下标访问.
len()给出了列表元素的数量
append()列表尾部添加单一元素
extend()尾部连接列表
insert(loc, 'string')向某个位置插入
remove('item')删去某个元素
pop(loc)删去第几个元素
split('char')根据某个字符将字符串分隔开

```

- 列表求和

```python
for num in array:
    sum += num
也可用内置的求和函数: sum(array)
```

- range(n)快速的生成等差数组列表.从0到n,常与for.....in...结合使用
  - range(1, n)生成从1到n的n个数字
  - range(1, 10, 2) 生成从1到10公差为2的序列
  - range(10, 1, -2) 同理

#### 排序

- 列表排序: `list.sort()` 返回值为None

- sorted(numbers) 返回值为列表

- sorted(numbers, reverse=True) 逆序

- 个性化排序:

  sorted(numbers, key = len)

#### 元组

- 固定大小的一组元素
- len(), [ ]等操作同样适用
- 空元组()
- 创建只有一个元素的元组,则第一个元素后面需要加一个括号tuple = ('hi', )
- 创建后不可以修改
- 用元组做返回值,可以返回多个值,用一个元组接收.

#### 字典

- 一系列用{}包裹的键值对的集合
- 可以作为键名的常见数据类型包括字符串, 数值, 和元组, 键值可以为任意类型
- 可以用in和键名判断某个键值对是否存在`print 'a' in bat`
- `bat.keys()`取bat这个字典的所有键名并放到一个列表里
- `bat.values()`取所有键值放到一个列表里
- `bat.items()`取所有键值对放到一个列表里

```python
#for循环打印字典
for k, v in bat.items():
	print k, '>', v
#字典数据格式化
boss['name'] = 'robin'
boss['age'] = 41
boss['height'] = 1.78
print '%(name)s %(age)d %(height)g' %boss
```

- 删除表达式`del`

  可以删除变量,列表中元素或者字典中元素

#### 文件

- open()返回一个可用于读出和写入文件的文件操作符.

  `fd = open('filename', 'r')   fd.close()`

- `fd.readline()`一次性加载完整的文件到内存,让文件的每一行作为它这个列表结构的每一个字符串元素.

- `fd.read()`一次性将完整文件作为一个字符串读入到内存内.

- `fd.write(字符串)`将指定的字符串写入到打开的文件中

  也可以`print >> 文件操作符, 字符串`

#### 正则表达式

- 由一些普通字符和一些元字符组成

```
.会匹配除了换行以外的任何字符.
\w等价于[a-zA-Z0-9_],会匹配单一字符,数字或下划线.\W匹配任何非以上的单一字符
\b匹配\w和\W之间的边界
\s等价于[\n\r\t\f],会匹配一个空白字符(空格,换行,回车,制表符,表格),\S匹配所有非空白字符
\d等价于[0-9]用于匹配十进制表示的数字
^作为开始标记
$作为结束标记
\用于一些字符的转义
```

- 模组re

  ```python
  import re
  str = 'A cute word:cat!!'
  match = re.search(r'word:\w\w\w', str)    #r代表后面的字符串不会被转义
  if match:
  	print 'found', match.group()
  ```

- 用*和+实现重复多次的形式的表述

  ```python
  import re
  print re.search(r'pi+', 'piiig').group()
  print re.search(r'pi*', 'pg').group()
  ```

- 正则里的方括号

  代表其中几个匹配项为或的关系

- 正则提取

  可以添加圆括号()用于指定几个具体的匹配的部分

  ```python
  import re
  str = 'purple alice-b@jisuanke.com monkey dishwasher'
  match = re.search('([\w.-]+)@([\w.-])', str)
  ```

  ```python
  import re
  str = 'purple alice-b@jisuanke.com monkey dishwasher'
  match = re.search('([\w.-]+)@([\w.-])', str)
  if match:
      print match.group()
      print match.group(1)
      print match.group(2)
  # group(1)提取@之前的
  ```

- findall()找到所有满足的,结果为一个列表,其中元素为元组

  ```python
  import re
  str = 'purple alice@jisuanke.com, blah monkey bob@abc.com blah dishwasher'
  tuples = re.findall(r'([\w\.-]+)@([\w\.-]+)', str)
  print tuples
  ```

- 选项与贪心匹配

  用于正则表达式的re模组中的函数有一些可选参数,可以对search()和findall()函数传入额外的参数来进行使用

  - 如`re.search(pat, str, re.IGNORECASE)`
  - IGNORECASE匹配时忽略大小写
  - DOTALL允许.去跨行匹配
  - MUTILINE对于一个多行文本组成的字符串,^和$将用于匹配每一行的开始和结束

- 贪心匹配

  .*这样的匹配是贪心的,会尽可能去匹配较长的匹配结果

  可加上?使之变为不贪心的.







- `del`删除的是变量, 而非数据.
- `a, b = 0, 0`python赋值可以多个变量一起赋值
- print循环输出时, 结尾加' , '可以在一行空格间隔输出

- `x = [1 for in range(n)]`

  生成n个1组成的列表

​	理解: i在range范围内循环, 分别计算for之前表达式的值,作为列表项.

-  `a = nums[1::2]`

  其中两个冒号代表从1取到最后,步长为2, 如果nums从1开始为下标编号,则此语句可以取出下标能被2整除的各元素

  类似`a = nums[1:]`从1取到最后

