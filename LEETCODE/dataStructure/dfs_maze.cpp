#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int maze[10][10]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,0,0,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,1,1},
    {1,0,1,1,1,0,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};
int vis[10][10];
typedef  struct sq{
    int x,y;
    int dir;
    sq(){
        x=y=0;
        dir =0;
    }  //c++结构体中有类似于构造函数的初始化方法
}sqStack;


//用栈做
int main(){
    //是否撞墙越界；是否有路
    //找到终点就出栈回溯输出
    stack<sqStack> st;
    //初始化起点
    //规定0123为右下左上
    sqStack start,now,arr[100];
    sqStack *q;
    memset(vis,0,sizeof(vis));
     int find =0;
    start.x = 1;
    start.y = 1;
    start.dir = 0;
    now = start;
    st.push(now);
     vis[now.x][now.y] =1;  //标记已到过

    int m =0;
    while(!st.empty()){//栈空就退出
     cout<<st.top().x<<' '<<st.top().y<<endl;
       
    if(st.top().y == 8 && st.top().x == 8){  //找到终点就清空栈并输出
    cout<<"got it"<<endl;
        while(!st.empty()){
            cout<<st.top().x<<' '<<st.top().y<<endl;
            st.pop();
        }
        break;
    }
   
    //移动  dfs的策略是有路就走 bfs是找不到路（找完所有路）就走
    for(int i = 0; i < 4 ;i ++){ 
        switch(i){
            case 0://右
             if(st.top().y+1 <=9 && st.top().y+1 >=0 && !vis[st.top().x][st.top().y+1] && !maze[st.top().x][st.top().y+1])
           {
                now.y+=1;
                find =1;
                now.dir=0;
                vis[now.x][now.y] =1;  //标记已到过
                cout<<"right"<<endl;
            }
            break;
           
            case 1: //下
            if(st.top().x + 1 <=9 && st.top().x+1 >=0 && !vis[st.top().x+1][st.top().y] && !maze[st.top().x+1][st.top().y])
           {
                 now.x+=1;
                find =1;
                now.dir=0;
                vis[now.x][now.y] =1;  //标记已到过
            }
            break;
            case 2://左
             if(st.top().y- 1 <=9 && st.top().y-1 >=0 && !vis[st.top().x][st.top().y-1] && !maze[st.top().x][st.top().y-1])  
          {
                 now.y-=1;
                find =1;
                now.dir=0;
                vis[now.x][now.y] =1;  //标记已到过
            }
            break;
            case 3://上
          if(st.top().x - 1 <=9 && st.top().x-1 >=0 && !vis[st.top().x-1][st.top().y] && !maze[st.top().x-1][st.top().y])
          {
               now.x-=1;
                find =1;
                now.dir=0;
                vis[now.x][now.y] =1;  //标记已到过
            }
            break;
        }
    if(find) break;
    }
 
    if(find){
        st.push(now);
        find =0;
    }
    else{  //无路可走就回溯
  
    st.pop();
  
    
   
    }
   
    }

 
  



    system("pause:");
    return 0;
}