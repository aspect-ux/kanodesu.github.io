#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Trivalue(vector<vector<int>>& grid,int i,int j){
        int maxv = 0;
        
        for(int k = i;k < i+3;k++){
            for(int m = j; m < j+3; m++){
                maxv = max(grid[k][m],maxv);
            }
        }
        return maxv;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> tmp;
        vector<vector<int>> ans;
        if(n == 1){
            return {{grid[0][0]}};
        }
        if(n == 2){
            return{{max(grid[0][0],max(grid[0][1],max(grid[1][0],grid[1][1])))}};
        }
        for(int i = 0; i < n - 2; i++){
            for(int j = 0;j < n -2; j++){
                tmp.push_back(Trivalue(grid,i,j));
            } 
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}