#### 类，接口，委托（class,interface,Delegate)

##### Part1-Class

```c#
namespace Windows第二次  //继承，虚函数（virtual+override)
{                       //abstract void fun() +abstract class()+override

    class Bird
    {
        public virtual void fun()
        {
            Console.WriteLine("1");
        }
    }
    //abstract class Bird{};
    class Magpie : Bird
    {
        public override void fun()
        {
            Console.Write("magpie");
        }
    }
    class Penguin : Bird
    {
        public override void fun()
        {
            Console.Write("penguin");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Bird[] bird = new Bird[]
            {
                new Bird(),
                new Magpie(),
                new Penguin()

            };
            foreach(var b in bird)
            {
                b.fun();
            }
            Console.ReadKey();
        }
    }
}

```

##### Part2-Class

```c#
using System;
using System.Collections.Generic;//注意interface 命名
using System.Linq;               //以I开头able结尾
using System.Text;               //类似于抽象类，不过不用关键字和public void
using System.Threading.Tasks;    //用的时候当成抽象类用

namespace Windows第二次
{
    abstract class Bird
    {
        public abstract void fun();
    }

    interface Iflyable
    {
        void fun1();
    }
    class Magpie : Bird,Iflyable
    {
        public override void  fun()
        {
            Console.Write("magpie");
        }
        public void fun1()
        {
            Console.WriteLine("interface seigo");
        }

       
    }
    class  Penguin : Bird
    {
        public override void fun()
        {
            Console.Write("penguin");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
           /* Bird[] bird = new Bird[]
            {
                
                new Magpie(),
                new Penguin()

            };*/
            Iflyable [] bird = new Iflyable[]
           {

                new Magpie(),
               

           };
            foreach (var b in bird)
            {
                b.fun1();
            }
            Console.ReadKey();
        }
    }
}

```



##### Part3-Class

```c#
//委托   1.
 static void fun(int a)
        {
            Console.WriteLine("1");
        }
 Action<int> action = new Action<int>(fun);

//2.
static int fun(int a)
{
    Console.WriteLine("1");
    return 1;
}
 Func<int, int> func = new Func<int, int>(fun);

```



#### End

* class 单继承
* interface 用于多个子类特殊功能。由于不是所有子类都需要这个功能，就不适合改父类。
* Delegate,lambda函数，传入参数为函数，也可以添加功能，多用action,func,也可以自己定义