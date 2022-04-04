#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//队列实现
typedef struct sq{
    int x;
    int y;
    sq(){
        x =0;
        y=0;

    }

}sqQueue;
int maze[10][10]={
    {1,1,1,1,1,1,1,1,1,1},     // 标号公式为 j+i*10
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,1,0,0,0,1,1,1},
    {1,0,0,0,0,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,1},
    {1,0,1,0,0,0,1,0,1,1},
    {1,0,1,1,1,1,1,0,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};
int vis[10][10];
int main(){
    queue<sqQueue> qu;
    sqQueue s;
    int cnt = 0,flag = 0,c=0,flag1=0; //用flag标记每一层有多少个
    memset(vis,0,sizeof(vis));
    s.x = 1;
    s.y = 1;
    vis[1][1] =1;   //初始化
    qu.push(s);

    while(!qu.empty()){    //寻找最优解  可以给每一个元素一个标号，将出队元素再入另一个队，从队尾开始遍历就可以找到最短路径
        if(qu.back().x == 8 && qu.back().y == 8){//不这样做单纯数个数还是有点麻烦
            break;
        }

      for(int i = 0;i < 4; i++){
            switch(i){
                case 0:  //右
                if(qu.front().x >= 0 && qu.front().x <= 9 && qu.front().y + 1 <= 9 && qu.front().y + 1 >=0
                && !vis[qu.front().x][qu.front().y+1] && !maze[qu.front().x][qu.front().y+1]){
                    vis[qu.front().x][qu.front().y+1] = 1;
                    sqQueue tmp;
                    tmp.x = qu.front().x;
                    tmp.y = qu.front().y + 1;
                    qu.push(tmp); //入队
                    flag ++;
               //    cout<<qu.back().x<<' '<<qu.back().y<<endl;
                    if(qu.back().x == 8 && qu.back().y ==8) {
                         cout<<">>>>"<<endl;
                         break;
                     }
                    
                }
                break;
                 case 1:  //下
                if(qu.front().x +1 >= 0 && qu.front().x+1 <= 9 && qu.front().y  <= 9 && qu.front().y>=0
                && !vis[qu.front().x+1][qu.front().y] && !maze[qu.front().x+1][qu.front().y]){
                    vis[qu.front().x+1][qu.front().y] = 1;
                    sqQueue tmp;
                    tmp.x = qu.front().x+1;
                    tmp.y = qu.front().y;
                    qu.push(tmp); //入队
                    flag ++;
                //    cout<<qu.back().x<<' '<<qu.back().y<<endl;
                    if(qu.back().x == 8 && qu.back().y ==8) break;
                }
                break;
                 case 2:  //左
                if(qu.front().x >= 0 && qu.front().x <= 9 && qu.front().y - 1 <= 9 && qu.front().y - 1 >=0
                && !vis[qu.front().x][qu.front().y-1] && !maze[qu.front().x][qu.front().y-1]){
                    vis[qu.front().x][qu.front().y-1] = 1;
                    sqQueue tmp;
                    tmp.x = qu.front().x;
                    tmp.y = qu.front().y - 1;
                    qu.push(tmp); //入队
                    flag ++;
               //     cout<<qu.back().x<<' '<<qu.back().y<<endl;
                    if(qu.back().x == 8 && qu.back().y ==8) break;
                }
                break;
                 case 3:  //上
                if(qu.front().x -1 >= 0 && qu.front().x-1 <= 9 && qu.front().y <= 9 && qu.front().y >=0
                && !vis[qu.front().x-1][qu.front().y] && !maze[qu.front().x-1][qu.front().y]){
                    vis[qu.front().x-1][qu.front().y] = 1;
                    sqQueue tmp;
                    tmp.x = qu.front().x-1;
                    tmp.y = qu.front().y;
                    qu.push(tmp); //入队
                    flag ++;
                //   cout<<qu.back().x<<' '<<qu.back().y<<endl;
                     
                }
                break;
            }
             if(qu.back().x == 8 && qu.back().y ==8) break;
        }
        //每一层加一
        cnt ++;
         cout<<qu.front().x<<' '<<qu.front().y<<' '<<c++<<endl;
        qu.pop();  //将第一个弹出
     

    }
   // cout<<qu.back().x<<' '<<qu.back().y<<endl;
    cout<<cnt<<endl;
    cout<<qu.size()<<endl;


    system("pause:");
    return 0;
}