#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long ans = 0;
    long long numberOfWays(string s) {
        int n = s.length(),last0 = 0,last1 = 0;
        vector<long long> type01(n,0),type10(n,0);
        vector<int> vis1(n,0),vis0(n,0),num(n,0);
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == '0'){
                vis0[i] += last0 + 1;
                last0 = vis0[i];
                if (i != n - 1)
                {
                    vis1[i] = vis1[i + 1];
                    type10[i] = type10[i + 1];
                }
                type01[i] += vis1[i] + ((i!=n-1)?type01[i + 1]:0);
            }
            else {
                vis1[i] += last1 + 1;
                last1 = vis1[i];
                if (i != n - 1)
                {
                    vis0[i] = vis0[i + 1];
                    type01[i] = type01[i + 1];
                }
                type10[i] += vis0[i] + ((i!=n-1)?type10[i + 1]:0);
            }
        }
        for (int i = 0; i < n - 2; i ++) {
            if (s[i] == '0') ans += type10[i + 1];
            if (s[i] == '1') ans += type01[i + 1];
        }
        return ans;
    }
};