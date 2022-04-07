#### Python连接MySql

* 连接（mysql需要connector)

  ```python
  import pymysql
  #连接数据库
  conn=pymysql.connect(host = '127.0.0.1' # 连接名称，默认127.0.0.1
  ,user = 'root' # 用户名
  ,passwd='3712466' # 密码               #可改
  ,port= 3306 # 端口，默认为3306
  ,db='test' # 数据库名称                 #可改
  ,charset='utf8' # 字符编码
  )
  cur = conn.cursor() # 生成游标对象
  sql="select * from `student` " # SQL语句
  cur.execute(sql) # 执行SQL语句
  data = cur.fetchall() # 通过fetchall方法获得数据
  for i in data[:2]: # 打印输出前2条数据
  	print (i)
  cur.close() # 关闭游标
  conn.close() # 关闭连接
  ```

* 基本框架

  ```python
  config = {
      'host': '127.0.0.1',
      'port': 3306,
      'user': 'root',
      'password': '3712466',
      'database': 'linnodata',
      'charset': 'utf8mb4',
      'cursorclass': pymysql.cursors.Cursor,
  }
  
  #basic class of execution of table
  class TBadmin:
      def __init__(self,sql):
          try:
              self.conn = pymysql.connect(**config)
              self.cur = self.conn.cursor()
              # 查询指定数据表table_stu是否存在.不存在，则创建.
          
              self.cur.execute(sql)
              self.conn.commit()
              print("创建数据表成功！")
          except Exception as e:
              print("创建数据表失败:", e)
    #添加记录.parameter 参数
      def add_record(self,sql,param):
          try:
              self.cur.executemany(sql,param) 	#添加多条记录.
              self.conn.commit()
          except Exception as e:
              raise e
    #查询记录.
      def select_record(self,sql,param):
          try:
              self.cur.execute(sql,param)
              return self.cur
          except Exception as e:
              raise e
    #更新记录.
      def update_record(self,sql,param):
          try:
              self.cur.execute(sql,param)
              self.conn.commit()
          except Exception as e:
              raise e
    #删除记录.
      def delete_record(self,sql,param):
          try:
              self.cur.execute(sql,param)
              self.conn.commit()
          except Exception as e:
              raise e
    
  ```

  

​		

