#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
    
public:
    void dfs(vector<vector<char>>& board,int row,vector<vector<int>> &vis){
        if(row == board.size()) return;
        for(int i = 0;i < board[0].size();i ++){
            if(board[row][i] == 'X') continue;
            if(board[row][i] == 'X'){
                if(row == 0 || i == 0 || row == board.size() - 1 || i == board[0].size() - 1){
                    continue;
                }
                
            }
            

        }

    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        dfs(board,0,vis);

    }
};
int main(){


    system("pause:");
    return 0;
}