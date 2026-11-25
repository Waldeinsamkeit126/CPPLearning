# 数据结构课程作业归档

[返回仓库首页](../../README.md)

归档上海财经大学「数据结构（0781）」课程中已提交的 Quiz10–16 与作业7–12。按要求跳过 Quiz14，实际包含 **6 份 quiz、6 份作业，共 12 份提交**。采集日期：2026-11-25。

源码来自 Canvas 提交详情中的文本内容；有多次提交时采用页面当前显示的提交。整理仅替换网页不换行空格、统一缩进和空行、保存为 UTF-8，保留原有代码、注释与未完成部分。文件名按编号和主题补充，便于检索。

## Quiz

| 编号与题目 | 主要内容 | 源码 | 状态 |
| --- | --- | --- | --- |
| Quiz10 走迷宫 | 递归 DFS 与显式栈回溯；递归版本保留在注释块中 | [Quiz10-Maze.cpp](Quizzes/Quiz10-Maze.cpp) | 非递归入口编译、运行通过 |
| Quiz11 打印杨辉三角形 | 使用队列逐行生成系数 | [Quiz11-PascalTriangle.cpp](Quizzes/Quiz11-PascalTriangle.cpp) | 编译、内置示例通过 |
| Quiz12 二叉树的深度与平均值 | 递归求深度，栈遍历统计总和与节点数 | [Quiz12-TreeDepthAndAverage.cpp](Quizzes/Quiz12-TreeDepthAndAverage.cpp) | 编译、内置示例通过 |
| Quiz13 堆排序 | 非递归向下调整，最小堆实现降序排列 | [Quiz13-HeapSort.cpp](Quizzes/Quiz13-HeapSort.cpp) | 编译、内置示例通过 |
| Quiz15 哈希表查找操作 | 分离链接、查找、删除与扩容 | [Quiz15-HashTable.cpp](Quizzes/Quiz15-HashTable.cpp) | 编译、内置示例通过 |
| Quiz16 二叉树练习 | 由先序、中序构造树并输出后序 | [Quiz16-BinaryTree-Incomplete.cpp](Quizzes/Quiz16-BinaryTree-Incomplete.cpp) | **未完成，不能编译** |

Quiz14「删除二叉搜索树上的节点」不在本次归档范围内，不使用题目模板代替个人提交。

## 作业

| 编号与题目 | 主要内容 | 源码 | 状态 |
| --- | --- | --- | --- |
| 作业7 汉诺塔问题的非递归求解 | 使用任务栈模拟递归调用 | [Homework07-IterativeHanoi.cpp](Homework/Homework07-IterativeHanoi.cpp) | 编译通过；输入 3 的示例通过 |
| 作业8 根据先序和中序遍历的序列构造二叉树 | 分割序列区间，递归构造左右子树 | [Homework08-ReconstructBinaryTree.cpp](Homework/Homework08-ReconstructBinaryTree.cpp) | 编译、内置示例通过 |
| 作业9 后序遍历的游标类 | 带左右访问标记的栈与迭代器接口 | [Homework09-PostorderIterator.cpp](Homework/Homework09-PostorderIterator.cpp) | 编译、内置示例通过 |
| 作业10 三进制哈夫曼编码 | 三叉哈夫曼树、虚拟叶子、编码与解码 | [Homework10-TernaryHuffman.cpp](Homework/Homework10-TernaryHuffman.cpp) | 编译、内置往返示例通过 |
| 作业11 AVL树的平衡操作 | 单旋、双旋及插入删除后的平衡维护 | [Homework11-AVLTree.cpp](Homework/Homework11-AVLTree.cpp) | 编译、内置示例通过 |
| 作业12 归并排序算法 | 区间递归与有序段合并 | [Homework12-MergeSort.cpp](Homework/Homework12-MergeSort.cpp) | 编译、内置示例通过 |

## 编译与运行

在仓库根目录，每次单独编译一个文件。例如 PowerShell：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 Coursework/DataStructures/Quizzes/Quiz10-Maze.cpp -o build/quiz10.exe
.\build\quiz10.exe

g++ -std=c++17 Coursework/DataStructures/Homework/Homework07-IterativeHanoi.cpp -o build/homework07.exe
"3" | .\build\homework07.exe
```

汉诺塔示例读取一个正整数；其余完整提交使用代码内置数据。不要把这些文件一起链接，每个完整练习都包含自己的 `main()`。Quiz16 仅供阅读，不能按完整程序运行。

## 已知局限与归档原则

- **Quiz16** 的提交止于 `int height`，没有后续函数实现或 `main()`。归档保留此状态。
- **Quiz12** 使用整数除法计算平均值，小数部分会被舍去。
- **Quiz13** 的部分原注释仍写“最大堆”，实际调用的非递归函数构造最小堆并得到降序结果。
- **作业7** 的输入应为正整数，原提交未处理非正数。
- **作业10** 的编码符号为三进制数字，原输出将字符数称为 bits，不能据此直接解释真实二进制压缩率。
- **作业12** 原程序打印 `Original array:` 后没有输出原数组；排序结果仍会输出。

本次迁入不改写算法或补答题目。编译与示例通过不代表所有边界情况均正确；具体检查见[验证记录](VERIFICATION.md)。课程题目框架与原提交注释一并保留，未新增统一许可证。

[归档清单](archive-manifest.json)记录课程作业链接、文件路径和 SHA-256；链接需要课程访问权限。
