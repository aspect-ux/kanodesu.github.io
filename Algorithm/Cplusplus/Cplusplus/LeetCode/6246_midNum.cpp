#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < n; j ++) {
                vector<int> arr(nums.begin()+i,nums.begin()+j);
                if (midNum(arr) == k) ans ++;
            }
        }
        return ans;
    }
    int partion(vector<int>& array, int begin, int end) {
	int start = begin;
	int key = array[begin];
	while (begin < end) {
		while (begin < end && array[end] >= key) {
			end--;
		}
		while (begin < end && array[begin] <= key) {
			begin++;
		}
		swap(array[begin], array[end]);
	}
	swap(array[start], array[begin]);
	return begin;
    }	
 
    int getNum(vector<int>& array, int midIndex) {
        int left = 0;
        int right = array.size() - 1;
        int index = -1;
        while (index != midIndex) {
            index = partion(array, left, right);
            if (index > midIndex) {
                right = index - 1;
            }
            else if (index < midIndex) {
                left = index + 1;
            }
            else
                break;
        }
        return (double)array[index];
    }
    int midNum(vector<int>& array) {
        if (array.empty()) {
            return -1;
        }
        int midIndex = (array.size() - 1) / 2;
        if (array.size() % 2 == 1) {
            return getNum(array, midIndex);
        }
        return (getNum(array, midIndex) + getNum(array, midIndex + 1)) / 2;
    }
};

