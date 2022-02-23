using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


// dfs深度优先搜索
   //s**.
   // ....
   // ***T
   //s为起点，t为终点，.表示平地，* 表示墙壁，只能走上下左右相邻位置
   //且每一个点只到一次，
   //求一种解法（口袋妖怪....)

   //三个判断，下一步在不在区域内，是否为墙壁，以及是否被标记过（即走过）
   //一条路走到黑，不行就回溯


   //c#的string是只读的，用stringbuilder 可进行多次改变
#region
    
#endregion

namespace _01
{
    internal class Program
    {
        public static char[,] maze = new char[100, 100];
        //c++的话string数组替代二维数组也可
        public static int[,] vis = new int[100, 100]; //标记位，是否为空

        public static int n, m;
        public static int x, y; //未赋值的局部变量不能传入函数

        public static String[] v = new String[100];
        static void Main(string[] args)
        {
            //输入迷宫地图


            
            Console.WriteLine("Input n:");
            n = int.Parse(Console.ReadLine());
            Console.WriteLine("Input m:");
            m = int.Parse(Console.ReadLine());
            Console.WriteLine("Input maze:");
            for (int i = 0; i < n; i++)
            {
                 v[i] = Console.ReadLine();
                
            }
            for (int i = 0;i < n; i++)
            {
                for(int j = 0;j < m; j++)
                {
                    maze[i, j] = Convert.ToChar(v[i][j]);
                    
                }
            }


            //找到起点，将x,y 的坐标设为S
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (maze[i, j] == 'S')
                    {
                        x = i;
                        y = j;
                    }
                }
            }

            //设置
            if(dfs(x, y))
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        v[i][j]=(maze[i,j]);

                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for(int j=0; j < m; j++)
                    {
                        Console.WriteLine(maze[i, j]);
                    } 
                    Console.WriteLine("\n");
                }
            }
            else
            {
                Console.WriteLine("no way!");
            }
              


        }

        private static bool dfs(int x, int y)
        {
            //出口
            if (maze[x, y] == 'T') {
                return true;
            }

            vis[x, y] = 1; //初始化标记起点，假设s在左边，逆时针开始(常见）
            maze[x, y] = 'm';

            //x,y是起始点，
            int tx=x-1;  //初始化
            int ty = y;

            //不是墙壁且没有出界并且没有经过过
            //左
            if ( inThe(tx, ty) && !Convert.ToBoolean(vis[tx,ty])&& maze[tx, ty] != '*')
            {
               if(dfs(tx, ty))
                {
                    return true;
                }

            }
            //下
            tx = x;
            ty = y + 1;
            if (maze[tx, ty] != '*' && inThe(tx, ty) && Convert.ToBoolean(vis[tx, ty]))
            {
                if (dfs(tx, ty))
                {
                    return true;
                }

            }
            //右
            tx = x + 1;
            ty = y;
            if (maze[tx, ty] != '*' && inThe(tx, ty) && Convert.ToBoolean(vis[tx, ty]))
            {
                if (dfs(tx, ty))
                {
                    return true;
                }

            }
            //上
            tx = x;
            ty= y - 1;
            if (maze[tx, ty] != '*' && inThe(tx, ty) && Convert.ToBoolean(vis[tx, ty]))
            {
                if (dfs(tx, ty))
                {
                    return true;
                }

            }

            //
            vis[tx, ty] = 0;     //如果只要一个结果，不恢复也行
            maze[tx, ty] = '.'; //一定恢复
            return false;


            //一般用dir[][]来存移动方向，这样就可以不写四个if



        }

        private static bool inThe(int x, int y)
        {
            return x >= 0 && x <= m && y >= 0 && y <= n;

        }

        
           
            
    }
}
