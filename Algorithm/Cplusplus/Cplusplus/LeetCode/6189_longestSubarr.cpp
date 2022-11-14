#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(),cnt = 1,ans = 1;
        auto it = *max_element(nums.begin(),nums.end());
        for(int i = 0; i < n; i ++){
            while(nums[i] == (it)){
                cnt ++;
            }
            ans = max(ans,cnt);
            cnt = 1;
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}