IOC 和DI

1.ioc

inversion of control

　**IoC很好的体现了面向对象设计法则之一—— 好莱坞法则：“别找我们，我们找你”；即由IoC容器帮对象找相应的依赖对象并注入，而不是由对象主动去找。**

​        ●谁依赖于谁：当然是**应用程序依赖于IoC容器**；

　　●为什么需要依赖：**应用程序需要IoC容器来提供对象需要的外部资源**；

　　●谁注入谁：很明显是**IoC容器注入应用程序某个对象，应用程序依赖的对象**；

　　●注入了什么：就是**注入某个对象所需要的外部资源（包括对象、资源、常量数据）**。



以往是对象需要什么，就调用什么，但是ioc是，容器需要什么对象，就把依赖注入对应的对象； ioc是一家公司，工厂，创建对象（招人），需要你做什么，给你注入相关资源、指令、权限；同时为你分配和其他对象的关系。主导权的inversion.

2.DI  Dependency Injection 依赖注入

```c#
//传统方法
public AccountController(){
	_loginService = new EFLoginService();  //创建对象
}

//依赖注入
public AccountController(ILoginService<ApplicationUser> loginService){
	_loginService = loginService;
}
```

依赖注册分为三个阶段（特例：ILoggerService已经定义并注册...还有其他....)

1.定义服务

2.注册服务  在 Startup.cs 中注册上下文对象（Context)和连接字符串

3.注入服务  

DI核心组件：IServiceCollection,负责服务注册，IServiceProvider负责提供服务实例（GetService())

addtransient 瞬时,addscoped,addsingleton 单例；三种生命周期