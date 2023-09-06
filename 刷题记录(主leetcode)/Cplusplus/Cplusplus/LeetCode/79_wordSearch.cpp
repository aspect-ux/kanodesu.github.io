#include<iostream>
#include<vector>
class Solution {
public:
    int flag = 0;
    bool inthe(vector<vector<char>>& board,int x,int y){
        return (x<=board.size()-1)&&(x>=0) &&(y<=board[0].size() - 1)&& (y>=0); 
    }
    bool dfs(vector<vector<char>>& board, string word,int pos,int x,int y,vector<vector<int>>& dp){
        if(pos == word.length()) return true;
        if(board[x][y] != word[pos]) return false;
        dp[x][y] = 1;
        int tx = x,ty = y + 1;
        if(inthe(board,tx,ty)&&!dp[tx][ty]&&dfs(board,word,pos + 1,tx,ty,dp)) return true;
        if(!(inthe(board,tx,ty)&&!dp[tx][ty])) flag++;
        tx = x + 1,ty = y;
        if(inthe(board,tx,ty)&&!dp[tx][ty]&&dfs(board,word,pos + 1,tx,ty,dp)) return true;
        if(!(inthe(board,tx,ty)&&!dp[tx][ty])) flag++;
        tx = x,ty = y - 1;
        if(inthe(board,tx,ty)&&!dp[tx][ty]&&dfs(board,word,pos + 1,tx,ty,dp)) return true;
        if(!(inthe(board,tx,ty)&&!dp[tx][ty])) flag++;
        tx = x - 1,ty = y;
        if(inthe(board,tx,ty)&&!dp[tx][ty]&&dfs(board,word,pos + 1,tx,ty,dp)) return true;
        if(!(inthe(board,tx,ty)&&!dp[tx][ty])) flag++;
         //如果四条路都走不了，就返回true
         if(flag == 4) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       
        for(int i = 0;i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                flag = 0;
                vector<vector<int>> dp(board.size(),vector<int>(board[0].size(),0));
                if(dfs(board,word,0,i,j,dp)) return true;
            }
        }
        return false;

    }
};
using namespace std;
int main(){


    system("pause:");
    return 0;
}