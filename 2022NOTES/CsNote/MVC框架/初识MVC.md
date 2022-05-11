#### 初识MVC

###### 什么是MVC架构设计模式

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





