#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int inThe(int a,int b,vector<vector<char>>& matrix){
        return a>=0&&b>=0 &&a<=matrix.size()&&b<=matrix[0].size();
    }
    void dfs(int x,int y,vector<vector<int>>& dp,vector<vector<char>>& matrix,int &row,int&col){
        if(!inThe(x,y,matrix) || dp[x][y]) return;
        dp[x][y] = 1;
        int tx = x+1,ty = y;
        if(inThe(tx,ty,matrix)&&matrix[tx][ty] == '1'){
            col += 1;
        }
        dfs(x+1,y,dp,matrix,row,col);
        dfs(x,y+1,dp,matrix,row,col);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(),n = matrix[0].size(),row,col;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if(!dp[i][j]){
                    dfs(i,j,dp,matrix,row,col);
                }
            }
        }
    }
};
int main(){
   
    system("pause:");
    return 0;
}