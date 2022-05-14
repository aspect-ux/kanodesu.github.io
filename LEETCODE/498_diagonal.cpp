#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //分装，再装箱     x+y=n
        //对角线数组空间为m+n+1条对角线
        vector<vector<int>> diagonal(mat.size()+mat[0].size()+1,vector<int>());
        vector<int> ans;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                diagonal[i+j].push_back(mat[i][j]);
            }
        }
        int flag = 1;
        for(vector<int> c : diagonal){
            if(flag){
                reverse(c.begin(),c.end());
                ans.insert(ans.end(),c.begin(),c.end());
                flag = 0;
            }
            else{
                ans.insert(ans.end(),c.begin(),c.end());
                flag = 1;
            }
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}