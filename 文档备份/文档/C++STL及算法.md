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