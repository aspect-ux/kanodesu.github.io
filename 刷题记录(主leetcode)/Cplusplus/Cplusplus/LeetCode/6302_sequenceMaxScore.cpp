#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<bool> status;
    int cnt = 0;
    long long ans = INT_MIN;
    void dfs(vector<int>& nums1,vector<int>& nums2,int k,int n,long long sum,long long mul){
        if(cnt==k)
        {
            ans= max(ans,sum * mul);
            return;   
        }
        for(int i = cnt;i < n; i++){
                cnt ++;
                if (cnt == 1 && i == n - k + 1) return;
                sum += nums1[i];
                long long mul_tmp = mul;
                mul = min(mul,(long long)nums2[i]);
                
                dfs(nums1,nums2,k,n,sum,mul);
                
                sum -= nums1[i];
                mul = mul_tmp;
                cnt --;
            }
            
        }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
      
        dfs(nums1,nums2,k,n,0,INT_MAX);
        return ans;
    }
};