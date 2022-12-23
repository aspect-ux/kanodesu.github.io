#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(),n = b.length(),fc = 0;
        string ans;
        string t;
        if (m > n) {
            t = a.substr(0,m - n);
            a = a.substr(m - n,n);
        }
        else {
            t = b.substr(0,n - m);
            b = b.substr(n - m,m);
        }
        for (int i = min(m,n) - 1; i >= 0; i --) {
            int tmp = (a[i] - 48 + b[i] - 48);
            if (tmp == 0) {
                if (fc){
                    ans += '1';
                    fc = 0;
                }
                else
                ans += '0';
            }
            if (tmp == 1) {
                if (fc){
                    ans += '0';
                    fc = 0;
                }
                else
                ans += '1';
            }
            if (tmp == 2) {
                if (fc){
                    ans += '1';
                }else{
                    //fc = 1;
                    ans += '0';
                }
                
            }
            
            cout<<tmp<<' '<<fc<<endl;
        }
        for (int i = t.size()-1; i >= 0; i --) {
            if (t[i] == '1'){
                if (fc) {
                    ans += '0';
                }else{
                     ans += '1';
                }
            }else{
                if (fc) {
                    ans += '1';
                    fc = 0;
                }
                else ans += '0';
            }
        }
        if (fc) {ans += '1';cout<<"?";}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};