#### 数据处理

##### 基本统计分析

* `df.age.describe()`

  ```python
  print(df.rating.describe());//对某一列进行统计分析
  count
  mean
  std
  min
  25%
  50%
  75%
  ```

* 其他常用统计函数

  ```python
  df.size//无括号，统计长度
  df.sum()
  df.mean()
  df.var()
  df.std()
  ```

##### 分组分析

* `df.groupby(by=['',])[''].agg({'列名':numpy.sum,....})`

  其中`.agg({})`里面是一个字典类型，列名配函数

  通过单个或多个列来分组，比如通过班级和性别来分组，谁在前面就用谁做”主键”

  > 同一班级，分男女,男女各项数据又分别列出

##### 分布分析

