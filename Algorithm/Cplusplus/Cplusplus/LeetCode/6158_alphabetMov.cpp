#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//差分数组
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),m=shifts.size();
        int a[n+1];
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++){//构造数组
            int tem=1;
            if(shifts[i][2]==0)tem=-1;
            a[shifts[i][0]]+=tem;
            a[shifts[i][1]+1]-=tem;
        }
        int sum=a[0];
        for(int i=0;i<n;i++){//加入数组
            int tem=(s[i]-'a'+sum)%26;
            if(tem<0)tem+=26;//-会变成负数
            s[i]=tem+'a';
            sum+=a[i+1];
        }
        return s;
    } 
};
int main(){
    system("pause:");
    return 0;
}