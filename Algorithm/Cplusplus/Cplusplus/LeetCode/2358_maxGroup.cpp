#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool cmp(int a,int b){
        return a>b;
    }
    int maximumGroups(vector<int>& grades) {
        int pre = 0,now = 0;
        sort(grades.begin(),grades.end(),cmp);
        pre = grades[0];
        for(int i = 1;i < grades.size(); i++){
            if(now <= pre){
                now += grades[i];
            }
            else{
                pre = now;
                now = 0;
            }
        }

    }
};
int main(){
   
    system("pause:");
    return 0;
}