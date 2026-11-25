# C++ 学习与练习

记录 C++、STL、算法、数据结构及自定义类的学习过程。各文件是独立练习或课程片段，完成程度不同。

## 分类导航

| 分类 | 内容 | 入口 |
| --- | --- | --- |
| STL 与标准库应用 | 容器计算、排序与归并 | [STL](STL/README.md) |
| 算法 | 二分、搜索、动态规划、贪心、滑动窗口、排序与双指针 | [算法目录](Algorithms/README.md) |
| 数据结构 | 链表、迭代器、多项式与稀疏矩阵 | [数据结构目录](DataStructures/README.md) |
| 自定义类 | 有理数、字符串与大整数练习 | [小项目目录](Projects/README.md) |
| 课程作业 | 数据结构课程 Quiz10–16（不含14）、作业7–12 | [课程归档](Coursework/DataStructures/README.md) |

## 从一个例子开始

安装支持 C++17 的编译器，在仓库根目录执行（PowerShell）：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 Algorithms/DynamicProgramming/01Pack.cpp -o build/knapsack.exe
.\build\knapsack.exe
```

此例使用代码内置数据，预期输出为 `7`。其他题目可能需要标准输入，运行前请查看对应 `main()`。

每次编译一个练习；不要将全仓库的 `.cpp` 一起链接。多个文件含独立的 `main()`，部分文件只是类或函数片段。多文件项目请看各目录说明。

## 当前状态

- 已有内容：标准库应用、算法、数据结构、自定义类及数据结构课程作业。
- 后续学习方向：Linux、多线程、网络编程、AI Infrastructure；这些是学习目标，当前尚无对应模块。
- [已知待完善项](KNOWN_ISSUES.md)记录整理时从源码确认的问题；本仓库不是经过完整测试的算法库。

## 目录调整对照

| 原路径 | 现路径 |
| --- | --- |
| `Sructure/` | `DataStructures/` |
| `Algorithms/LinkedList/` | `DataStructures/LinkedList/` |
| `Algorithms/BinaryResearch/` | `Algorithms/BinarySearch/` |
| `Algorithms/DynamicPro/` | `Algorithms/DynamicProgramming/` |
| `Algorithms/MonoDeque/` | `Algorithms/MonotonicStackAndQueue/` |
| `STL/BigInt.cpp` | `Projects/BigInt/BigInt.cpp` |

整理保留了练习源码内容。排序目录中的 `LinkedList.cpp` 是与链表目录相同内容的历史副本，暂保留并标注。

## 新增内容约定

按知识点选择目录；独立练习说明题意、输入输出和思路；多文件练习增加 README，说明入口、编译方式与未完成部分。编译产物放入 `build/`。

相关仓库：[Python 学习](https://github.com/Waldeinsamkeit126/PythonLearning) · [竞赛与工具项目](https://github.com/Waldeinsamkeit126/Projects)
