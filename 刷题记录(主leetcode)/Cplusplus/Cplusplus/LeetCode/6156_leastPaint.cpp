#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0,n = blocks.size(),tmp = 0;
        for(int i = 0;i < k;i++){
            if(blocks[i] == 'B') cnt ++;
        }
        for(int j = k;j < n;j ++){
            if(blocks[j] != blocks[j - k]) 
            {
                if(blocks[j] == 'B' && blocks[j - k] == 'W') tmp++;
                else tmp --;
            }
            cnt = max(cnt,cnt + tmp);
        }
        return k - cnt;
    }
};
int main(){
   
    system("pause:");
    return 0;
}