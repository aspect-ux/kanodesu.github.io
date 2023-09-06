#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i ++){
            vector<int>::iterator it = find(nums2.begin(),nums2.end(),nums1[i]);
            it ++;
            for(;it < nums2.end(); it ++){
                if(*it > nums1[i]){
                    ans[i] = *it;
                    break;
                }
            }
            if(it == nums2.end()) ans[i] = -1;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}