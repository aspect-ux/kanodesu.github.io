#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int res = 0,flag = 0;
    void dfs(vector<int>& nums,int pos,int sum){
        if(flag)return; 
        if(pos == nums.size()) return;
        if(2*res == sum) {
            flag = 1;
            return;
        }
        res += nums[pos];
        dfs(nums,pos + 1,sum);
        res -= nums[pos];
        dfs(nums,pos + 1,sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0,res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        dfs(nums,0,sum);
        if(flag) return true;
        else return false;
    }
};
int main(){

    system("pause:");
    return 0;
}