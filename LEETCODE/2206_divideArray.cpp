#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
   
public:
    bool divideArray(vector<int>& nums) {
         unordered_map<int,bool> ispair;
         for(int i =0;i < nums.size();i ++){
             if(ispair.find(nums[i])!= ispair.end()){//找到
                if(ispair[nums[i]] == true) //如果已经成对，
                ispair[nums[i]] = false;    //偶变奇
                else{ //只有奇数个     
                ispair[nums[i]] = true;     //奇变偶
                }

             }
             else{
                 ispair.insert({nums[i],false}); //不存在就初始化

             }
         }
         for(pair<int,bool> c : ispair){
             if(c.second == false)
             return false;

         }
         return true;

        
    }
};
int main(){
    Solution s;
    vector<int> nums={3,2,3,2,2,2};
    cout<<s.divideArray(nums);


    system("pause:");
    return 0;
}