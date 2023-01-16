#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int avg = 0,n = skill.size();
        long long sum = 0,ans = 0;
        unordered_map<int,int> hash;
        for (int i = 0 ; i < n; i ++) {
            sum += skill[i];
        }
        if (sum % (n/2)) return -1;
        avg = sum/(n/2);
        for (int i = 0; i < n; i ++) {
            if (hash.find(avg - skill[i]) == hash.end()) hash[skill[i]]++;
            else {ans += skill[i]*(avg - skill[i]);if (--hash[avg - skill[i]] == 0) hash.erase(avg - skill[i]);}
        }
        return ans;
    }
};