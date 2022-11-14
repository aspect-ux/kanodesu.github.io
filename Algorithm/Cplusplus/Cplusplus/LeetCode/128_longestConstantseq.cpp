#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1,res = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == 1){
                ans++;
            }
            else if(nums[i] == nums[i - 1]) continue;
            else{
                res = max(res,ans);
                ans =  1;
            }
        }
        if(nums.size() == 0) return 0;
        return max(res,ans);
    }
};
int main(){
    Solution s;
    vector<int> nums={0,3,7,2,5,8,4,6,0,1};
    cout<<s.longestConsecutive(nums);

    system("pause:");
    return 0;
}