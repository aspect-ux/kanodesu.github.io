#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n),arr(n),keep;
        int cnt = 0;
        iota(perm.begin(),perm.end(),0);
        keep = perm;
        while (true)
        {
            cnt ++;
            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0) arr[i] = perm[i / 2];
                else arr[i] = perm[n / 2 + (i - 1) / 2];
            }
            perm = arr;
            if (keep == arr) return cnt;
            
        }
        return -1;
    }
};