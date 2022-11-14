#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int GCD(int a){
        int ans = 0;
        for (int i= 1; i <= sqrt(a); i ++) {
            if (a % i == 0) return a / i;
        }
        return a;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        vector<int> dp(n,0),g(n,0);
        if (nums[0] % k == 0) {g[0] = 1;dp[0] = (GCD(nums[0])==k);}
        for (int i = 1; i < n; i ++) {
            if (nums[i] % k == 0) {dp[i] += g[i - 1] + (GCD(nums[i]) == k);g[i] += g[i - 1] + 1;}
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
int gcd(int m,int n)
    {
        if (m % n == 0)
        {
            return n;
        }
        else
        {
            return gcd(n,m % n);
        }
    }
int main(){
   
    system("pause:");
    return 0;
}