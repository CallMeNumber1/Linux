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

## 能存储任意类型的链表

![能存储任意类型的链表](/home/chongh/图片/能存储任意类型的链表.png)



对于一个函数，要保证传入的值与函数实际需要的值一样

	比如函数要的是地址，要传入一个地址，不能是个值

一个程序实现什么功能，所存储的数据结构是必要的



## 简历

如果没有项目，学习的一个独立的模块也可以代替项目写在简历上

所有写在简历上的应该是自己擅长的

合理化吹b



> 2019-2-25 第一周 周一

## vector

```cpp
#include <vector>
vecotor<int> v1; 						// vector元素为int型
vector<int>::iterator it; 				// 定义一个迭代器
v1.push_back();							// 在数组的最后添加一个元素
v1.pop_back();
v1.front();
v1.empty();
v1.size();
v1.insert(pos, data); 					// 在pos处插入数据
v1.erase(pos);							// 删除pos位置的数据
v1.erase(begin, end);					// 删除左闭右开区间的数据
v1.begin(); v1.end(); 					// 得到数组的头/尾指针，用迭代器接受


// 初始化
vector<T> v(n, val);					// v包含n个值为val的元素
// 排序
sort(v1.begin, v1.end());				
reverse(v1.begin(), v1.end())
// 顺序访问
for (int i = 0; i < v1.size(); i++) cout << v1[i];
for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
    cout << *it << endl;
}
// 寻找
vector < int >::interator it = find(v1.begin() , v1.end(), 3)
```

## string

```cpp
// 字符串初始化
string s1 = "abcdef";
string s1("abcdef");
string s1 = s2;							// 通过拷贝构造函数
string s1(7, 's'); 						// 初始化7个s的字符串

// 字符串遍历
// 1.通过数组
for (int i = 0; i < s.length(); i++) cout << s[i] << " ";
// 2.通过迭代器
for (string::iterator it = s.begin(); it != s.end(); it++) cout << *it << " ";

// char*和string的转换
// 1.string->char*
string s1 = "abcdefg"; cout << s1.c_str() << endl;
// 2.char*->string
char buf[64] = {0};
s1.copy(buf, 7);						// 复制7个元素

// 字符串连接
string s1 = "123";
string s2 = "456";
s1 += s2;								// 方式1
s1.append(s2);							// 方式2

// 删除最后一个字符
s1.pop_back();
```

**int转string**：标准库中的`to_string(i)`方法

## 全排列函数

- `std::next_permutation()`

```cpp
// 函数原型
// 1.提供升序
template <class BidirectionalIterator>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last );
// 2.提供降序
template <class BidirectionalIterator, class Compare>
bool prev_permutation (BidirectionalIterator first,BidirectionalIterator last, Compare comp);

// 使用前要先排序！！！
int myints[] = {1, 2, 3, 1};
sort(myints, myints + 4);
do {
    // output
} while (next_permutation(myints, myints + 4));	 		// 获得下一个较大字典序列

// 对于vector<int> v
vector<int> v;
do {
    // output
} while(next_permutation(v.begin(), v.end()));
```

