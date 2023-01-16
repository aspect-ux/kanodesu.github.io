#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int BreakToPrimeSum(int a)
    {
        int sum = 0;
        for (int i = 2; i <= a; i ++) {
            while (a % i == 0)
            {
                sum += i;
                a /= i;
            }
        }
        return sum;
    }
    bool IsPrime(int x)
    {
        if (1 >= x)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(x); i++)
            if (x%i == 0)
            {
                return false;
            }
        return true;
    }
    int smallestValue(int n) {
        while (!IsPrime(n))
        {
            n = BreakToPrimeSum(n);
        }
        return n;
    }
};
