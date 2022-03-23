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

  