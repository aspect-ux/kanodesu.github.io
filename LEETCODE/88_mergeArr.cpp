#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start = 0;
        for(int i =0;i<m;i++){
            if(nums1[i] == 0) {
                start = i;
                break;
            }
        }
        sort(nums1.begin(),nums1.begin() + start);
        sort(nums2.begin(),nums2.end());
        for(int i = 0;i < n; i++){
            nums1[i + m] = nums2[i];
        }
    }
};
int main(){
    system("pause:");
    return 0;
}