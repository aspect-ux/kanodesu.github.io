#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
        int cnt = 1,value = nums[0],ans = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i - 1] + 1){
                cnt ++;
            }
            else if(nums[i] == nums[i - 1]) continue;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}