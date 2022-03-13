#### C++ vector

```c++
vector<T> v;
v.empty();

//删除  不会减小容量 size变
vector<T>:: iterator it; //迭代器删除
v.erase(pos);    //it
v.erase(begin(),end());
v.remove(ElemType); //  不会改变size
v.clear();


```

