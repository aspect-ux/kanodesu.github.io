#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),oil = 0,index = 0,flag = 1;
        for(int i = 0;i < n; i++){
            if(oil + gas[i] >= cost[i]){
                if(flag) {
                    index = i;
                    flag = 0;
                }
                oil += gas[i] - cost[i];
            }
            else{
                flag = 1;
                i = index;
            }
        }
        return index;

    }
};
int main(){
   
    system("pause:");
    return 0;
}