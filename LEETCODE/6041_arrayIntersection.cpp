#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
         int n = nums.size();
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j < nums[i].size(); j++){
                if(hash.find(nums[i][j]) == hash.end()){ //没找到
                        hash.insert({nums[i][j],1});
                }
                else hash[nums[i][j]]++;
            }
        }
       
        for(int i = 0; i < nums[0].size(); i++){
            if(hash[nums[0][i]] == n){
                ans.push_back(nums[0][i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    vector<int> ans;
    ans = s.intersection(nums);
    for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<endl;
        }

    system("pause:");
    return 0;
}