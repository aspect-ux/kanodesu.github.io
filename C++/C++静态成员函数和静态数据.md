### ***C++静态成员函数和静态数据***

* **静态成员函数是属于类的，只能访问静态数据成员与静态函数**

* **（对象、函数）调用谁，this指针就指向谁，但是静态成员函数没有指针**

* **虽然静态函数调用有局限，但非静态成员调用静态却没有，一般还是静态调用静态**

  

```c++
/*c++程序分为“main.cpp","student.h","student.cpp",其中头文件用来储存函数，就像是一个“方法库”，用#include"student.h",调用，不用编译，"student.cpp"写类*/


class Test{
    
    //private:     default:private
    /*generally,private for datatype,public for func,for data need be protected,but func need be          	invoked(evoked) by subject*/
    	static int a;
    public:
    	static void display();
};

Test::static int a=1;   //类外初始化
 int main()
{
    Test::display(); //静态成员函数由类名直接调用
    
    
    
    return 0;
}
```

