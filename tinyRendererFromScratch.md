# Tiny Renderer From Scratch

## Preparations

### CMAKE

[Index of /files/PreviousRelease (cmake.org)](https://cmake.org/files/PreviousRelease/)

### MAKE FOR WINDOWS

https://gnuwin32.sourceforge.net/packages/make.htm

build 目录下cmake .. -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G "Unix Makefiles"

配置c++

```cmake
cd build
cmake ..
make
```



## Project

### example1_point_lighting

main.cpp

constexpr c++11标准，可以使得const变量在编译阶段计算出值，而不是在运行阶段（也可能。。。）



