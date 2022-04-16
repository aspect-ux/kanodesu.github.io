#### VS连接Sql Server

* vs添加数据源，选择连接sql server登录，别选错了

* 代码环节

  * 连接字符串`conStr`,可以在高级中选择复制

  * 创建连接对象

    ```c#
    using (SqlConnection conn = new SqlConnection(connStr))
    {
        // 3.编写sql语句
        string sql = "select * from test";
        // 4.创建执行sql语句的命令对象
        SqlCommand cmd = new SqlCommand(sql, conn);
        // 5.打开数据库连接
        conn.Open();
        // 6.执行sql语句
        //cmd.ExecuteNonQuery();
        //cmd.ExecuteReader();   
        //cmd.ExecuteScalar();
        SqlDataReader reader = cmd.ExecuteReader();
        if (reader.HasRows)
        {
            while (reader.Read())
            {
                Console.WriteLine(reader["sno"] + " "+reader["sname"]);
    
            }
        }
        else
        {
            Console.WriteLine("表中没有数据。");
        }
    }
    Console.ReadKey();
    ```

    * 使用控件dataGridView来使得数据显示在窗体中