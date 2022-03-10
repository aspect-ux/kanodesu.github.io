### string

###### 定义

```c#
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
string s3 = "Visual C# Express";
System.Console.WriteLine(s3.Substring(7, 2));
// Output: "C#"


System.Console.WriteLine(s3.Replace("C#", "Basic"));
// Output: "Visual Basic Express"


// Index values are zero-based
int index = s3.IndexOf("C"，StartIndex);
// index = 7  pointer will start from StartIndex and stop in "c"


//split
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