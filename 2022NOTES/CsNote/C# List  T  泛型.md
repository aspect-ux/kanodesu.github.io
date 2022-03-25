#### C#  泛型

**list集合**

```c#
List<T> list1 =new List<T>();

//用list集合储存奇数和偶数数组

 string msg = "1 2 3 4 5 6 7 8 9 10";
            List<string> evenlist = new List<string>();
            List<string> oddlist = new List<string>();
            string []parts =msg.Split(new char[] { });
            foreach(string part in parts)
            {
                if(Convert.ToInt32(part)%2 != 0)
                {
                    Console.Write(part);
                    Console.Write(' ');
                }       
            }
            foreach (string part in parts)
            {
                if (Convert.ToInt32(part) % 2 == 0)
                {
                    Console.Write(part+' ');

                }

            }
```



**键值对集合**

```c#
Dictionary<int, string> dic = new Dictionary<int, string>();

string msg = "0零 1壹 2贰 3叁 4肆 5伍 6陆 7柒 8捌 9玖";
string []parts = msg.Split(' ');
foreach(string part in parts)
{
    dic[part[0]] = part[1].ToString();
}
string input = Console.ReadLine();
foreach (var item in input)
{
    Console.Write(dic[Convert.ToInt32(item)]);
}
```

* ```c#
  using System;
  using System.Collections.Generic;
  using System.Linq;
  using System.Text;
  using System.Threading.Tasks;
  
  namespace _04
  {
      internal class Program
      {
          static void Main(string[] args)
          {
              #region 4.计算字符串中每种字母出现的次数。"Hello! Welcome to China!  How are you ?  Fine!  And you?"（扩展：不区分大小写）(提示：Dictionary<K,V>)
  
              #endregion
  
              Dictionary<char, int> dic = new Dictionary<char, int>();
              string msg = "Hello! Welcome to China!  How are you ?  Fine!  And you?";
              char[] a = msg.ToCharArray();
          //    for (int i = 0; i < a.Length; i++)
          //    {
          //        char.isLetter()
          //是字母且原键值对集合中没有
          //        if (Char.IsLetter(a[i]))
          //        {
          //            if (!dic.ContainsKey(a[i]))
          //                dic.Add(a[i], 1);
          //            else
          //            {
          //                dic[a[i]]++;
          //            }
  
          //            dic[a[i]]++;//int 类型默认为0
          //        }
  
          //    }
  
              //不区分大小写 msg.Upper()
              char[] b = msg.ToUpper().ToCharArray();
              for (int i = 0; i < b.Length; i++)
              {
                  //char.isLetter()
                  //是字母且原键值对集合中没有
                  if (Char.IsLetter(b[i]))
                  {
                      if (!dic.ContainsKey(b[i]))
                          dic.Add(b[i], 1);
                      else
                      {
                          dic[b[i]]++;
                      }
  
                      // dic[b[i]]++;//int 类型默认为0
                  }
  
              }
              foreach (var c in dic)
              {
                  Console.WriteLine(c);
              }
             Console.ReadKey();
          }
      }
  }
  
  ```

  

* ```c#
  using System;
  using System.Collections.Generic;
  using System.Linq;
  using System.Text;
  using System.Threading.Tasks;
  
  namespace _05
  {
      internal class Program
      {
          static void Main(string[] args)
          {
              #region 5.设计方法实现，将中文日期转换为数字格式的日期。比如：“二零二二年三月十五日”应转换为“2022-3-15”。（"零0 一1 二2 三3 四4 五5 六6 七7 八8 九9"， 难点：“十”的转换）
  
              #endregion
              string msg = "零0 一1 二2 三3 四4 五5 六6 七7 八8 九9";
              string input= "二零二二年三月十日";
              Dictionary<char, char> dic = new Dictionary<char, char>();
              string [] parts=msg.Split(' ');
              string output = "";
              
              foreach (string part in parts)
              {
                  dic[part[0]] = part[1];
              }
              //十号-10，二十一号-21，二十号-20,十一号
              for(int i = 0;i<input.Length; i++)
              {
                  if(input[i] == '十')
                  {
                      if (dic.ContainsKey(input[i - 1])&&dic.ContainsKey(input[i+1])) //如果2
                      {
                          ;
  
                      }
                      else if(!dic.ContainsKey(input[i - 1]) && !dic.ContainsKey(input[i + 1])) //如果1
                      {
                          
                          output += "10";
                      }
                      else if(dic.ContainsKey(input[i - 1]) && !dic.ContainsKey(input[i + 1])) //如果3
                      {
                          output += "0";
  
                      }
                      else{//如果4
  
                          output += "1";
                      }
  
                  }
                  else if(dic.ContainsKey(input[i]))
                  {
                      output+=dic[input[i]];
                  }
                  else
                  {
                      output += "-";
  
                  }
  
  
              }
              Console.WriteLine(output.Substring(0,output.Length-1));
              Console.ReadKey();
  
  
          }
      }
  }
  
  ```

  
