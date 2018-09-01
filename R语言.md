#### 脚本执行 Rscript + name.R

- 变量的数据类型
  - R语言中,变量本身没有声明任何数据类型,而是获取分配给它的R对象的数据类型.
  - 所以R成为动态类型语言, 这意味着我们可以在程序中使用同一个变量时,一次又一次改变变量的数据类型.
- 查找变量
  - ls()函数,查看工作空间中当前可用的所有变量`print (ls())`
  - 以.开头的变量被隐藏, 要显示`ls(all.name = TRUE)`
- 删除变量
  - rm(var)
  - 所有的变量可以通过rm()和ls()函数一起删除`rm(list=  ls())`



#### 数组

- 可以在两个以上维度中存储数据的R数据对象.
- 只能存储数据

#### 因子

- 数据帧的因子, 在创建具有文本数据列的任何数据框时,R语言将文本列视为分裂数据并在其上创建因子.

#### 数据帧

- 创建数据帧`data.frame`

```R
emp.data <- data.frame(
   emp_id = c (1:5), 
   emp_name = c("Rick","Dan","Michelle","Ryan","Gary"),
   salary = c(623.3,515.2,611.0,729.0,843.25), 
   
   start_date = as.Date(c("2012-01-01", "2013-09-23", "2014-11-15", "2014-05-11",
      "2015-03-27")),
   stringsAsFactors = FALSE
)
```

- 获取数据帧的结构`str()`
- 数据帧中的数据摘要`summary`

- 从数据帧中提取数据`data[ , ]`
- 扩展数据帧
  - 添加列:data$dept <- c()
  - 添加行:rbind(new.data)

#### 图表

- eog + 文件名可以打开图片
- barplot() 条形图

#### 数据接口

- csv文件,文本文件,列的值由逗号分隔.
- 分析csv文件`is.data.frame ncol nrow`
- 可以获取满足特定过滤条件的行,类似于sql where子句

```r
data <- read.csv("input.csv")
sal <- max(data$salary)
retval <- subset(data, salary == max(salary))
```

