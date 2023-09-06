#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<bool> status;
    void dfs(vector<vector<int>>& ans,vector<int>& nums){

        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!status[i]){
                status[i] = true;
                res.push_back(nums[i]);
                dfs(ans,nums);
                res.pop_back();
                status[i] = false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        status.resize(nums.size(),false);
        dfs(ans,nums);
        unordered_map<vector<int>,int> hash;

        return ans;

    }
};


int main(){
   
    system("pause:");
    return 0;
}