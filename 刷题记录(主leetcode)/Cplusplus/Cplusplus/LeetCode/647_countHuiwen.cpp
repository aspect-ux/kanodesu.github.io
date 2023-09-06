#include<iostream>
using namespace std;
class Solution {
public:
    int res = 0;
    int iscount(string s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]){
                 return 0;
            } 
            i++;
            j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = 1; j <= s.length() - i; j++){
                ans += iscount(s.substr(i,j),0,s.substr(i,j).length() - 1);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.countSubstrings("aaa")<<endl;

    system("pause:");
    return 0;
}
