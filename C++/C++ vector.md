#### C++ vector

```c++
//初始化
vector<T> v(capacity,initial);
//在空容器的基础上分配空间
v.reserve(20); //v.capacity =20
//用数组来初始化
int arr[]={1,2,3};
vector<int> v(arr,arr+2);
vector<int> v1(v.begin(),v.begin()+2);
//判空
v.empty();


//返回元素个数
v.size();

//删除  不会减小容量 size变
vector<T>:: iterator it; //迭代器删除
v.erase(pos);    //it
v.erase(begin(),end());
v.remove(ElemType); //  不会改变size
v.clear();			//清空


//交换两个容器的全部数据
v1.swap(v2)
    
//排序
sort(v.begin(),v.end());

```

