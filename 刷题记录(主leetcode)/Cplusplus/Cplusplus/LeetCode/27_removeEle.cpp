#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = nums.size();
        vector<int>::iterator it;
        it = remove(nums.begin(),nums.end(),val);
        return it - nums.begin();
    }
};
int main(){
   
    system("pause:");
    return 0;
}