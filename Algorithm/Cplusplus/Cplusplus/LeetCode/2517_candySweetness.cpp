#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        auto check = [&](int lim)
        {
            int cnt = 1;
            for (int i = 1,j = 0; i < n; i ++)
            {
                if(price[i] - price[j] >= lim)
                {
                    cnt ++;
                    j = i;
                }
            }
            return cnt >= k;
        };
        int head = 0,tail = price[n - 1],mid = (tail - head) /2 + head;
        while (head <= tail)
        {
            if (check(mid)) {head = mid;}
            else tail = mid - 1;
            mid = (tail - head) /2 + head + 1;
        }
        return mid;
    }
};