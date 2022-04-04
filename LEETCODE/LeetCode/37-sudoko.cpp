#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
//https://leetcode-cn.com/problems/sudoku-solver/

char board[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
unordered_map<int,char> arr = {{'0','1'},
{1,'2'},{2,'3'},{3,'4'},{4,'5'},{5,'6'},{6,'7'},{7,'8'},{8,'9'}};  //dir

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        unordered_map<int,char>:: iterator it =arr.begin();
        for(int i = 0;i < 9; i++){
            set<char> tmp = {'1','2','3','4','5','6','7','8','9'};
            for(int j =0; j <9; j++){   //删除重复元素
                auto it = arr.find(board[i][j]);
                if(it !=arr.end())
                tmp.erase(it->second);
            }
            for(int k =0;k < 9; k++){   //将空白处填充
                dfs();

            }
        }

    }

    public void dfs(){
        
    }
};

int main(){
   
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
  
   


    system("pause:");
    return 0;
}
