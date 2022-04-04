#include<iostream>
#include<vector>
using namespace std;
class Solution { //在vector动态分配空间时不能直接通过下表来改变值

public:
    void fun(vector<int>& nums,int pos,int &ans){
        if(pos == 0) {
            ans = nums[0];
            return;
        }
        for(int i =0 ; i < pos; i++){
            nums[i] = (nums[i] +nums[i+1])%10;
        }
        fun(nums,pos - 1,ans);


    }
    int triangularSum(vector<int>& nums) {
    int pos = nums.size() -1,ans =0;
    fun(nums,pos,ans);
       return ans; 
    }
};
int main(){
    Solution s;
    vector<int>nums={1,2,3,4,5};
    cout<<s.triangularSum(nums);


    system("pause:");
    return 0;
}