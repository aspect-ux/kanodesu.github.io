#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        for(int i = 0; i < n; i ++){
            if(s[i] == 0)  dp[i - 1] = 1;
        }
        for(int i = 0; i < n; i ++){
            if()
        }
    }
};
int main(){
    
    system("pause:");
    return 0;
}