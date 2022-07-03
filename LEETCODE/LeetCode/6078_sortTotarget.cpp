#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> hashs,hasht;
        int m = s.length(),n = target.length(),cnt = 0;
        sort(target.begin(),target.end());
        if(m < n) return 0;
        for(int i = 0;i < n; i++){
            hasht[target[i]] ++;
        }
        for(int i = 0 ; i < m; i ++ ){
            if(hasht.find(s[i]) != hasht.end()){ //找到
                hashs[s[i]] ++;
            }
        }
        int stop = 0;
        while(1){
            for(auto c : hasht){
            hashs[c.first] -= c.second;
                if(hashs[c.first] < 0){
                    stop = 1;
                    break;
                }
            }
            if(stop)break;
            cnt ++;
        }
        return cnt;
    }
};
int main(){
    system("pause:");
    return 0;
}