#include<iostream>
#include<string>
using namespace std;

//string maze[5]={"....S*",".***..",".*..*.","*.***.",".T...."};
 char maze[100][100];
        //c++的话string数组替代二维数组也可
 int vis[100][100]; //标记位，是否为空
 int n, m;
 int x, y; //未赋值的局部变量不能传入函数
string v[5]={"....S*",".***..",".*..*.","*.***.",".T...."};

bool inThe(int x, int y)
{
    return x >= 0 && x <= 5 && y >= 0 && y <= 6;

}
/*
....S*
.***..
.*..*.
*.***.
.T....
*/

bool dfs(int x, int y)
{
    //出口
    if (maze[x][y] == 'T') {
        return true;
    }

    vis[x][y] = 1; //初始化标记起点，假设s在左边，逆时针开始(常见）
    maze[x][y] = 'm';

    //x,y是起始点，
    int tx = x;  //初始化
    int ty = y - 1;

    //不是墙壁且没有出界并且没有经过过
    //左
    cout<<tx<<ty<<endl;
    if ( inThe(tx, ty) && !(vis[tx][ty])&& maze[tx][ty] != '*')
    {
        if(dfs(tx, ty))
        {
            return true;
        }

    }
    //下
    tx = x + 1;
    ty = y ;
    if (inThe(tx, ty) && maze[tx][ty] != '*' &&  !(vis[tx][ty]))
    {
        if (dfs(tx, ty))
        {
            return true;
        }

    }
    //右
    tx = x ;
    ty = y + 1;
    if (inThe(tx, ty) && maze[tx][ty] != '*' &&  !(vis[tx][ty]))
    {
        if (dfs(tx, ty))
        {
            return true;
        }

    }
    //上
    tx = x;
    ty= y - 1;
     if (inThe(tx, ty) && maze[tx][ty] != '*' &&  !(vis[tx][ty]))
    {
        if (dfs(tx, ty))
        {
            return true;
        }

    }

    //
    vis[tx][ty] = 0;     //如果只要一个结果，不恢复也行
    maze[x][y] = '.'; //一定恢复
    return false;


    //一般用dir[][]来存移动方向，这样就可以不写四个if



}
int main(){
       /*    cout<<"Input n:";
            cin>>n;
           cout<<"Input m:";
            cin>>m;
            cout<<"Input maze:";
               for (int i = 0; i < n; i++)
            {
                 cin>>v[i]; 
                
            }*/
            for (int i = 0;i < 5; i++)
            {
                for(int j = 0;j < 6; j++)
                {
                    maze[i][j] = v[i][j];
                    
                }
            }


            //找到起点，将x,y 的坐标设为S
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (maze[i][j] == 'S')
                    {
                        x = i;
                        y = j;
                       
                    }
                }
            }
           /*  x=0;
            y=4; */
            cout<<x<<y<<endl;
           

            //设置
            if(dfs(x, y))
            {
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        v[i][j]=maze[i][j];

                    }
                }
                for (int i = 0; i < 5; i++)
                {
                    for(int j=0; j < 6; j++)
                    {
                        cout<<maze[i][j];
                    } 
                    cout<<endl;
                }
            }
            else
            {
               cout<<"no way!";
            }     
    system("pause:");

    return 0;
}

 


