#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> hash;
        int offset = 0,leave = 0;
        for(int c:nums){
            hash[c]++;
        }
        for(auto &[x,y]:hash){
            offset += y/2;
            leave +=  y%2;
        }
        return {offset,leave};
    }
};
int main(){
   
    system("pause:");
    return 0;
}