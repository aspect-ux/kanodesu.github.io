# 类自带属性

六大默认属性，三函数，三运算符

- 默认构造函数
- 析构函数
- 拷贝构造函数 A("");
- 赋值运算符  = 
- 取址运算符 &
- const取址运算符 const &



## 取址运算符重载

```c++
class Date
{
public :
    Date* operator&()
    {
        return this ;
    }
    const Date* operator&()const // const取址重载
    {
        return this ;
    }
private :
	int _year ; // 年
	int _month ; // 月 
	int _day ; // 日
};
```



## 构造函数与析构函数

### 析构函数什么时候被调用

1. **生命周期**：对象**生命周期结束**，会调用析构函数。

2. **delete**：调用delete，会删除指针类对象。

3. **包含关系**：对象Dog是对象Person的成员，Person的析构函数被调用时，对象Dog的析构函数也被调用。

4. **继承关系**：当Person是Student的父类，调用Student的析构函数，会调用Person的析构函数。

# 

