#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution {
public:/*
    int max(int x,int y,int z){
        int temp = x>y?x:y;
        return temp>z?temp:z;

    }*/
    int maxProduct(vector<int>& nums) {
        int dpp[nums.size()],dps[nums.size()],temp,ans = 0;
        memset(dpp,0,sizeof(dpp));
        memset(dps,0,sizeof(dps));
        if(nums.size() == 1) return nums[0];
        dpp[0] = dps[0] = nums[0];
        for(int i = 1;i < nums.size(); i++){
            dpp[0] = max(dpp[0]*nums[i],max(nums[i],dps[0]*nums[i]));
            dps[0] = min(dps[0]*nums[i],min(nums[i],dpp[0]*nums[i]));
            
            

            ans = max(ans,dpp[0]);
        }
        return ans;

    }
};
int main(){
    Solution s;
    vector<int>nums={-2,0,-1};
    cout<<s.maxProduct(nums);
    system("pause:");
    return 0;
}
