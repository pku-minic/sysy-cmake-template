# 基于 CMake 的 SysY 编译器项目模板

该仓库中存放了一个基于 CMake 的 SysY 编译器项目的模板, 你可以在该模板的基础上进行进一步的开发.

该仓库中的 C/C++ 代码实现仅作为演示, 不代表你的编译器必须以此方式实现. 如你需要使用该模板, 建议你删掉所有 C/C++ 源文件, 仅保留 `CMakeLists.txt` 和必要的目录结构, 然后重新开始实现.

该模板仅供不熟悉 CMake 的同学参考, 在理解基本原理的基础上, 你完全可以不使用模板完成编译器的实现. 如你决定不使用该模板并自行编写 CMake, 请参考 [“评测平台要求”](#评测平台要求) 部分.

## 使用方法

首先 clone 本仓库:

```sh
git clone https://github.com/pku-minic/sysy-cmake-template.git
```

进入仓库目录后执行:

```sh
cd sysy-make-template
cmake -B build
cmake --build build
```

CMake 将在 `build` 目录下生成名为 `compiler` 的可执行文件.

如在此基础上进行开发, 你需要重新初始化 Git 仓库:

```sh
rm -rf .git
git init
```

然后将自己的编译器的源文件放入 `src` 目录.

## 评测平台要求

当你提交一个根目录包含 `CMakeLists.txt` 文件的仓库时, 评测平台会使用如下命令编译你的编译器:

```sh
cmake -S "你的repo的路径" -B "build目录的路径"
cmake --build "build目录的路径" -j `nproc`
```

你的 `CMakeLists.txt` 必须将可执行文件直接输出到所指定的 build 目录的根目录, 且将其命名为 `compiler`.
