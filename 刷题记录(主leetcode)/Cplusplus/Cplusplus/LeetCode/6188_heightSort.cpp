#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> hash;
        int n = names.size();
        vector<string> ans;
        for(int i = 0; i < n; i ++){
            hash[heights[i]] = names[i];
        }
         map<int,string> :: iterator it = hash.end();
         it --;
        while(it != hash.begin()){
            ans.push_back(it->second);
            it --;
        }
        ans.push_back(it->second);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}