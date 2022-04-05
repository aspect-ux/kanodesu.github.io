#### Series DataFrame

##### Series

```python
#位置是从0开始....
#索引是人为定义....
#值  无非就这三要素

from pandas import Series
#创
s =Series([],index==[])#不设置index默认012...
s = Series({}) #字典也可
#访问
s[0]
s['']#设置了index也可
#增
s.append(Series([],index=[]))


#查
2 in s.values#返回布尔值
s[1:3]#位置切片  其实就是默认的索引，第二行和第三行两行
s['first':'third'] #索引切片  区别就是first-third都输出共三行
s[[1,3,2]]#根据位置  s[1]是第二行name lisi,如果s[[1,3,2]]无非就是换成了列表
s.index[s.values='a']#通过值来找索引，s.index[0]是通过位置找索引

#删
x.drop('first')#根据索引来删
x.drop(x.index[0])#根据位置来删，通过位置定位索引
x[x.values!=2]#直接根据值来删除

#改
#改索引
x.index=[]
x.sort_index()#按索引排序自动
x.reindex([''])#手动
#改


```

##### `DataFrame`

```python
#索引+位置
#另外加上一个标签（列名）
#
#创
df = DataFrame({'age':Series([]),'name':Series([])},index=[])
#这里的index是行index，就是Series中一个字段的index

#增
df['']=[]#直接加一列
df.loc[len(df)]
#loc和iloc的区别  查
df.loc[n1:n2,m1:m2]#loc是根据标签，所见即所得
df.iloc[n1:n2,m1:m2]#iloc是根据位置左闭右开
df['a']#一列的值
df[1:2]#正常切片
df.at[0,'name']#交叉值
df.at['','']#标签交索引

#增加行和列
#增加列 df['']=[]
#增加行 df.loc[len(df)]=[]  #效率低
df.append(df0,ignore_index=True)#ignore_index使得可以重新分配索引
pandas.concat([df,df0])#将多个dataframe连接起来，也可以实现增加行

#改
#修改列名和行索引
df.columns=['']
df.index=['']

#删除
df.drop(1)#行索引
df.drop('')#列名 axis =1
del df['']#用del删除一列
```

