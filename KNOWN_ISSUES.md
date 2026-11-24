# 已知待完善项

[返回仓库首页](README.md)

以下来自源码检查，是学习记录，未在本次目录整理中改写算法。

| 文件 | 已确认的问题 |
| --- | --- |
| [LinkedList2.cpp](DataStructures/LinkedList/LinkedList2.cpp) | `print()` 末尾括号位置错误，`cout` 落在函数外，无法直接编译。 |
| [KthReverse.cpp](DataStructures/KthReverse.cpp) | 缺少完整节点定义或独立入口，需要放入相应题目上下文。 |
| [BigInt.cpp](Projects/BigInt/BigInt.cpp) | 使用 `pow` 但没有包含 `<cmath>`；小数值输入时 `len` 的初始化不完整。 |
| [rational.cpp](Projects/RationalCustom/rational.cpp) | 减法函数使用了加号；约分循环没有用循环变量作为除数；分母与符号边界尚待处理。 |
| [CustomSort.cpp](Algorithms/Sort/CustomSort.cpp) | 比较函数在字符串相同时没有返回值。 |
| [Josephus.cpp](DataStructures/Josephus.cpp) | 步长为 1 时 `pre` 仍为空，随后会被解引用。 |
| [MergeSort.cpp](Algorithms/Sort/MergeSort.cpp) | 文件名与实现不符，当前是 O(n²) 逆序对计数。 |

上述列表不是完整代码审计。验证其他题目时，应补充题意、输入范围、样例和边界测试。
