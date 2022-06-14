==1.标题==
大标题
===

中标题
---

# 一级标题

## 二级标题

### 三级标题

#### 四级标题

##### 五级标题

###### 六级标题

==2.换行==
换行<br>换行
换行用\<br>或\<br/>
==3.单行文本==

    单行文本
==4.多行文本==

    多
    行
    文
    本
==5.部分文字的高亮==
部分文字的`高亮`
==6.文字超链接==
这是一个[文字超链接](https://www.baidu.com)
==7.悬停显示文本==
这是一个[悬停显示文本](https://www.baidu.com "悬停显示")
==8.插入符号==

* 1
  * 2
    * 3

* 1
  * 2
    * 3

==9.缩进==
>数据结构
>>树
>>>二叉树
>>>>平衡二叉树
>>>>>满二叉树

==10.插入图片==
[![baidu](http://www.baidu.com/img/bdlogo.gif "百度logo")](http://baidu.com)
==11.插入代码片段==

```java
Java public static void main(String[]Jarga){}//Java
```

```c
int main(int argc, char * argv[])//C
```

```bash
echo "hello GitHub"# Bash
```

```javascript
document. getElementdyId("myH1"). innerHTML="Welcome to my Homepage"; //javascript
```

```cpp
string &operator+(const atrings A, const atrings B)//cpp
```

==12.斜体==
*斜体*
==13.有序序号==

1. 111
2. 222
3. 333

==14.横线==

---
***
==15.表格==

 | 表头表头表头 | 表头表头表头 | 表头表头表头 | 表头表头表头 |
 | ------------ | :----------: | -----------: | ------------ |
 | 居左         |     居中     |         居右 | aaa          |

<table>
<tr><th align="left">表头表头表头</th><th>表头表头表头</th><th>表头表头表头</th><th>表头表头表头</th></tr>
<tr><td align="left">左</td><td align="center">中</td><td align="right">右</td><td>aaa</td></tr>
</table>

==16.文字上下标==
文字^上标^
文字~下标~

==17.流程图==

| 标志 |         方向          |
| :--: | :-------------------: |
|  TB  | top bottom - 从上到下 |
|  BT  | bottom top - 从下到上 |
|  RL  | right left - 从右到左 |
|  LR  | left right - 从左到右 |
|  TD  |       等同于 TB       |

```mermaid
graph TB
    1[开始] --> 2[结束]
```

```mermaid
graph LR
    1[方形] --> 2(圆角) --> 3((圆形)) --> 4>非对称] --> 5{菱形} --> 6{{六角形}}
```

```mermaid
graph LR
    1[\平行四边形\] --> 2[/平行四边形/] --> 3[/梯形\] --> 4[\梯形/]
```

* 样式的含义：
  * 有箭头：一般指数据流方向
  * 无箭头：仅表示相关性
  * 实线：强关联
  * 虚线：弱关联

```mermaid
graph LR
    1[开始] --> 2[结束]
```

```mermaid
graph LR
    1[begin] --- 2[end] -- 带文字的无向连接线 --- 3[ooooooo]
```

```mermaid
graph LR
    1[one] -.- 2[two] -.带文字的虚线.- 3[three] -.带文字和箭头的虚线.-> 4[four]
```

```mermaid
graph LR
    1[one] === 2[two] == 带文字粗箭头 ==> 3[three]
```

```mermaid
graph TB
    c1-->a2
    subgraph 第一组
    a1-->a2
    end
    subgraph 第二组
    b1-->b2
    end
    subgraph 第三组
    c1-->c2
    end
```

```mermaid
graph LR
    执行1[i = 1]
  执行2[j = 0]
  执行3[i ++]
  执行4["a = arr[j], b = arr[j + 1]"]
  执行5[交换 a, b]
  执行6[j ++]
    判断1["i < n"]
    判断2["j < n - i"]
  判断3["a > b"]
  开始 --> 执行1
  执行1 --> 判断1
  判断1 --Y--> 执行2
  执行2 --> 判断2
  判断2 --Y--> 执行4
  判断2 --N--> 执行3
  执行3 --> 判断1
  执行4 --> 判断3
  判断3 --N--> 判断2
  判断3 --Y--> 执行5
  执行5 --> 执行6
  执行6 --> 判断2
  判断1 --N--> 结束
```

```mermaid
graph TB
默认方形
id1[方形]
id2(圆边矩形)
id3([体育场形])
id4[[子程序形]]
id5[(圆柱形)]
id6((圆形))
id7{菱形}
id8{{六角形}}
id9[/平行四边形/]
id10[\反向平行四边形\]
id11[/梯形\]
id12[\反向梯形/]
```
