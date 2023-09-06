#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int computeOne(int n)
    {
        int res = 0;
        while (n)
        {
            if (n%2)
                res ++;
            n /= 2;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i ++) {
            ans.push_back(computeOne(i));
        }
        return ans;
    }
};
class Solution_1 {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0, j = 0,fc = 0,m = a.size(),n = b.size();
        string res;
        while(1)
        {
            int tmp = ((i<m)?(a[i ++] - 48) : 0 )+ ((j<n)?(b[j ++] - 48):0);
            if (tmp == 1) {
                if (fc) res += '0';
                else res += '1';
            }else if (tmp == 0){
                if (fc) {
                    res += '1';
                    fc = 0;
                }else res += '0';
            }else if (tmp == 2){
                if (fc) res += '1';
                else{res += '0';fc = 1;}
            }
            if (i >= m && j >= n)break;
        }
        if (fc) res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};