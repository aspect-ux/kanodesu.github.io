#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;
    int dfs(int n){
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        return dfs(n - 1) +dfs(n-2);
    }
    int climbStairs(int n) {
        return dfs(n);
    }
};
int main(){
   
    system("pause:");
    return 0;
}