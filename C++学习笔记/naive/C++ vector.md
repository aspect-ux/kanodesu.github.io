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

v.erase(pos);    //it，如果是it，it会变成野指针
v.erase(begin(),end());
//stl是通过把vector中要删除位置后面的所有数据移动到要删除的位置，然后删除最后一个位置的数据来实现的

v.remove(ElemType); //  不会改变size
v.remove(v.begin(),v.end(),value);
//删除容器中所有和指定元素值相等的元素，并返回指向最后一个元素下一个位置的迭代器。值得一提的是，调用该函数不会改变容器的大小和容量。


v.clear();			//清空


//交换两个容器的全部数据
v1.swap(v2);
//单纯交换
swap(v[i],v[j]);
    
//排序
sort(v.begin(),v.end());
sort(v.rbegin(),v.rend());


//插入
v.insert(v.begin()+n,value);
//将一个vector接到另一个vector后面
std::vector<int> src;
std::vector<int> dest;
dest.insert(dest.end(), src.begin(), src.end());


//查找
#include<algorithm>
vector<int> v;
v.find(v.begin(),v.end(),value);

//获取最大值
int a = *max_element(v.begin(),v.end());

```

