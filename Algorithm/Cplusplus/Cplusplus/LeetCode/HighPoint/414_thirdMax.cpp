#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int n:nums){
            s.insert(n);
            if(s.size() > 3) s.erase(s.begin());
        }
        return s.size()==3?*s.begin():*s.rbegin();
    }
};
int main(){
   
    system("pause:");
    return 0;
}


