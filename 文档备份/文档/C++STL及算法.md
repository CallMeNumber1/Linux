## STL set

```cpp
set<int> s;
// 插入
insert(x);
// 查询
if(s.find(x) != s.end())
// 删除
s.erase(x)
```

C++11里将hash_set改成了unordered_set，还有unordered_map

因此leetcode中用不了hash_set，可以用后面的



#### set和map都是基于红黑树的

因此set不会有重复元素

因此set也可以实现稳定排序



## 实现自己的cout

船长上课演示

## 封装一个有多个哈希函数的哈希表