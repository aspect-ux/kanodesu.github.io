#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int available = maxSum - n,ans = 0,sum = 0,border = -1;
        for (int i = 0;available > 0; i ++)
        {
            if (index + i > n - 1 || index - i < 0) 
            {
                if (index + i > n - 1 && index - i < 0) sum = n;
                else sum = 1 + i + min(n - index - 1,index);
            }
            else sum = 1 + i * 2;

            ans ++;
            available -= sum;
            if (available < 0) ans --;
        }
        return ans + 1;
    }
};