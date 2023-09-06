#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; i ++)
        {
            int t = 0;
            for (int j = 0; j < m; j ++)
            {
                int g = to_string(grid[j][i]).size();
                t = max(t,g);
            }
            ans[i] = t;
        }
        return ans;
    }
};