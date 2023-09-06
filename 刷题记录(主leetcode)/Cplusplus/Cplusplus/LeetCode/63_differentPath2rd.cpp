#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// class Solution {
// public:
//     int ans = 0;
//     int inThe(int a,int b,vector<vector<int>>& obstacleGrid){
//         return a >=0&&b>=0&&a<obstacleGrid.size()&&b<obstacleGrid[0].size();
//     }
//     bool dfs(int x,int y,vector<vector<int>>& obstacleGrid){
//         if((x == obstacleGrid.size()-1)&&(y == obstacleGrid[0].size()-1)){
//             ans++;
//             return true;
//         } 
//         int tx = x,ty = y +1;
//         if(inThe(tx,ty,obstacleGrid)&&!obstacleGrid[tx][ty]) dfs(tx,ty,obstacleGrid);
//         tx = x + 1,ty = y;
//         if(inThe(tx,ty,obstacleGrid)&&!obstacleGrid[tx][ty]) dfs(tx,ty,obstacleGrid);
//         return false;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         dfs(0,0,obstacleGrid);
//         return ans;
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    }
};
int main(){
   
    system("pause:");
    return 0;
}