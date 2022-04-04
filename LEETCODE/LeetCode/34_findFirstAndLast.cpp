#include<iostream>
#include<vector>
using namespace std;
class Solution {
public://could it be logn for the complexity of time?   double Pointer
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int i =0, j = nums.size()-1; //找到0个，找到1个，找到2个，找到多个(采用双指针就不用考虑),nums为空
        //找到一个又分为只有一个头，只有一个尾，和头尾共用
        //null
        if(nums.size() == 0) return {-1,-1};
        while( i < nums.size() && nums[i] != target){  //先比较后判断是否相等不然null没法跟int比较
            i++;
        }
        //假设没找到 ,有可能遍历后到达nums.size(),但也有可能最后一个元素找到，
        if(i == nums.size()) return {-1,-1};
        //假设找到

        while(j > i && nums[j] !=target){
            j--;
        }
        // 假设尾指针没找到 即 j == i
        if(j == i) return {i,i};  //1
        // 假设为指针找到 即 j >i
        return {i,j};    //2
    }
};
int main(){
    Solution s;
    vector <int> nums ={1};
    vector<int> res = s.searchRange(nums,1);
    cout<<res[0]<<' '<<res[1];
    system("pause:");
    return 0;
}