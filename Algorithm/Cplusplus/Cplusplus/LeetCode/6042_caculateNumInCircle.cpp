#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
// 在不在圆内，到没到过，什么时候结束  //递归不行......  暴力枚举
class Solution {
private:
     unordered_map<int,unordered_map<int,int>>hash;
     int dp[201][201];
     int n = 0;
public:
    int indp(int x,int y){
        return 0<=x&&x<=201 &&0<=y&&y<=100;
    }
    int inThe(int x,int y,vector<int>&circle){
        return ((x - circle[0])*(x - circle[0]) + (y - circle[1])* (y - circle[1])) <= circle[2]*circle[2];
    }
    void dfs(vector<int> &circle,int x,int y){
        if(!(inThe(x,y,circle)&&indp(x,y)&&hash[x].find(y) == hash[x].end()))
        return;
        n++;
        hash[x][y] = 1;
        int tx = x,ty = y + 1;  //向上走
        dfs(circle,tx,ty);
        tx = x + 1,ty = y;  //向右走
        dfs(circle,tx,ty);
        tx = x,ty = y - 1;  //向下走
        dfs(circle,tx,ty);
        tx = x - 1,ty = y;  //向左走
        dfs(circle,tx,ty);
        return;
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < circles.size(); i++){
            dfs(circles[i],circles[i][0],circles[i][1]);
        }
        for(int i = 0; i < 201; i++){
            for(int j = 0 ; j < 201; j++){
                if(dp[i][j])
                ans++;
            }
        }
        return n;
        
    }
};
int main(){
    Solution s;
    vector<vector<int>> nums={{8,9,6},{9,8,4},{4,1,1},{8,5,1},{7,1,1},{6,7,5},{7,1,1},{7,1,1},{5,5,3}};
    cout<<s.countLatticePoints(nums);
    system("pause:");
    return 0;
}