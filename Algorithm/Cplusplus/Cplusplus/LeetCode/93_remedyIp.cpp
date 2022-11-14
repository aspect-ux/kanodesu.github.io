#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void dfs(string s,int pos,int leave){
        if(leave == 1){
            if(s.substr(pos).size() > 3) return;
            else{
                ans.push_back(s);
            }
            return;
        }
        //if()
        for(int i = 0; i < s.length() - 1; i++){
            s.insert(pos,".");
            dfs(s,pos + 1,leave);
            s.erase(pos,1);
        }
        

    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,1,4);
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}