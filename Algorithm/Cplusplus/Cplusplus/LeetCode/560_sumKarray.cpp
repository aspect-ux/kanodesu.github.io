#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//条件错了，要加连续数组
/*class Solution {
public:
    int compute(string s){
        int temp = 0;
        for(char c : s){
            temp += c - 48;
        }
        return temp;

    }
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        string s = "";
        for(int i = 0; i < nums.size(); i++){
            s += to_string(nums[i]);
        }
        for(int i = 0; i< nums.size(); i++){
            for(int j = 1; j <= nums.size() - i; j++){
                int tmp = compute(s.substr(i,j));
                if(tmp == k){
                    ans ++;
                }
                cout<<tmp<<endl;
            }
        }
        return ans;
    }
};*/
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int size = nums.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                res += sum == k ? 1 : 0;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums={-1,-1,1};
    cout<<s.subarraySum(nums,0);
    system("pause:");
    return 0;
}