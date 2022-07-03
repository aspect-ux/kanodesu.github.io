#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(int a,int b){   //声明为静态方法
        return to_string(a) > to_string(b);
    }
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(),nums.end(),cmp);
        for(int i = nums.size() - 1; i >= 0; i--){
            res += to_string(nums[i]);
        }
        return res;
    }
};
int main(){
    system("pause:");
    return 0;
}