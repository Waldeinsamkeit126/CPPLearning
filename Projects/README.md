# 自定义类练习

[返回仓库首页](../README.md)

| 项目 | 内容 | 运行状态 |
| --- | --- | --- |
| [RationalCustom](RationalCustom/) | 有理数、运算符重载、流输入输出 | `q2.cpp` 为入口，需与 `rational.cpp` 一起编译；有已知计算问题 |
| [StringCustom](StringCustom/) | 动态字符数组、拷贝、拼接与流操作 | `string.cpp` 配合 `string.h`，没有独立 main |
| [BigInt](BigInt/) | 大整数表示、加法与输出 | 单文件练习，有已知头文件及初始化问题 |

## 有理数练习

从仓库根目录编译（PowerShell）：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 Projects/RationalCustom/q2.cpp Projects/RationalCustom/rational.cpp -o build/rational.exe
.\build\rational.exe
```

输入是两个有理数的分子、分母，共四个整数，如 `1 2 3 4`。程序演示加减乘除；当前减法和约分实现尚待修复，输出不能作为正确性依据。

`StringCustom/random.h` 只有随机数类声明，当前目录没有对应实现。其他已知问题见[待完善项](../KNOWN_ISSUES.md)。
