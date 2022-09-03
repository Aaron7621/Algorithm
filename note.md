## 快速排序

**坑**：选分界点的时候要直接取到具体的那个是x，而不是取那个数的下标mid。因为数组的元素一直在变化，并非从头到尾q[mid]都等于x

**坑**：在快排分类的一步中，为了不开辟新的数组空间，用优美的分类方法，同时确保递归下去的两个子数组一定是一边所有数小于等于x，另一边大于等于x，i和j的边界非常敏感和重要。

- 为什么使用do while而不使用while：表面上看两者的语义完全一样，但是在于最后可能会i少加一次，或j少减一次，导致分到的左子数组不正确，例如：

![image-20220730170929783](C:\Users\Aaron\AppData\Roaming\Typora\typora-user-images\image-20220730170929783.png)

第一遍分类后，i、j都指向了3，而使用whil，使左子数组的范围是(l, j)，所以错误地把1 1 3都放去了左边，导致出错

- 解决：没有必要再去认真推边界问题的产生原因，直接记号模板就好

## 第k个数

**坑**：当完成了左右分好之后，并不是说j=k-1就可以直接输出q[j]了，因为目前只是说明左边所有数都小于等于x，并不能说明j[k-1]就是左边最大的一个数



## 逆序对数量

用归并排序做。

逆序对统计的过程刚好就是归并排序进行归并时，右数组元素小于左数组元素的时候。



**坑**：int不够大就用long或者unsigned long, long long。printf long long类型要"%lld"



## 二分查找

二分查找不需要递归。排序才要。

- 为什么：二分查找原问题一直缩小，直到最后问题小到能直接得出解。排序原问题的解决需要依仗子问题的解决，原问题包含了所有子问题。即：二分查找需要处理的元素越来越少；而排序等需要用递归解决的问题虽然采用了分治的思想，但问题最终仍然需要关注和处理所有的元素



## 数的三次方跟

用二分查找

scanf double要"%lf"，不然gg



## 差分

vector和数组定义好了之后元素自动初始化为0

**但是int就不是了**，要手动初始化为0



## 差分矩阵

acwing oj的问题：调试的时候segmentation fault不一定是真的有问题。提交之后可能就ac了



## 数组元素的目标和

双指针的体会：所有双指针问题都可以用暴力解决，双指针就是暴力遍历的优化。

思考需不需要用双指针的原则就是：在暴力的过程中，两个指针的更新**是否有一些操作是因为之前已经进行过的判断，而变得没有必要的**。

比如这题，i从A的小端开始遍历，j从B的大端开始遍历，当A[i] + B[j]已经大于目标数的时候，A[i+1]就必然没必要再和B[j]一起进行判断



## 判断自序列

不是KMP的那个判断子序列，是判断小的序列是否在大的序列中也是按顺序排的



## 区间和

前几次一直segmentation fault。原因是误把c也塞进vector里面了。对于最后的结果是没有影响的，但是可能会使vector的长度大了1/3，因此排序和unique等操作压力也会增加，最终在样例较多的时候segmentation fault



## 链表

用数组模拟链表，数组的下标就是链表地址，e数组存储的是value，head、ne数组存储的是下标，就是理解为链表的地址。

## 双链表（这道题和链表一起刷）

数组模拟双链表中，数组的0，1号下标用来固定表示头节点和尾节点，但这是两个虚的节点。和单链表中定义了一个head的int变量并总指向头节点所在的下标不同。

这道题卡了很久



## 表达式求值（多练）

核心：双栈。操作符栈和操作数栈。

核心思想：遇到数字，直接入栈，遇到操作符，比较与栈顶操作符的优先级，如果栈顶操作符优先级高，则执行栈顶操作符的计算；如果未入栈操作符的优先级高，则直接入栈

遇到括号：左括号，直接入栈；右括号：一直执行操作符计算，直到操作符栈栈顶为左括号为止

用到的工具

- c++ stack: #include<stack>,  stack<int> stack_name
- c ++ unordered_map: #include<unorder_map>, unorder_map<int, int> its_name = {{1, 1}, {key2, value2}, ...}

- 判断字符是否是数组：isdigit(c)



取top或pop之前记得想想需不需要判断栈空

最后一步的计算并非一定只剩下一个运算符的，要用while而不是if



## 滑动窗口

其实这道题和单调栈的那道题几乎一样，语义都是：如果“我比你右我还比你小，那你就都没用了”，只不过滑动窗口这道题的“栈底”元素需要随着窗口的移动被除掉，所以不能用栈



## KMP算法（多练多练多练多练）

输出一个字符串并且让其从1开始

char s[];

cin >> s+1;



生成next和比较的过程非常类似。

找到next[i]：就是要找到next[i - 1]的位置后，比较a[next[i - 1] + 1] 和a[i]是否相等。相当于：现在用next数组前面的部分匹配了i前面的部分，如果此时a[next[i - 1] + 1] 和a[i]相等，next[i]不正是next[i - 1] + 1吗

无论是生成next还是匹配，i的作用是指向“正在比较的字符”，

**关于j：**

- 对于生成next的步骤：j指向的是i前一个字符的next。所以当a[j + 1] = a[i]时，意味着：a[i]的（前一个字符的next的下一个字符）也等于a[i]，所以i的next就是j++

- 对于比较时的步骤：j指向的字符意味着子串中j以前（包含）j的字符都已经比较成功。所以当a[j + 1] = b[i]，意味着j可以++。当a[j + 1] != b[i]，则j = ne[j]，依然能满足j的定义。

从含义上，两者的区别在于，*生成next时*，j不能是简单的理解为i的前一个字符，**而是前一个字符的next**。如果j的含义知识i的前一个字符，则当a[j + 1] = a[i]并不能得出ne[i] = j+1（这样岂不是当自己比较失败之后，又和自己比较吗？）。而*比较时*，j的含义则既可能是i（当前比较字符）的前一个字符，也可能是当前比较字符的前一个字符的next。

两者含义的差别就在于生成next时的j**是多next了一步的**。在代码上的差别则非常细微，在处理初始化时注意即可。

**多想多背多刷**



## 最大异或对

1. 用tier树存储所有数
2. 再次用到，求n的二进制表示中，第k位是几：右移k，再&1
3. 一个数<2^n，那么这个数最大是2^n - 1，则最多用n位来存储，最大的数的最高位的下标是n-1
4. 当遇到一个数字逐位往上+的时候，往往用到的是x * n + b的操作。这个时候要想清楚是先+还是先*。如果是乘了再+，最后的结果可能会打n倍，尽管可以在最后除以n补救，但当遇到边界数据的时候可能越界。



## 食物链

最核心的一点：维护一个d数组，d[i]表示的是点i到其**父节点**的距离。

此时的find函数要完成两件事：一是压缩路径，二是压缩路径后的d[i]表达的是i点到根节点的距离（因为压缩路径后父节点就是根节点）。因此find函数要完成**边压缩，边累加**的操作

在ac的过程中遇到了非常多的小问题，小问题累加起来变成了一次次奇怪的结果。



## 模拟堆

down的时候的那个传入的t和临时变量i，在if中的使用的时候用i什么时候用t，真的看清楚。。。不然坑到爆



## 走迷宫

bfs遍历的时候，要用d[][]来标记什么走过的路径，却不能在path中直接把走过的路径修改为“墙”，不然segmentation fault，很怪



## 全排列

所有用一个字典标记状态的问题，都可以考虑一下用位运算进行优化



## 树的重心

树的一个重要的性质：如果一棵树的边是无向的，也就是说这棵树只是一个树形态的图（无向无环连通图），那么此时任何一个节点其实都可以是根节点



存储树和图的时候的e和ne数组大小应该是**边的数量**，而不是点的数量



## 图中的层次

AcWing的调试功能。。一言难尽。当wa之后换了代码，再用wa的样例去调试，如果恰巧那个案例很长，那么结果就不是真的代码跑出来的结果，和下面显示的参考答案不一样。但是提交了之后一样能ac的



## 3Sum问题

最优就是O(n2)的了。

排好序之后定住一个点。剩余两哥点用双指针找到（即2Sum的方法）。然后循环定住的点。



重点在重复的元素





**坑坑坑坑坑坑**：当for循环里面希望是：如果xxx，就continue的话，就**正常写if+continue就好了**，不要把条件写到for的中间那里去，那里的语义是当false，则break



## 在移动过的有序序列用二分

当二分的分界点真的很难用一句if else说明白的时候，要分子if else，而还要避免出现边界问题，最好就是保证，无论多少个if else，最终循环的处理结果都是r = mid， l = mid + 1，这样可以避免出现死循环

![image-20220809191222778](C:\Users\Aaron\AppData\Roaming\Typora\typora-user-images\image-20220809191222778.png)



## 模拟LRU

双链表 + map

map用来O(1)访问key value

双链表用来O(1)完成访问次序的增、删、改

其实LRU最核心的就是如何选用一个数据结构，保存一个序列，且该序列的增删改查都要在O(1)完成。所以用map保证查的O(1)，只要能查到，双链表的也可以做到O(1)增删改了



unordered_map的查找

```c++
unordered_map<string, string>::iterator it = m4.find("sc0301");  // 查找关键字为"sc0301"的元素,返回一个迭代器
if (it == m4.end()) {         // 若"sc0301"不在容器中，则it等于尾后迭代器
cout << "未找到！" << endl;
}
else {
pair<string, string> result1 = *it;	// 找到了
}
```



LRU的最近访问是最近get过，不是最近put过



链表节点要保存key value对，因为有两种删除操作



还需要考虑update的操作，即put进去的时候，如果value不同，要更新value。



为了不tle，在进行节点移动到头节点的时候，应该直接操作链表移，而不是删了再插入



## 反转链表

空间复杂度O(1)完成的话，定义三个关键指针：p，c，n。代表上一个节点，当前节点，下一个节点



## 反转以k为一组的链表

用快慢指针定位到当前group的头和尾

保存上一组的尾节点（也就是上一组反转之前的头节点）

当前组反转之后的尾节点默认值指向反转之前尾节点的next（因为还不知道下一组要不要反转）。如果下一组也要反转，则在反转完之后再根据上一组的尾节点，调整上一组尾节点的next



## 103蜿蜒遍历二叉树

两个栈



## 121买卖股票

双指针



## 200岛的数量⭐

并查集

一堆点或者元素，在若干个集合里面，各集合要能更新、能插入操作的，就是并查集，非常高效



## 236 最小公共父节点

dfs



## 160找到两个链表的公共节点

1. hashmap：**两个序列、公共、找**，这些关键词出现的时候想到用map
2. 本题的巧解：如果两个链表有公共节点，那么用两个指针去遍历两个链表，当一个指针遍历完后指向另一个链表的链表头。最终两个指针一定会在交点相遇，因为：
   1. 假设两个链表分为3部分，交点之后的点为c，交点之前的点分别为a和b。那么两个链表先走完自己的一遍，再走一遍对方的，相当于分别走了a+c+b和b+c+a，所以最终一定会相遇。
   2. 如果两链表不相交且不等长，那么个指针分别走了a+b与b+a，则一定会通知走到空



## acwing897 最长上升子序列Ⅱ

用到的方法不太像dp了

保存每个长度的最长公共子序列中末尾数的最小值



## acwing899编辑距离

当用到字符数组存储字符串，且要获得字符串长度的时候：

```c++
#include<string.h>

char str[N];
int len = strlen(str);

//如果字符串是用下标一开始存
len = strlen(str + 1);
```





# DP问题状态定义的启发

一般和一段序列有关的状态定义f[i, j]有两种

- a前i个和b前j个元素的xxxx，即f[i,j]可以不选到i或j的（背包问题、编辑距离）
- 以a[i]、b[j]结尾的xxxx（最长上升子序列）



## 下一个排列

Not best

思路1. 找到最后一个上升对a[i], a[j]，找到i后面最小的、且比a[i]的数a[t]，swap(a[i], a[t])。然后sort一下i+1后面的元素

O(nlogn)时间复杂度



## 罗马数字转数字

做重要的是分类讨论



## 接雨水

按层数遍历，O(n^2)，超时



双指针：初始化左指针和右指针，左右指针都要指向柱子

- 如果左指针<右指针，意味着左指针右边所有低于柱子的格子都必然能储水。
- 反之亦然



## 最长上升子序列

怎么初始化，最后输出什么，二分从哪里找到哪里，绕晕了



## 二叉树层序遍历

最重要的是怎么得到一层的结束。

可以在queue中放一个特殊的标记。



## 92反转链表Ⅱ

不能用(p == q -> next)判断指针是否相等。即使相等，判断也是false

而 qn = q->next, (p == qn)，就能正常判断了。。。



## 73矩阵清零

想到了很多办法：

- 开两个数组，分别标记要被清零的行和列。SC=O(n + m)

- 用位优化来代替两个数组，需要SC = O(log(n + m))个bit的空间复杂度

- 标记法：给需要清零的元素打标记（不能直接置0，因为后续的遍历中不知道那些是原本的0哪些是新的0）.SC = O(1)，但是题目把元素数据范围覆盖了int的范围，不行
- **借用第一列和第一行**：借用第一行和第一列来标记要清空的行/列，额外定义两个变量来标记第一列和第一行是否要清空。SC = O(1)



## 69Sqrt(x)

这题看上去是浮点数二分，实际上是整数二分

要找到一个数n， n^2 >=x或 <=x，最后判断如果n^2 == x，返回n，否则，如果找的是 >=x的n^2，则返回n - 1



## 环形链表

判断环：快慢指针，如果有环必相遇

判断入口：数学问题。如果有环，在快慢指针相遇的时候，定义新指针k指向头节点，然后k和慢指针一起移动，相遇的时候就是环入口



## 98验证查找二叉树

想到的办法：

dfs的时候传两个阈值下去，根据递归的是左子树还是右子树调整子树的阈值



另一个方法：

中序遍历二叉树完美解决

对于查找二叉树，如果中序遍历一定会输出一个从小到大的序列，所以只要中序遍历，并总保存上一个遍历的点，当当前点不比上一个点大，就说明不是查找二叉树



## 39 组合和

排序+去重

然后dfs搜索



不排序也可以，但是在dfs遍历数组各点的时候，当当前结果sum>target之后，不能提前退出，要继续遍历完后面的所有数



## 55jump game

好题

贪心



## 211设计tire树

多练习

形参const意味着不可以修改



## 212 Word Search Ⅱ

直接dfs：超时



对整张表所有可能出现的词建Trie树，然后在树中查找各词：超时。第一步时间复杂度太大



正解：对各个词建trie树，然后对表用dfs找



在递归时传递向量的引用，比一直使用一个全局的向量要更快



全局数组和局部数组则不会有很明显的变化。相反如果递归次数多的话，局部数组不断重复定义可能更加耗时



## 347 遍历



## 79 Word Search

联想到Word Search Ⅱ：在具有**多个字符串**判断的时候才考虑Tire树，只有一个字符串的话一般就不考虑



## 100 & 101

same tree 和判断对称树：都是判断两棵树是否相等，代码几乎一样

判断对称树不能用先序、后序遍历的方式。有bug



## 128 最长连续子序列⭐

1. 只需要去重和O(1)访问的时候可以用unordered_set，而不是map
2. 要达到O(n)并不等价于只能写一重循环。有时候可以写两重循环，只要保证每个元素只访问了常数次就可以。这道题的O(n)方法非常有启发意义。



## 3Longest Substring Without Repeating Characters && 424Longest Repeating Character Replacement && 567Permutation in String

这两题都是滑动窗口。可以看出滑动窗口经常和hashmap一起使用的



## 875Koko Eating Bananas

**想复杂了**，想用两步二分，想法可以但是边界条件太绕了。

而且要用两部二分就要给原始数组先做排序，从理论上复杂度相当。

mid的题不应该那么绕的，下次注意。



## 45Jump Game II

求最短路径一定要想到**BFS**啊啊啊啊

BFS不一定非要用queue。详见别人的题解



## 621 Task Scheduler

非常非常骚



## 322 coin change

这题掌握思路思路之后很简单，但是实现上要注意：

- 第二层循环是对coins数组进行遍历
- 不能用0表示不可达。因为0（不选）也是可达的一种。要用INT_MAX来表示不可达

## 240 Search a 2D Matrix II

做不到O(log(m + n))的

1. 每行都来一次二分，则O(mlogn)
2. 更妙的方法，但线性。从右上角元素开始找，每次遍历排除一行或一列。O(m + n)