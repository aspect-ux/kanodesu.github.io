#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int inThe(int a,int b,vector<vector<int>>& matrix){
        return a<matrix.size()&&a>=0&&b<matrix[0].size()&&b>=0;
    }
    int dfs(int x,int y,vector<int>& ans,int len,vector<vector<int>>& matrix,int index,vector<vector<int>>&dp){
        if(len == 0) return true;
        len --;
        dp[x][y] = 1;
        ans.push_back(matrix[x][y]);
        int tx = x,ty = y + 1;
        if(inThe(tx,ty,matrix)&& !dp[tx][ty]&&dfs(tx,ty,ans,len,matrix,index+1,dp)){
            return true;
        }
        tx = x + 1,ty = y;
        if(inThe(tx,ty,matrix)&& !dp[tx][ty]&&dfs(tx,ty,ans,len,matrix,index+1,dp)){
            return true;
        }
        tx = x,ty = y - 1;
        if(inThe(tx,ty,matrix)&& !dp[tx][ty]&&dfs(tx,ty,ans,len,matrix,index+1,dp)){
            return true;
        }
        tx = x - 1,ty = y;
        if(inThe(tx,ty,matrix)&& !dp[tx][ty]&&dfs(tx,ty,ans,len,matrix,index+1,dp)){
            return true;
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int len = matrix.size() * matrix[0].size(),index = 0;
        vector<int> ans;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        dfs(0,0,ans,len,matrix,index,dp);
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}