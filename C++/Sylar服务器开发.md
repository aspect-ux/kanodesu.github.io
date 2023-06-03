# Sylar服务器开发

## 配置报错及其他

### 项目目录结构

```txt
build #中间文件目录
aspect[name] #源代码文件
CMakeLists.txt
lib #库输出
bin #二进制
tests #测试源代码
```



### cmake

1. [4. CMake 中 set 的使用 - 下_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV14s4y1g7Zj?p=4&vd_source=2b3a7e4dffb44c07076538fe075cb1cf)

#### Toolchain

编辑器将源文件变成可运行文件（如果使用集成环境，点击编译就可以生成可执行文件）

称之为toolchain（整个过程就是高级语言转换成二进制可执行文件）

1. 预处理器（预编译）将头文件展开，宏替换，注释去掉

   ​    `gcc - E test.c  -o test.i`

   -E使得预处理后停止

2. 编译器gcc/g++   

   ` gcc -S test.i -o test.s`   -S代表停止不进行后续。生成**汇编代码**

3. 汇编（器）将汇编代码转换成**机器码** 二进制也就是.o或obj 叫做**目标文件**

   `gcc -c test.s -o test.o`

4. 链接器（对`windows *.obj,linux *.o`)将目标文件和其他头文件库文件链接成可执行文件

   `gcc test1.o test2.o test3.o -o main`

最后生成可执行文件

常用命令

`gcc/g++ test.cxx -o test.o`

`gcc/g++ test.o -o main`

或者 `gcc/g++ test.cxx -o test` 直接生成

#### makefile

编写`makefile`

make批处理命令使得makefile运行

cmake能根据不同平台生成对应makefile



#### cmake命令

1. [(116条消息) Cmake编写CmakeList.txt 语法备忘_HW140701的博客-CSDN博客](https://blog.csdn.net/HW140701/article/details/90203141?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-2-90203141-blog-105183076.235^v36^pc_relevant_default_base3&spm=1001.2101.3001.4242.2&utm_relevant_index=5)

* 如何make

`cd build`

`cmake ..//CMakeLists在上一层目录,生成makefile文件`

`make`

* `cmake --version //查看版本`

* 如何更换低版本`cmake`

1. [(116条消息) ubuntu改变cmake版本_mdjxy63的博客-CSDN博客](https://blog.csdn.net/mdjxy63/article/details/82686504)

2. [(116条消息) ubuntu安装cmake-CSDN博客](https://blog.csdn.net/yuanzhoulvpi/article/details/122938078)

```
sudo apt-get install build-essential
 
#http://www.cmake.org/files  这个网站里面有cmake的所有版本的列表，下载对应的cmake版本
wget http://www.cmake.org/files/v3.4/cmake-3.4.1.tar.gz
tar xf cmake-3.4.1.tar.gz
cd cmake-3.4.1

//检查是否有报错
./bootstrap

make

//如果cmake --version失效，cp bin/cmake /usr/bin/
```

* 卸载cmake

  `which cmake`查看是否有cmake

  `sudo apt-get remove cmake` 卸载已有cmake

#### 编写CMakeLists.txt

* `add_executable(test tests/test.cc)`

  多个源文件可以用空格或分号，执行`cmake ..`直接生成可执行文件

* `SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)`

  将变量写到$的大括号里，指定可执行文件的输出路径

* set也可以用来设置c++标准，不论是lists里面还是cmake命令后面

* 生成静态库，可执行文件大，运行快；动态库可执行文件小，运行慢

  生成的静态库名字和文件名一致

  静态link_library放到executable前面

  动态target_link_library放到最后面，也可以链接静态库

* cmake_cxx_flags

  [(116条消息) CMake指令解析 set(CMAKE_CXX_FLAGS “$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprec_For Nine的博客-CSDN博客](https://blog.csdn.net/m0_51551385/article/details/125083575)

**案例**

子节点CMakeLists,项目名是子节点目录名，搜索源文件，生成静态库

![image-20230603111943955](CPP/image-20230603111943955.png)

根节点CMakeLists，添加子目录，链接各个子节点，添加可执行文件

![image-20230603112812959](CPP/image-20230603112812959.png)

### boost库安装

1. [(117条消息) ubuntu 安装 Boost_乌恩大侠的博客-CSDN博客](https://blog.csdn.net/qq_36666115/article/details/131015894)

### 报错

#### Cmake报错

* **Cannot specify link libraries for target " XXX XXX " which is not built by this project.**

  可能是顺序错误executable在前，也可能是空格是中文空格

  ![image-20230603011217203](CPP/image-20230603011217203.png)

## 日志系统

### 日志01框架搭建

Logger日志器

`LogAppender`日志输出地

`LogFormatter`日志格式器

`LogEvent`日志事件

### 日志02 logger

![image-20230520000615024](CPP/image-20230520000615024.png)

## 配置系统

使用Yaml进行配置



# 参考链接

1. c语言实现协程库

   [cloudwu/coroutine: A asymmetric coroutine library for C. (github.com)](https://github.com/cloudwu/coroutine/tree/master)
