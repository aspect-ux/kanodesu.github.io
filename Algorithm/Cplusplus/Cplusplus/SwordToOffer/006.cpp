#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //vector find,击败5%
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i ++) {
            int tmp = target - numbers[i];
            auto newBegin = numbers.begin() + i + 1;
            auto it = find(newBegin,numbers.end(),tmp);
            int t = it - newBegin;
            if (it != numbers.end()) {
                return {i,t + i + 1};
            }
        }
        return {};
    }
};
class Solution_1 {
public:
    //二分,因为本来就是升序,又刚好要查找,二分再合适不过
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i, mid};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};
class Solution_2 {
public://双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l<r){
            if(numbers[l] + numbers[r] == target) return {l, r};
            else if(numbers[l] + numbers[r] > target) r--;
            else l++;
        }
        return {-1, -1};
    }
};