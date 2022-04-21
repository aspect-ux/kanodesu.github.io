##### EF框架的使用

*  dataGridView1.DataSource = dbContext.Set<test>().ToList();
*  MyDbContest dbContext = new MyDbContest();
*  新建md5加密
   * 在解决方案文件夹中创建lib文件夹
   * 进入packages，EntityFramework.6.2.0，lib；
   * 将4.5中的文件复制到新建的lib中
   * 在本解决方案下添加引用，浏览，选择lib（new)中的两个dll
   * 。。。
   * 新建类库，拷贝文件，删除class1.cs
   * 在所需项目中引用，添加引用，项目，选择类库

