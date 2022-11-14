#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(),l1 = 0;
        long long ans = 0;
        queue<int> QuMin,QuMax;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == minK) 
            {
                QuMin.push(i);
                if (QuMin.size() > 1) QuMin.pop();
            }
            if (nums[i] == maxK) 
            {
                QuMax.push(i);
                if (QuMax.size() > 1) 
                QuMax.pop();
            }
            if (QuMin.size() && QuMax.size()) {
                l1 = min(QuMin.front(),QuMax.front()) + 1;
                j = max(QuMin.front(),QuMax.front()) + 1;
                cout<<j<<"?"<<endl;
                
                ans += l1;
                cout<<ans<<endl;

                QuMax.pop();
                QuMin.pop();
                
                while (j < n) {
                    if (nums[j] <= maxK && nums[j] >= minK) {ans ++;cout<<"!!"<<ans<<endl;}
                    else {i = j + 1;break;}
                    j ++;
                }
            }
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}