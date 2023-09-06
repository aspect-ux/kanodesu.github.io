#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        int n = path.size();
        unordered_set<int> obsolete,cnt;
        unordered_map<int,int> hash;

        for(int i = 0; i < n; i ++){
            cnt.insert(path[i][0]);
            cnt.insert(path[i][1]);
            obsolete.insert(path[i][0]);
            hash[path[i][1]] ++;
        }
        for(auto c : hash){
            if(obsolete.find(c.first) != obsolete.end()) continue;
            if(c.second == cnt.size() - 1) return c.first;
        }
        return -1;
    }
};
int main(){
    
    system("pause:");
    return 0;
}