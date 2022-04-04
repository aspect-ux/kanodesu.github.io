#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_set>
using namespace std;
class Solution {
    private:
    int cnt = 0;
     unordered_set<int>row,column,diagonal;
public:
    void dfs(vector<vector<string>> res,int n,int pos){
        if(cnt == n){
            return;
        }
        dfs(res,n,pos);
        for(int i = 0;i < n;i ++){
            if(!(row.find(i) !=row.end() || column.find(pos) !=column.end() || diagonal.find()) )
            res[i][pos]='Q';
            row.emplace(i);
            column.emplace(pos);
            dfs(res,n,pos+1);

        }


    }
    vector<vector<string>> solveNQueens(int n) {
        //
        //建立三个集合用以存储是否能放queen,枚举
       
        vector<vector<string>> res;
        //初始化
        for(int i = 0 ;i < n; i++){
            for(int j = 0 ; j < n; j++){
                res[i][j]='.';
            }
        }
        int pos = 0;
        
            dfs(res,n,pos);
            return res;
        
    }
};
int main(){



    system("pause:");
    return 0;
}