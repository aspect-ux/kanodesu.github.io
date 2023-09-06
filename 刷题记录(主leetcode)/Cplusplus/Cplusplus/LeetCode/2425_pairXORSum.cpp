#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        unordered_set<int> hash;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                hash.insert(nums1[i] ^ nums2[j]);
            }
        }
        int sum = 0;
        for(auto c : hash){
            sum ^= c;
        }
        return sum;
    }
};
int main(){
    
    system("pause:");
    return 0;
}