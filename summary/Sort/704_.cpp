#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1,mid;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};
void insert_sort(vector<int> nums){
    int j = 0,target;
    for(int i = 0;i < nums.size(); i++){
        target = nums[i];
        j = i;
        for(;j <= i; j++){
            if(target > nums[j + 1]){
                nums[j] = nums[j + 1];
            }
            else break;
        }
        if(j > i){
            nums[j + 1] = target;
        }
   }
}
void Print(vector<int> nums){
    for(int i = 0;i < nums.size(); i++){
        cout<<nums[i]<<endl;
    }
}
int main(){
    vector<int> nums={1,2,4,2,1,4,2,8,3,7,2};
    insert_sort(nums);
    Print(nums);
    system("pause:");
    return 0;
}