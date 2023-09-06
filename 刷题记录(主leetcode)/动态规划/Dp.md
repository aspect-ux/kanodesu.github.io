## 动态规划

#### 杨辉三角 lc118

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        for(int i = 0;i < numRows; i++){
            dp[i].resize(i + 1);
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for(int i = 2; i < numRows; i++){
            for(int j = 1; j < i; j ++){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];   // C(k,n) = C(k - 1,n) + C(k - 1 , n - 1);
            }
        }
        return dp;
    }
};
```



`static constexpr int inf = 0x3f3f3f3f;`



[1824. 最少侧跳次数 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-sideway-jumps/)

```cpp
class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<int> d = {1, 0, 1};
        for (int i = 1; i <= n; i++) {
            int minCnt = inf;
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                } else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};

```

