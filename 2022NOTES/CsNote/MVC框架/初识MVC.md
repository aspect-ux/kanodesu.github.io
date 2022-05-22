#### 初识MVC

###### 什么是MVC架构设计模式

1.视图(View)代表用户交互界面，对于Web应用来说，可以概括为HTML界面

 2.模型(Model)：就是业务流程/状态的处理以及业务规则的制定。

业务模型的设计可以说是MVC最主要的核心。目前流行的EJB模型就是一个典型的应用例子，它从应用技术实现的角度对模型做了进一步的划分，以便充分利用现有的组件，但它不能作为应用设计模型的框架。它仅仅告诉你按这种模型设计就可以利用某些技术组件，从而减少了技术上的困难。

业务模型还有一个很重要的模型那就是数据模型。数据模型主要指实体对象的数据 保存（持续化）。比如将一张订单保存到数据库，从数据库获取订单。我们可以将这个模型单独列出，所有有关数据库的操作只限制在该模型中。

3.控制(Controller)可以理解为从用户接收请求, 将模型与视图匹配在一起，共同完成用户的请求

----

 1）最上面的一层，是直接面向最终用户的"视图层"（View）。它是提供给用户的操作界面，是程序的外壳。
   2）最底下的一层，是核心的"数据层"（Model），也就是程序需要操作的数据或信息。
   3）中间的一层，就是"控制层"（Controller），它负责根据用户从"视图层"输入的指令，选取"数据层"中的数据，然后对其进行相应的操作，产生最终结果。
————————————————
版权声明：本文为CSDN博主「皓月星辰_w」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_21225505/article/details/81666986

* Controller 和  View之间如何交互
  - Html页面代码
  - javascript代码
  - 后台action（在该行右键可以跳转添加视图）

###### 代码



###### 通过Controller 向View传输数据

* Controller

  ```c#
  //1
  public ViewResult TransData()
          { 
              ViewBag.TGB = "大米时代";
              return View();
          }
  ```

  ```c#
  //2
  public ViewResult TransData()
          { 
              ViewData["hengshuiTGB"] = "衡水大米时代";
              return View();
          }
  //3
  public ViewResult TransData()
          { 
             Models.Models modelClass = new Models.Models() { cname="广州大米时代"};
   
   
              ViewData.Model = modelClass;
              return View();
          }
  ```

  

* View

  ```c#
  //1
  <head>
      <meta name="viewport" content="width=device-width" />
      <title>TransData</title>
  </head>
  <body>
      <div>
          @ViewBag.TGB <br />
      </div>
  </body>
      
      
  //2
  
  <head>
      <meta name="viewport" content="width=device-width" />
      <title>TransData</title>
  </head>
  <body>
      <div>
         @ViewData["hengshuiTGB"] <br />
      </div>
  </body>
      
  //3
  
  <head>
      <meta name="viewport" content="width=device-width" />
      <title>TransData</title>
  </head>
  <body>
      <div>
         @Model.cname <br />
         @ViewData.Model.cname     
      </div>
  </body>
  ```

**创建强类型view以后，View的第一行代码如下所示：
@model _01FirstMVC.Models.Models，这段代码代码了这个View使用的Model为“_01FirstMVC.Models.Models”然后Model.就能有智能提示啦，会显示Model中定义的所有属性。**

##### 通过View向Controller传输数据





