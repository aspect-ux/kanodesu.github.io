IOC 和DI

1.DI  Dependency Injection 依赖注入

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