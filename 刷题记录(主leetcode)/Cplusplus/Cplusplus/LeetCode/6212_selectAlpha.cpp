#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> hash(26,0);
        unordered_map<int,int> cnt;
        int flag = 0;
        for(auto c : word){
            hash[c - 'a'] ++;
        }
        for(auto c : hash){
            cnt[c] ++;
        }
        if(cnt.size() == 1) return false;
        if(cnt.size() == 2){
            vector<int> a,b;
            for(auto c:cnt) a.push_back(c.first);
            if(abs(a[0] - a[1]) == 1) return true;
            else return false;
        }
        if(cnt.size() > 2) return false;
        return true;
    }
};
int main(){
    
    system("pause:");
    return 0;
}