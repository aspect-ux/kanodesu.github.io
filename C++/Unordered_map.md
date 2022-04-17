##### Unordered_map

* *Launch*

  [C++ STL unordered_map容器用法详解 (biancheng.net)](http://c.biancheng.net/view/7231.html)

  ```c++
  #include<iostream>
  #include<string>
  #include<unordered_map>
  using namespace std;
  
  unordered_map<string,int> hash;
  // use {{}} to create key and value
  unordered_map<int,char> arr = {{0,'1'},
  {1,'2'},{2,'3'},{3,'4'},{4,'5'},{5,'6'},{6,'7'},{7,'8'},{8,'9'}}; 
  unordered_map<string,int>::iterator it;
  cout<<it->first<<it->second;
  ```

* `insert`

  ```c++
  map.insert({key:value});
  ```

* `find`

  ```c++
  if(hash.find(index)!= hash.end()) //找到
  ```

* 遍历

  * 迭代器遍历
  * `for(auto c : hash){}`
  * `for(auto & [x,y] :hash){}`
  
* `erase`

  * `hash.erase(it.begin());`
  * `hash.erase(it.begin(),it.begin()+2)`左开右闭
  * 如果想定值删除`hash.erase(key)`
  * 哈希表是无序的，所以迭代器删除似乎不能定向删除