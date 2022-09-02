#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestNumber(string pattern) {
        string nums = "123456789",ans = "",ts;
        vector<int> help;
        int cnt = 0,tmp = 0;
        for(int i = 0; i < pattern.size(); i++){
            if(pattern[i] == 'I'){
                tmp = i;
                while(pattern[i] == 'I'){
                    i++;
                    cnt ++;
                }
                ans += nums.substr(tmp,cnt);
                cnt = 0;
                nums.erase(tmp,cnt);
            }
            if(pattern[i] == 'D'){
                tmp = i;
                while(pattern[i] == 'D'){
                    i++;
                    cnt ++;
                }
                ts = nums.substr(tmp+1,cnt);
                reverse(ts.begin(),ts.end());
                ans += ts;
                cnt = 0;
                nums.erase(tmp,cnt);
            }
        }
        return ans;
    }
};
int main(){
   //Solution s;

    system("pause:");
    return 0;
}