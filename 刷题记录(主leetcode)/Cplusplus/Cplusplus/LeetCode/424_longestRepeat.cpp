#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<vector<int>> hash(26,vector<int>(2));
        int n = s.length(),ans = 0;
        for(int i = 0; i < n; i ++){
            if(hash[s[i] - 'A'][1]){
                if(i - hash[s[i] - 'A'][0] - 1 <= k){
                    hash[s[i] - 'A'][1] += i - hash[s[i] - 'A'][0];
                    hash[s[i] - 'A'][0] = i;
                }
            }else{
                hash[s[i] - 'A'][0] = i;
                hash[s[i] - 'A'][1] = 1;
            }
        }
        for(auto c : hash) ans = max(ans,c[1]);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}