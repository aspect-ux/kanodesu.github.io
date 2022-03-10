### Sequel

* sum() over()分组求和

  first_value() over()求分组第一条

  last_value() over()求分组最后一条

  其中用row_number() over()取编号第一条的也可以实现first_value() over()的效果

  ```sql
  first_value() over(partition by ... order by ...) rk 排序
  ```

  

