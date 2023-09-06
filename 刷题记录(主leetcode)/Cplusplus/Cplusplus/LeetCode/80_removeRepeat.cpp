#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),cnt = 0;
        if(n == 1) return 1;
        for(int i = 0, j = i + 1; j < n;){
            if(nums[i] != nums[j]){
                i = j;
                j ++;
                continue;
            }
            while(nums[i] == nums[j]){
                if(j - i >= 2)
                {
                    nums.erase(nums.begin() + j,nums.begin()+j+1);
                    cnt ++;
                }
            }
            nums.resize(n);
        }
        return n - cnt;
    }
};
int main(){
    
    system("pause:");
    return 0;
}