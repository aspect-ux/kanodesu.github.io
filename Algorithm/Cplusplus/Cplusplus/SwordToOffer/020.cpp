#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//中心拓展
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int l = i,r = l;l>=0;l --,r ++) {
                if (s[l] == s[r]) ans ++;
                else break;
            }
            for (int l = i,r = l + 1;l>=0;l --,r ++) {
                if (s[l] == s[r]) ans ++;
                else break;
            }
        }
        return ans;
    }
};
