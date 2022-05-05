#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
private:
     string s;
public:
    string countAndSay(int n) {
        if(n == 1) {
            s.push_back('1');
            return s;
        }
        s = countAndSay(n-1);
         string ans;
         char temp = s[0];
         int t = 0;
        for(int i = 0;i < s.length(); i++){
            if(temp != s[i]) {
                ans.push_back((char)t);
                ans.push_back(temp);
                temp = s[i];
                t = 1;
            }
            else t++;
        }
        return ans; 

    }
};
int main(){
    Solution s;
    cout<<s.countAndSay(4);
    system("pause:");
    return 0;
}