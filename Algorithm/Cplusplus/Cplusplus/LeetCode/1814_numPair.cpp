#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    const long long MOD = 1e9+7;
    ll rev(int x)
    {
        ll ans = 0;
        while (x > 0) {
            ans = (ans * 10 + (x%10));
            x /= 10;
        }
        return ans;
    }
    int _comm(int n,int k){
        if(k > n)
            return 0;
        else if(n == k||k==0)
            return 1;
        else
            return comm(n-1,k) + comm(n-1,k-1);
    }
    int comm(int x,int y){
        int num1 = x,num2 = y,num = 0;
        for(int i = 1;i < y; i++)
        {
            num1 *= x - i;
            num2 *= y - i;
        }
        num = num1/num2;
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,int> hash;
        for(int i = 0; i < n; i ++) {
            hash[(ll)nums[i] - rev(nums[i])] ++;
        }
        //compute C(n,m)
        ll ans = 0;
        for (auto c : hash) {
            ans = (ans + comm(c.second,2))%MOD;
        }
        return ans;
    }
};