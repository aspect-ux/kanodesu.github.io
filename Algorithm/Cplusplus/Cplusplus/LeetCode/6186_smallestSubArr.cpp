#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n  = nums.size(),maxv = nums[0],index = 0,tmp = maxv;
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1; i < n; i ++){
            maxv |= nums[i];
            dp[1] = maxv; 
            if(maxv > tmp){
                index = i;
                tmp = maxv;
            }
        }
        int now = nums[0];
        vector<int> ans;
        for(int i = 0; i < n; i ++){
            now = nums[i];
            for(int j = i + 1; j < n; j ++){
                if(now == tmp) {
                    ans.push_back(j - i);
                    break;
                }
                now |= nums[j];
            }
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}