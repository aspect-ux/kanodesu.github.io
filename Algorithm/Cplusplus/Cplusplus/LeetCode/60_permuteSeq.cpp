#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     int comm(int a,int b){
//         if(a == b) return 1;
//         if(a == 0) return 0;
//         if(a < b){
//             return comm(a - 1,b - 1) + comm(a - 1,b);
//         }
//     }
//     string getPermutation(int n, int k) {
//         vector<int> nums(n);
//         for(int i = 0; i < n; i++){
//             nums[i] = i + 1;
//         }
//         do{
//             k --;
//             if(k == 0) break;
//         }while(next_permutation(nums.begin(),nums.end()));
//         string ans = "";
//         for(int c : nums) ans += (c + '0');
//         return ans;
//     }
// };

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        string ans = "";
        vector<int> valid(n + 1, 1);
        int start = 1;
        for (int i = 1; i < n; ++i) {
            if(k > factorial[n - i - 1] && k < factorial[n - i]){
                for(int j = start ; j <= n - i; j ++) ans += (j + '0');
                start = n - i + 1;
                k -= factorial[n - i - 1];
            }
        
        }
        return ans;     
    }
};
int main(){
   
    system("pause:");
    return 0;
}