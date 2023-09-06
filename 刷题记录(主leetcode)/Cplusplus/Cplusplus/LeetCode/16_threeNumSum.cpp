#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=0,m,add=0,ans = (target-nums[0]-nums[1]-nums[2]);
        vector<int>a;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
        {
            for(int k=j+1;k<nums.size();k++)
        {
            add=nums[i]+nums[j]+nums[k];
            ans =min(ans,abs(target-add));               
        }           
        }       
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={-3,-2,-5,3,-4};
    cout<<s.threeSumClosest(nums,-1);

    system("pause:");
    return 0;
}