#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans = s;
        int i = 0;
        for(; i < s.length(); i++){
            if(s[i] != ' ')break;
        }
        ans = ans.substr(i);
        i = ans.size() - 1;
        for(; i >= 0; i--){
            if(ans[i] != ' ')break;
        }
        ans.substr(0,i+1);
        vector<string> a;
        for(int i = 0; i < ans.size(); i++){
            string tmp;
            while(i<ans.size()&&ans[i]!=' '){
                tmp += ans[i];
                i++;
            }
            if(tmp.size()==0)cout<<"?";
            a.push_back(tmp);
        }
        reverse(a.begin(),a.end());
        string res;
        for(string c:a){
            res+=c+" ";
        }

        return res.substr(0,res.size()-1);

    }
};
int main(){
   
    system("pause:");
    return 0;
}