##### C++   string

* string 函数

```c++
//增
string s;
string s1;
s.insert(5,s1) //在第六个元素出插入s1 ,但这只能插入字符串
   s.insert(5,1,c);//这样就可以插入字符

//删
s.erase(6);    //从第七个元素开始，默认全删
s.erase(6,3);   //从第七个元素开始，删三个
    
//子串
s.substr(6,6);  //从第七个元素，截取六个
s.substr(6);//默认到结尾
s.find(s1,5);   //从第六个元素开始寻找子字符串，返回index
                //只要每次更新StartIndex,就可以达到连续寻找
                //如果没找到，就会返回最大值2的32次方
s.rfind(s1,5)   //找到第六个元素还没找到就返回最大值
    
//常用函数
s.length();     //区别vector 返回长度
reverse(s.begin(),s.end()); //逆转
```

