# cpp note day day dream

参考：[Top (The C Preprocessor) (gnu.org)](https://gcc.gnu.org/onlinedocs/cpp/)

## 1. c++ 模板编程(泛编程)
### 1.1 自动推导
#### **auto**
c++11中，auto作为类型指示符，编译时推导变量的数据类型
**使用场景：**

* 右值可以是具体的数，也可以是表达式或函数
* 不能作为形参类型
* 不能声明数组，类的非静态成员变量。
* 代替冗长变量声明

#### delctype
c++11中，用于推导数据类型
语法
```c++
decltype(expression) var;

//示例：
void func(std::string line)
{
	std::cout << "func() is called at " << line << std::endl;
}
//...
void test_DeclType()
{
	//1.
	/*short n1 = 1;
	short& n2 = n1;
	decltype(n2) n3 = n1; // 引用类型需要初始化
	Print(n3);*/

	//2.
	decltype(func(std::to_string(__LINE__)))* p1 = func; // 不会调用
	p1;

	decltype(func)* p2 = func; // 声明为函数指针
	p2(std::to_string(__LINE__));

	//3.
	int a1 = 0;
	decltype((a1)) a2 = a1; // expression = (a1)时等价于引用
	decltype((func)) a3 = func;
	a3(std::to_string(__LINE__));
}
//...

// 其他使用方法
// auto func(int a,int b) -> int{return a + b;}
```

### 1.2 函数模板
示例
```cpp
// 函数模板示例
//1.
template<typename T>
void Print(T a, T b)
{
	std::cout << a << ' ' << b << std::endl;
}
//...
Print(1,2);      // 隐式调用
Print<int>(1,2); // 显示调用
//...
//2.
template<typename T,typename N>
void Print(T a, N b)
{
	std::cout << a << ' ' << b << std::endl;
}

// 函数模板的具体化（特化）
// 3.具体函数模板,使用优先级大于普通函数模板
template<> void Print(User& u1, User& u2)
{
	std::cout << u1.name << ' ' << u2.name << std::endl;
}
```
原理就是，调用函数的时候，发现函数模板，然后分析实参的数据类型，内部生成对应的函数实例，生成的函数名会在原有的名字上加各种修饰符，这也是函数重载的原理。
**使用场景：**
* 可以用于类函数，但是不能用于虚函数，不能用于析构函数（没有参数）
* 模板不能隐式转换，需要显示声明类型。
  例如，如果调用模板函数，自动分析数据类型，在实例1中，传入一个int和一个char会报错，char不会隐式转换成int类型。
* 支持函数重载
* 优先级，普通函数>具体函数模板>普通函数模板
  具体优先级还需要看参数匹配度
* 函数模板没定义就放在头文件中，有定义就在源文件中

### 1.3 类模板

示例

```c++
// 5. 类模板,可以指定默认类型实现缺省
template<class T,class N = std::string>
class Student
{
public:
    Student(T age,N name) : age(age), name(name){}
    void PrintStudentData()
    {
        printf("该学生年龄=%d", age);
        std::cout << "名字是" << name << std::endl;
    }
private:
    N name;
    T age;
};
```

* 不能在类外为函数指定默认类型

* template<class>和template<typename>本质上一样，但是后者可以用于嵌套，

  typename用于告诉编译器修饰的不是类，也不是函数，而是数据类型。

## 2. c++实现计时器

### std::chrono

c++11引入

包含了三种时钟类

* `system_clock`系统时钟，可以自己设置
* `steady_clock` 稳定时钟，不可修改时钟，刻度为1ns,单调的时钟，相当于秒表，可以用于记录程序耗时（时间差），不受系统时间影响。
* `high_resolution_clock` 高精度时钟，当前系统最高精度，高精度版`steady_clock`

这三种类相互独立，都不是模板类；但是成员类型和函数大多相同。

都提供了以下成员

* `rep` 周期
* `period` 单位比率
* `duration` 时间长度，时间段

* `now()` 获取当前时间 返回类型为`time_point` 时间点

#### 编写计时器

计时器类基本代码

```c++
class Timer
{
public:
    Timer()
    {
        Reset();
    }
    // 重置
    void Reset()
    {
        // 获取当前时间(不是系统的时间)
        m_Start = std::chrono::high_resolution_clock::now();
    }
    // 已经过去的时间（消逝）
		float Elapsed()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
		}
private:
    // 声明一个高精度的time_point(记录初始时间)
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};
```

**项目中计时器的使用**(调试时用于测试程序运行时间来进行代码优化optimize)

```c++
template<typename Fn>
class Timer
{
public:
	/*
	 *@ class Timer
	 *@ description steady_clock用于记录时刻 
	*/
	Timer(const char* name,Fn&& func)
		: m_Name(name),m_Stopped(false),m_Func(func)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		// microseconds微秒
		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;

		//std::cout << m_Name << " Duration: " << duration << "ms" << std::endl;

		m_Func({ m_Name,duration });
	}
private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
	Fn m_Func;
};

// []表示捕获（capture）上下文变量，[=]按值，[&]按引用，[]什么也不捕获
#define PROFILE_SCOPE(name) Timer timer##__LINE__(name)
```

使用构造函数和析构函数控制计时器声明周期

```c++
{
	PROFILE_SCOPE("Name");//就可以调用
}
```

## 3. c++ STL

STL统称为：**"Standard TemplateLibrary 标准模板库"**

STL六大组件

* **容器：**就是熟知的存储各种数据结构的容器；
* **算法：**见名思义，就是各种常用的算法（比如：冒泡，排序算法等）；
* **迭代器：**这个可以看作成是一个指针，扮演了容器与算法之间的胶合剂的作用；
* **仿函数：**行为类似熟知的函数，它的作用可作为算法的某种策略；
* **适配器：**一种用来当作修饰（容器）或（仿函数）或（迭代器）接口的东西；
* **空间配置器（分配器）：**负责空间的配置与管理的作用；

## 4. c++ 关键字及符号

* **inline**

  在C++中，`inline`关键字用于建议编译器将函数的调用替换为函数体中的语句，这种优化方法称为内联函数（inline function）。内联函数可以减少函数调用的开销，提高程序的执行效率。当编译器将函数替换为函数体中的语句时，这个过程称为内联展开（inline expansion）。

  1. `inline`关键字只是对编译器的建议，编译器可以选择忽略该建议。编译器会根据函数的大小、调用次数等因素来决定是否进行内联展开。
  2. 内联函数通常适用于简单、执行速度快、调用频繁的函数。对于大型函数或调用次数较少的函数，内联展开可能会增加代码的大小和运行时间。
  3. 内联函数通常在头文件中声明和定义，这样可以在多个源文件中使用。如果在源文件中定义内联函数，则需要使用`inline`关键字。

  **总而言之**：内联函数: 适用于较简单、常用的小函数。需要判断函数自身所占空间资源是否小于函数调用的资源开销，小于则适用，反之会造成空间浪费。***内联是以代码膨胀复制为代价*** 。

  `inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }`

* **... (ellipsis)**,省略号，被称作可变参数模板(variadic template)

  函数传参，可以接受任意数量和类型的参数

  ```c++
  // 参数不能为空
  void foo(...) {  
      // 函数体  
  }
  
  // c++11引入，支持初始化列表的拓展
  int arr[] = {1, 2, 3, ...};
  ```

* **noexcept**

  ```c++
  // 函数后缀，用于告诉编译器该函数不会抛出异常
  [[nodiscard]] static T& GetInstance() noexcept(std::is_nothrow_constructible<T>::value)
   {
       static T instance;
       return instance;
   }
  //具体来说，当一个函数被声明为 noexcept 时，编译器会做出一些优化，以避免异常的处理。这些优化包括省略异常处理代码，减少栈展开操作和其他能够提高程序运行效率的操作。因此，使用 noexcept 可以帮助开发者提高程序的性能和可靠性。
  ```

* **nodiscard**

  表示该类或函数 不应舍弃

  如果放弃了返回值，就会warnning

  ```c++
  [[nodiscard]] int func(){return 1;}; // C++17
  [[nodiscard("nodiscard_func_1")]] int func_1(){return 2;};  // C++20
  
  // 对于类也用于函数返回值，但是对于类的引用或指针作为返回值，nodiscard不会生效
  ```

  

## 5. c++宏

### 基本概念

c++宏是预处理器(preprocessor)的一部分，预编译阶段被替换。

程序生成exe文件的流程：预编译->编译（编译成汇编代码）->汇编（生成机器语言）->链接（生成exe）

**编译之前就已经完成文本替换，被替换的字符叫做替换文本。**

用来定义常量，函数等。

```c++
// 1. 普通宏,可以是常量，函数，类型
#define PI 3.1415926

// 2. 带参函数
#define SQUARE(x) (x * x)

// 3. 条件编译，只定义，通过if else控制开关
#define DEBUG
```

### 项目中的示例

```c++
// []表示捕获（capture）上下文变量，[=]按值，[&]按引用，[]什么也不捕获; this指针只能在成员函数中使用,不能在静态函数中使用
#define AS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
```

## 6. c++线程

### 6.1 相关概念

**进程**：是指⼀个内存中运⾏的应⽤程序，每个进程都有⼀个独⽴的内存空间，⼀个应⽤程序可以同时运⾏多个进程；进程也是程序的⼀次执⾏过程，是系统运⾏程序的基本单位；系统运⾏⼀个程序即是 ⼀个进程从创建、运⾏到消亡的过程。
**线程**：线程是进程中的⼀个执⾏单元，负责当前进程中程序的执⾏，⼀个进程中⾄少有⼀个线程。⼀个进程中是可以有多个线程的，这个应⽤程序也可以称之为多线程程序。
**简⽽⾔之：⼀个程序运⾏后⾄少有⼀个进程，⼀个进程中可以包含多个线程**

并发指的是同一时间段内多个线程的发生，并行则是同一时刻多个线程的发生。

c中可以使用`pthread`

c++11中可以使用`std::thread`

**在C++中实现线程安全主要涉及两个方面：避免数据竞争和同步访问。**

### 6.2 如何实现线程安全

* mutex(互斥锁)

  ```c++
  #include <mutex>  //c++11
  std::mutex mtx;  
  // 线程函数  
  void thread_func() {  
      mtx.lock();  
      // 访问共享数据或资源  
      mtx.unlock();  
  }
  ```

* **Condition Variables**(条件变量)

  ```c++
  #include <condition_variable>  
  std::condition_variable cv;  
  std::mutex mtx;  
  // 线程函数  
  void thread_func() {  
      std::unique_lock<std::mutex> lock(mtx);  
      cv.wait(lock, []{return !queue.empty();}); // 等待队列不为空  
      // 处理队列中的数据  
  }
  ```

* Atomic(原子操作): 不可中断的操作，多线程中最小的不可并行的操作。

  ```c++
  #include <atomic>  
  std::atomic<int> counter(0);  
  // 线程函数  
  void thread_func() {  
      counter++; // 原子操作，自增计数器  
  }
  ```


## 7. c++ malloc, free, new, delete的区别

后两个是c++的操作符。

* new可以自动计算所需分配内存大小，malloc需要手动计算

* new返回对象指针，malloc返回 void*(所以需要类型转换)

  `Task *p = (Task*)malloc(sizeof(*p)); // sizeof里也可以是Task`

* new分配失败抛出异常，malloc失败返回NULL

* new在 free store(自由存储区)上分配内存，malloc则是在堆（主要），也有在文件映射。

* delete 需要对象类型指针，free则是void*。delete void * 会报错。

## 9.c++中值类型和引用类型

数据一般在两种内存中

* **栈内存**，空间小，读写速度快，先进后出，后进先出
* **堆内存**，空间大，读写慢，没有手动删除会存储到程序结束

## 10.c++类与结构体的区别

参考：[值类型和引用类型由来及详解(C++/C#混讲) - ShawBlack - 博客园 (cnblogs.com)](https://www.cnblogs.com/ShawBlack/p/16997772.html)

先说c与c++的struct的不同

* 前者成员函数，静态成员，继承都不行，默认权限public且不能修改，不能直接初始化数据成员；

  后者则是改进了以上五个。

然后是c++中class和struct的**不同**

* **在代码使用上**，唯一的不同是 成员默认访问权限不同，class是private, struct 是public

* 类可以继承，结构体也可以(c中不行)  (此条删去)

* **更深入地**，struct是值类型，class引用类型

  在C#中值类型有：整型:Int; 长整型:long; 浮点型:float; 字符型:char; 布尔型:bool 枚举:enum 结构:struct，余下皆是引用类型。

  c++默认都是值类型，引用类型则是需要通过new在堆上申请空间并返回存储对象地址。

  栈上的数据程序员不需要手动管理，但是堆上的数据则需要手动delete.
  
  、

## 11.c++函数指针+lambda函数

### 11.1raw function pointer(c)

示例代码

```c++
void DoWork1(int a)
{
    std::cout << "Working...Value is:" << a << std::endl;
}
// - 传递函数指针作为参数
void ForEach(std::vector<int> values, void(*Print)(int))
{
    for (auto v : values)
        Print(v);
}

// ...main()
// 直接声明函数指针，取别名简化，使用auto自动推导创建
typedef void(*DoWorkFunc)(int); // 对函数指针取别名
DoWorkFunc function0 = DoWork1;
auto function1 = DoWork1; // 此时没有调用函数，而是传递函数指针
void(*function2)(int) = DoWork1; //声明变量funciton2为函数指针
function1(8);

// 函数指针传参
std::cout << "Start Print Values" << std::endl;
std::vector<int> v = { 0,3,4,1 };
ForEach(v, Print);
//...

```

### 11.2 lambda函数

示例

```c++
ForEach(v, [](int a) {std::cout << a << std::endl; });
```

## 12.c++中库的使用（静态和动态链接）

静态库是**直接被放到**exe可执行文件中的。

而动态库则是在程序运行时（runtime）动态**链接**调用的（LoadLibrary API import dll, get api,and call api)，一般需要dll和exe同目录。

通常来说静态链接会更快（可以优化的空间大），一般也会使用静态链接。

### 静态链接

静态库包含两个重要目录

* include: 包含了所有头文件
* lib：包含了函数的实现

### 动态链接

* 有的lib文件中可能会有dll文件，还有的有dll.lib文件，这个是用于指向dll的指针，就不用自己去检索函数的位置，这两个文件需要同时编译。

* 一般来说编译后会报错，因为dll需要和exe文件在同一目录，所以需要手动复制移动dll。

* 如果是静态链接，哪怕只有一个exe也可以运行。

**如果同时采用lib和dll链接，就不需要 _declspec(dllimport)来导入，因为所有的函数和变量已经在lib中了（IAT,Import Address Table)，只是如果采用了_declspec(dllimport)导入，就可以特定想要导入的函数和API，导入更快而已。**

### 如何制作自己的库

## 13.c++ namespace 

### 13.1 为什么不用using namespace std;

因为std::访问在复杂项目中容易让人辨认出函数或类型属于哪个库。



## 14.c++预编译头文件

大型项目需要使用

每一次#include<vector>都会把该文件及相关头文件合并到一起重新编译。

于是将编写预编译头文件，将这些不需要频繁（或不更改）更改的大型头文件包含起来。

这样就只用编译一次。

## 15.c++ 智能指针

智能指针的三种初始化方法

```cpp
//初始化方式1
std::shared_ptr<int> sp1(new int(123));

//初始化方式2
std::shared_ptr<int> sp2;
sp2.reset(new int(123));

//初始化方式3
std::shared_ptr<int> sp3;
sp3 = std::make_shared<int>(123);

// 不能够直接 = new()
```

## 16. c++反射

参考：[跟我学c++高级篇——反射的基本实现方式_c++反射-CSDN博客](https://blog.csdn.net/fpcc/article/details/130788656)

一般来说，基本静态反射可以通过宏和模板实现。

**要想实现反射，首先知道类的信息，这些信息包括大小，名称，变量数量、地址，函数的地址等等**



## 6. c++特性

* **std::move和std::forward**

  参考: [[C++特性\]对std::move和std::forward的理解 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/469607144)

  左值: 内存中有存储单元，左值引用用&

  右值：没有存储单元，寄存器立即数或者中间值，右值引用用&&

  ```c++
  int x = 10; // 左值
  int y = 20; // 左值
  int z = x + y; // z是左值，但是x+y却是右值
  ```

  比方说push_back(x)是将x复制一份，增加拷贝开销+重新申请空间，如果使用右值引用就能避免。

  ```c++
  v.push_back(std::move(x)); // x无论是左值还是右值都能转换成右值节省开支
  ```

  **c++折叠规则**

  - T& & -> T& （对左值引用的左值引用是左值引用）

  - T& && -> T& （对左值引用的右值引用是左值引用）

  - T&& & ->T& （对右值引用的左值引用是左值引用）

  - **T&& && ->T&& （对右值引用的右值引用是右值引用）**

    ```cpp
    // 1. std::forward是完美转发，左值转发成左值，右值转发成右值
    // 2. 没有使用std::forward会发生隐式转换，右值会变成左值
    // 3. 以下是一个lambda表达式，右值传递参数
    
    [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
    ```



* `std::bind`

  绑定器，用于将函数（可调用对象）存储在`std::function`（stl内部的仿函数）中

  ```c++
  // Application.cpp
  // 1. 将Application::Function 绑定到std::function中
  // 2. std::placeholders::_1 是一个占位符
  //    _1用于替代回调中第一个参数，简单来说就是动态传入的第一个参数的位置。_2则以此类推
  #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1) 
  ```

  其它示例

  ```c++
  void output(int x, int y)
  {
      std::cout << x << " " << y << std::endl;
  }
  // main()
  std::bind(output, 1, 2)(); // 输出 : 1 2
  std::bind(output, std::placeholders::_1, 2)(1); // 输出 : 1 2
  std::bind(output, 2, std::placeholders::_1)(1); // 输出 : 2 1
  ```

* `std::optional`

  c++17引入

  * std::optional用来包装可以为空的类型（主要），例如工厂模式返回不同类型，如果为空的话就需要一个类型判断一次，使用std::optional可以解决该问题。
    std::optional或者为空，或者包含一个有效值
  * 使用operator *，operator->，value()或者value_or()来访问有效值
  * std::optional可以隐式转换为布尔类型，因此我们可以很方便地检查有效值是否存在

* `std::filesystem`

  参考：[C++17 C17 中的新增功能std::filesystem-CSDN博客](https://blog.csdn.net/shaderdx/article/details/108235666)

  C++17的新功能，用于跨平台文件系统

  常用类

  * path 类：说白了该类只是对字符串（路径）进行一些处理，这也是文件系统的基石。

  * directory_entry 类：功如其名，文件入口，这个类才真正接触文件。 

  * directory_iterator 类：获取文件系统目录中文件的迭代器容器，其元素为 directory_entry对象（可用于遍历目录）

  * file_status 类：用于获取和修改文件（或目录）的属性（需要了解C++11的强枚举类型（即枚举类））

  常用方法

  * std::filesystem::is_directory()检查是否为目录；

  * std::filesystem::current_path()返回当前路径；

  * std::filesystem::exists()文件目录是否存在；

  * std::filesystem::create_directories()创建目录，可以连续创建多级目录；

  

  ```cpp
  // 示例
  std::filesystem::path p1 = ""
  std::filesystem::path p2 = "a/b";
  p2 /= p1;  // 错误，左边是std::filesystem::path，右边就只能是std::string类型，不然结果路径会出错。
  ```

  
