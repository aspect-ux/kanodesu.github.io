#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
void Print(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
}
void insert_sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) { // n - 1轮次执行
            int target = nums[i], j = i - 1;
            for (; j >= 0; j--) {
                if (target < nums[j]) nums[j + 1] = nums[j];
                else break;
            }
            // j变动表示发生了移动，此时的插入对象数字 ≥ j位置的数字，故插入位置为j + 1
            if (j != i - 1) nums[j + 1] = target;
        }
        Print(nums);
}

int main() {
    vector<int> nums = { 1,2,4,2,1,4,2,8,3,7,2 };
    insert_sort(nums);
    Print(nums);
    system("pause:");
    return 0;
}