#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int j = 0,m = s.length(),n = p.length();
        for(int i = 0;i < p.length(); i++){
            if(j == m) return false;
            if(s[j] == p[i] || p[i] == '.'){
                if(j == s.length() - 1) return false;
                j ++;
            }
            else if(p[i] == '*'){
                if(i == 0) return false;
                while(j < m && (s[j] == p[i - 1] || p[i - 1] == '.')){
                    j ++;
                }
            }
            else return false;
        }
        if(j != m) return false;
        return true;
    }
};
int main(){
   
    system("pause:");
    return 0;
}