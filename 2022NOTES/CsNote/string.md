### string

* 注意的点

  * string只读不可以改，想改只能设为StringBuilder sb=.....改完再转回来

    ```c#
    string s1="fasd";
    s1[0]='a'; //不合法
    ```

  * GetUpperBound(0 || 1),获取二维数组的上界，一维 为(0,rank -1),二维为（0，arr[i].length-1)

###### 定义

```c#
string s = new string(char [] arr);
string s = new string('a',i);  //i个'a'的字符串
string quote = @" ""   "" ";
string txt = @"  ...
.........";
string filePath = @"C:\Users\scoleridge\Documents\";
//Output: C:\Users\scoleridge\Documents\
```



```c#
var jh =(j:"",);
Console.Writeline({jh.j})
```

###### 方法

```C#
string s3 = "Visual C# Express";//子串
System.Console.WriteLine(s3.Substring(7, 2));//不声明长度默认为全输出
// Output: "C#"


System.Console.WriteLine(s3.Replace("C#", "Basic")); //字符串代替
// Output: "Visual Basic Express"


// Index values are zero-based
int index = s3.IndexOf("C"，StartIndex);//可以通过改变StartIndex来连续查找
//如果加上end 参数表示 end个字符
// index = 7  pointer will start from StartIndex and stop in "c"
int  index =s3.LastIndexOf('\\');// 寻找最后一个，注意转义


//split   c#字符串分块
char[] delimiterChars = { ' ', ',', '.', ':', '\t' };
string text = "one\ttwo three:four,five six seven";
System.Console.WriteLine($"Original text: '{text}'");
//    split(params)  params can be arr of the split word you don't want
string[] words = text.Split(delimiterChars);
System.Console.WriteLine($"{words.Length} words in text:");

foreach (var word in words)
{
    System.Console.WriteLine($"<{word}>");
}//output : one two three four...(splited by '\n')
```

三种空格unicode(\u00A0,\u0020,\u3000)表示的区别

[三种空格unicode(\u00A0,\u0020,\u3000)表示的区别 - 简书 (jianshu.com)](https://www.jianshu.com/p/4317e3749a13)



###### 有关更改string

```c#
string question = "hOW DOES mICROSOFT wORD DEAL WITH THE cAPS lOCK KEY?";
System.Text.StringBuilder sb = new System.Text.StringBuilder(question);

for (int j = 0; j < sb.Length; j++)
{
    if (System.Char.IsLower(sb[j]) == true)
        sb[j] = System.Char.ToUpper(sb[j]);
    else if (System.Char.IsUpper(sb[j]) == true)
        sb[j] = System.Char.ToLower(sb[j]);
}
// Store the new string.
string corrected = sb.ToString();
System.Console.WriteLine(corrected);
// Output: How does Microsoft Word deal with the Caps Lock key?
```



[字符串 - C# 编程指南 | Microsoft Docs](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/)