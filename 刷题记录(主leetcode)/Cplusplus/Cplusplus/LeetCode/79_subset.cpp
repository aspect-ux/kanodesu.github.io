#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(vector<int>& nums,int pos){
        if(pos == nums.size()){
             ans.push_back(res);
             return;
        }
        res.push_back(nums[pos]);
        dfs(nums,pos + 1);
        res.pop_back();
        dfs(nums,pos + 1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int pos = 0,n = nums.size();
        dfs(nums,pos);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    cout<<(s.subsets(nums))[1][0]<<endl;

    system("pause:");
    return 0;
}