using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//抽象dfs    n个数其中k个数总和为sum，求这些数的组合种类

//？？？？？？？？？没搞懂.......基线，选项--------二叉树模型
//第二种方法，从第一个元素开始，选择第一个，选择第二个，循环，取消选择...
//这样显然每种方法都多计算了A(3,2)次  5 3 9 ->12/6=2......

namespace _02
{
    internal class Program
    {
        public static int[] a =  {1,2,3,4,5}; //存储数据
        public static int n, k, sum, ans;
        static void Main(string[] args)
        {
            //n=int.Parse(Console.ReadLine());
            //k= int.Parse(Console.ReadLine());
            //sum= int.Parse(Console.ReadLine());
            n = 5;
            k = 3;
            sum = 9;
            ans = 0;
            dfs(0,0,0);
            Console.WriteLine(ans);
            Console.ReadKey();


        }
        // cnt 为已选几个数，s为当前总和  (进行时）
        private static void dfs(int i,int cnt,int s)
        {
            if (i == n)
            {
                if (cnt == k && s == sum)
                {
                    ans++;

                }
                return;

            }
     
            dfs(i + 1, cnt, s);
            dfs(i + 1, cnt + 1, s + a[i]);
            
            
        }
    }
    
}
