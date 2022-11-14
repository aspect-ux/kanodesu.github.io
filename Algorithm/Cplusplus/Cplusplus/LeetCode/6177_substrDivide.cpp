#include<iostream>
using namespace std;
class Solution {
public:
    // string ans;
    // string tmp;
    // void dfs(string s,int n){
    //     if(n == s.length())return;
    //     if(tmp.find(s[n])!=-1) tmp += s[n];
        
    // }
    int partitionString(string s) {
        string tmp = "";
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            //没找到：可分，可不分
            //找到:分
            if(tmp.find(s[i]) != -1){
                tmp += s[i];
            }
            else{
                tmp.resize(0);
                cnt ++;
            }
        }
        return cnt + 1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}