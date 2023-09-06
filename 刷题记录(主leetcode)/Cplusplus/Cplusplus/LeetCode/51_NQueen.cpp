#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void backtrace( vector<int> &queen,unordered_set<int>&columns, unordered_set<int>&diagonal1,unordered_set<int>&diagonal2,vector<vector<string>> &ans,int row,int n){
        if(row == n) {
            vector<string> row1;
            for(int i =0; i < row;i++){
                string tmp(n,'.');
                tmp[queen[i]]='Q';
                row1.push_back(tmp);
               
            }
             ans.push_back(row1);
            return;
            
        }
        for(int i =0 ;i < n; i++){
            if(columns.find(i) != columns.end()){//找到了continue
                continue;
            }
            int diagonal11 = row - i;
            if(diagonal1.find(diagonal11) != diagonal1.end()){
                //主对角找到
                continue;
            }
            int diagonal22 = row + i;
            if(diagonal2.find(diagonal22) != diagonal2.end()){
                //主对角找到
                continue;
            }
           
                 queen[row] = i;
            columns.insert(i);
            diagonal1.insert(row - i);
            diagonal2.insert(row + i);
            //要是都没找到就开始尝试填写
            backtrace(queen,columns, diagonal1,diagonal2,ans,row + 1,n);
            //如果填满了开始回溯
            queen[row] = -1;
            columns.erase(i);
            diagonal1.erase(row - i);
            diagonal2.erase(row + i);

            
           

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queen(n,-1);
        vector<vector<string>> ans;
        unordered_set<int>columns;
        unordered_set<int>diagonal1;
        unordered_set<int>diagonal2;
    
        backtrace(queen,columns, diagonal1,diagonal2,ans,0,n);
        return ans;
        

    }
};
int main(){
    Solution s;
    s.solveNQueens(4);



    system("pause:");
    return 0;
}