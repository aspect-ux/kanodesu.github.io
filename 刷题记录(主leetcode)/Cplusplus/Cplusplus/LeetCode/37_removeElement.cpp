#include<iostream>
#include<vector>
using namespace std;
/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
class Solution { //double pointer  destination is to move the val before to the behind,while moving !val to front 
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = nums.size() - 1,ans = 0;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1 && nums[0] != val) return 1; //只有一个元素并且不为val
    while(i < j){
        while(i < j && i<nums.size() && nums[i] != val)
           i++;
       
        //此时nums[i] = val
        while(j>i && nums[j] == val)
            j--;
        if(j > i){
            swap(nums[i],nums[j]);
        }
        }
        for(int i = 0; i < nums.size();i++){
            if(nums[i] != val) {
                ans++;
            }
            else {
                break;
            }

        }
    return ans;
    }
};
int main(){

    Solution s;
    vector<int>nums={3,3};
    cout<<s.removeElement(nums,5)<<endl;
   for(int i = 0;i < nums.size(); i++){
        cout<<nums[i]<<' ';
    }
    system("pause:");
    return 0;
}