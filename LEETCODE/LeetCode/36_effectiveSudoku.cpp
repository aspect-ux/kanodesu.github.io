#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int rows[9][9],columns[9][9],subboxes[3][3][9];
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(rows,0,sizeof(rows));
        memset(columns,0,sizeof(columns));
        memset(subboxes,0,sizeof(subboxes));
        for(int i = 0;i < 9; i++){
            for(int j = 0; j<9 ;j++){
                if(board[i][j]!='.'){
                    int index = board[i][j] - '0' -1;//下标
                    rows[i][index]++;
                    columns[i][index]++;
                    subboxes[i/3][j/3][index]++;
                     if(rows[i][index]>1 || columns[i][index] >1 || subboxes[i/3][j/3][index] >1){
                     return false;//只遍历一次，若是不满足要求
                    }
                }   
            }
            
        }
        return true;

    }
};
int main(){


    system("pause:");
    return 0;
}