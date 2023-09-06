#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> hash;
        int n = s.length();
        for(int i = 0;i < n;i++){
            if(hash.find(s[i])==hash.end()){
                hash[s[i]] = i;
            }
            else{
                auto it = hash.find(s[i]);
                hash[s[i]] = (i-it->second-1);
            }
        }
        for(int i = 0;i < distance.size();i ++){
            if(hash.find(i + 'a')==hash.end()) continue;
            if(hash[i + 'a'] != distance[i]) return false;
        }
        return true;
    }
};
int main(){
   
    system("pause:");
    return 0;
}