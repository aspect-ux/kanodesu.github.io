#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] == '*') {
                --j;
            } else {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
    }
};
int main(){
   
    system("pause:");
    return 0;
}