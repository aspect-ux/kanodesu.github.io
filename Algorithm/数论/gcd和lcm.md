# 最大公约和最小公倍数

两者关系 gcd * lcm = a * b;

[6234. 最小公倍数为 K 的子数组数目 - 力扣（LeetCode）](https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/submissions/)

要计算最小公倍数为k的子数组。通过上述公式，双重循环枚举

如果lcm大于k，那就跳出；如果等于k，那就符合要求ans++;否则继续循环。

**核心思想在于** 第一个数和第一个数求lcm,单个数是否符合要求，后面每层都和第一个lcm，这样保证符合要求就++,可能符合要求就循环，不符合就跳出。

```c++
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long l = nums[i];
            for (int j = i; j < n; j++) {
                long long g = gcd(l, nums[j]);
                l = l / g * nums[j];
                if (l == k) ans++;
                // 防止溢出
                else if (l > k) break;
            }
        }
        return ans;
    }
};
```

