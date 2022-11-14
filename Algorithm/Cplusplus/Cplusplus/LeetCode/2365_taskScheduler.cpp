#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0,yasumi = 0;
        unordered_map<int,int> hash;
        for(int i = 0;i < tasks.size(); i++){
            if(hash.find(tasks[i]) == hash.end())
                hash[tasks[i]] = i;
            else{
                auto it = hash.find(tasks[i]);
                day += abs(i - it->second);
            }
            day ++;
        }
        return day;
    }
};
int main(){
   
    system("pause:");
    return 0;
}