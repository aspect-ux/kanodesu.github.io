#### STL特殊函数

* **全排列**

  `next_permuteation()`代码如下

  ` bool next_permutation(iterator start,iterator end)`

```c++
#include<algorithm>
do{

}while(next_permutation(arr,arr+n)); //vector,string,[]
//前提是vector中的数据是有序的
```

* 二分查找

  ```c++
  lowerbound(v.begin(),v.end(),value);//返回不小于value的第一个数
  //也要求先排序才能用不然结果不对
  ```

  
