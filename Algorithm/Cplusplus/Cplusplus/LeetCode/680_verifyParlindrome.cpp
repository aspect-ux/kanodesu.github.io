#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int flag = 0;
    bool dfs(string s,int i,int j){
        if(i >= j) return true;
        while(i < j){
            while(i < j && s[i] == s[j]){
                i --;
                j --;
            }
            if(s[i] != s[j] && flag) return false;
            if(s[i] != s[j]){
                flag = 1;
                return dfs(s,i + 1,j) || dfs(s,i,j-1);  
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return dfs(s,0,s.length() - 1);
    }
};
int main(){
    
    system("pause:");
    return 0;
}