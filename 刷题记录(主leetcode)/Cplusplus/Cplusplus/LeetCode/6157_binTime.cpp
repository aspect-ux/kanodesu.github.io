#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        string t = "";
        int ans = 0,flag = 0,cnt = 0;
        for(char c :s){
            if(c == '1')
            cnt++;
        }
        for(int n = 0;n<cnt;){
            for(int i = 0;i < s.length() - 1; i++){
                t += s[i];
                t += s[i+1];
                if(t == "01")
                {
                    s[i] = '1';
                    s[i+1] = '0';
                    i++;
                }
            }
            if(s[n] == 1){
                n++;
            }
            ans ++;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}