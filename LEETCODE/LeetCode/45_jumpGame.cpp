#include<iostream>
#include<vector>
using namespace std;
//贪心算法求最优解
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
/*
class Solution {
private:
    int newJump = 0,ans = 0,newStart = 0,newIndex = 0;
public:  //递归
    int fun(vector<int>& nums,int newStart,int newIndex){
         if(newIndex >= nums.size() -1){  //如果当前可以跳到终点
            return ans;                                    //返回结果
        }                                                  //如果不行，那就遍历所有情况找到最远的newStart
        for(int i = newStart; i < nums[i] && i < nums.size(); i++)  //内容为n，那么最远跳n,最近跳1  没必要跳0那样浪费次数 于是循环n次
        {
           if(newStart < i + nums[i]){
               newStart = i +nums[i];
               newIndex = i;
               newJump = nums[i];  //递归强调迭代谨慎赋值         
           }   
        }
        if(newIndex == nums.size() -1 && newJump == 0) return 0;
        ans ++;
        return fun(nums,newIndex + newJump,newIndex); 
    }
    int jump(vector<int>& nums) {
        return fun(nums,0,0);      //多加个newIndex
    }
};*/
int main(){
    Solution s;
    vector<int> nums={0};
    cout<<s.jump(nums);


    system("pause:");
    return 0;
}