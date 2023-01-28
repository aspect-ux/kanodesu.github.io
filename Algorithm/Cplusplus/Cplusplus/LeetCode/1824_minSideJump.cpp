#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 3; j ++)
            {
                if (obstacles[i] != j + 1)
                {
                    
                }
            }
        }
    }
};