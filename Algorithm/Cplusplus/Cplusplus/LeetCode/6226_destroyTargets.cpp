#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int cnt = 0;
    void isCorrect(int space,int num,vector<int> nums)
    {
        int n = nums.size();
        for (int j = 0; j < n; j ++) {
            for (int i = 0;num + space * i <= nums[j]; i ++) {
                if (nums[j] == num + space * i) {cnt ++;break;}
            }
        }
    }
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size(),ans = 0,keep = 0;
        for (int i = 0; i < n; i ++) {
            //输入指令nums[i]
            isCorrect(space,nums[i],nums);
            if (ans <= cnt) keep = min(keep,nums[i]);
            ans = max(ans,cnt);
            cnt = 0;
        }
        return keep;
    }
};
int main(){
    
    system("pause:");
    return 0;
}