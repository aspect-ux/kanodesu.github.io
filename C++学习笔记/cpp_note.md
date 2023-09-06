# cpp note day day dream
## 1. c++ 模板编程(泛编程)
### 1.1 自动推导
####**auto**
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
* 