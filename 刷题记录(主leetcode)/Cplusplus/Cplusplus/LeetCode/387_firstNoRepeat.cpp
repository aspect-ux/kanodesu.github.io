#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> qu;
        unordered_map<char,int> hash;
        for(char c : s){
            hash[c] ++;
        }
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 1)return i;
            else continue;
        }
        return -1;

    }
};
int main(){
   
    system("pause:");
    return 0;
}