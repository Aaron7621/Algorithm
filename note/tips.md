- 用lambda重定义sort规则
e.g. 按照pair<int, int>的第二个元素排序，从大到小排
```
sort(vec.begin(), vec.end(), 
        [](const PII &p1, const PII &p2)
        {
        return p1.second > p2.second; 
        });
```

- 重定义堆的排序规则：如果用于自定义对象，需要重载该类的<运算符
```
struct node{
   float val;
   int count;
}

bool operator<(const node& a, const node& b) {
  return a.count > b.count;
}

priority_queue<node> pq;
```