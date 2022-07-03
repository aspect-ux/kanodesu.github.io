#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1,j;
        string s ="1";
        for(int i = 1;i < n; i++){
            string next = "";
            j = 0;
            while(j < s.length() - 1){
                if(s[j] == s[j+1]){
                    cnt++;
                }
                else {
                    next += to_string(cnt);
                    next.push_back(s[j]);
                    cnt = 1; 
                }
                j++;
            }
            next += to_string(cnt);
            next.push_back(s[j]);
            cnt = 1; 
            cout<<s<<endl;
            s = next;
        }
        return s;
    }
};
int main(){
    Solution s;
    cout<<s.countAndSay(4);
    system("pause:");
    return 0;
}