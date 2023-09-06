#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 1 3 2 3 3
// 1 2 3 3 3
// 1 1 1 
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(),left = 1e8,right = 0;
        vector<int> cp(nums),dp(n,0);
        sort(cp.begin(),cp.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[j]) continue;
                
                if(nums[i] == cp[j]){
                    if(i != j) {
                        left = min(left,min(i,j));
                        right = max(right,max(i,j));
                    }
                    dp[j] = 1;
                    break;
                }
            }
        }
        if(left == 1e8) return 0;
        return right - left + 1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}