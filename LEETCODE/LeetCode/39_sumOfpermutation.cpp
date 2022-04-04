#include<iostream>
#include<vector>
using namespace std;
class Solution {


public:
    void dfs(vector<int> res,int t,vector<vector<int>> &ans,vector<int>& candidates,int i){
        if(i == candidates.size()) return;
        if(t == 0){
            ans.emplace_back(res);
            return;
        }
        dfs(res,t,ans,candidates,i+1);
        if(t - candidates[i] >=0 ){
            res.emplace_back(candidates[i]);
            dfs(res,t - candidates[i],ans,candidates,i);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
    vector<vector<int>> ans;
        dfs(res,target,ans,candidates,0);
        return ans;
    }
};
int main(){


    system("pause:");
    return 0;
}