#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int parseIntoInt(string a){
        return (a[0] * 10 + a[1]) * 60 + a[3] * 10 + a[4];
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> parse;
        int ans = INT32_MAX;
        for (int i = 0; i < n ; i ++) {
            for (int j = i + 1; j < n; j ++){
                int t1 = parseIntoInt(timePoints[i]),t2 = parseIntoInt(timePoints[j]);
                int a = max(t1,t2),b = min(t1,t2);
                ans = min(ans,min(a - b,abs(a - 24 * 60 - b)));
            }
        }
        return ans;
    }
};