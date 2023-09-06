#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int transfer(int a){
        int b = 0;
        if(a < 10) return a*10;
        while(a>0){
            b = b*10 + a%10;
            a/=10;
        }
        return b;
    }
    int numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> hash;
        unordered_set<int> store;
        int a = 0,b = a;
        for(int i = 0;i < nums.size();i++){
            a = nums[i];
            b = transfer(nums[i]);
            if(store.find(a)!=store.end() && store.find(b)!=store.end())
            {
                store.insert(nums[i]);
                hash[abs(a-b)] ++;
            }
        }
        long long sum = 0;
        for(auto c:hash)
        sum += ((c.second-1)+1)*(c.second-1)/2;
        return sum%((long)10e9);
    }
};
int main(){
   
    system("pause:");
    return 0;
}