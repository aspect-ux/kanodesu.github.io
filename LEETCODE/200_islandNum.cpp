#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//下面的方法时间复杂度太高能否再优化
/*
class Solution {
public:
    int inthegrid(int x,int y,vector<vector<char>>& grid){
        return x<grid.size()&&x>=0&&y<grid[0].size()&&y>=0 ? 1:0;
    }
    int dfs(int &ans,int i,int j,vector<vector<char>>& grid,int vis[1000][1000]){
        grid[i][j] = '2';
        int x = i,y = j + 1;  //右
        if(inthegrid(x,y,grid) && grid[x][y]!='2' && grid[x][y]!='0'){  //走过的地方标记为2,
             dfs(ans,x,y,grid,vis);
        }
         x = i + 1,y = j;//下
        if(inthegrid(x,y,grid) && grid[x][y]!='2' && grid[x][y]!='0'){  //走过的地方标记为2
              dfs(ans,x,y,grid,vis);
        }
        x = i,y = j - 1;//左
        if(inthegrid(x,y,grid) && grid[x][y]!='2' && grid[x][y]!='0'){  //走过的地方标记为2
            dfs(ans,x,y,grid,vis);
        }
         x = i - 1,y = j;//上
        if(inthegrid(x,y,grid) && grid[x][y]!='2' && grid[x][y]!='0'){  //走过的地方标记为2
           dfs(ans,x,y,grid,vis);
        }
        if(vis[i][j] == 1)
        ans++;   //无路可走那么找到一片陆地
    }
    int numIslands(vector<vector<char>>& grid) {
        int vis[1000][1000];
        int n = grid.size(),m = grid[0].size();
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for(int i = 0;i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    vis[i][j] = 1;
                    dfs(ans,i,j,grid,vis);
                    vis[i][j] = 0;
                }
            }
        }
        return ans;


    }
};*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

    }
};
int main(){
    Solution s;
    //不知道怎么输入要么用for吧
   /* vector<vector<char>> grid({{'1','1','1','1','0'},
        {'1','1','0','1',"0"},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}});*/
    cout<<s.numIslands(grid);

    system("pause:");
    return 0;
}