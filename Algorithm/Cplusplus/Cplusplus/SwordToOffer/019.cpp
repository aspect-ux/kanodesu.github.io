#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s){
        for (int i = 0,j = s.length()-1;i < j; i ++,j --)
            if (s[i] != s[j]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        string::iterator it = s.begin();
        for (;it != s.end();it ++)
        {
            string tmp = s;
            string::iterator t = tmp.begin() + (int)(it - s.begin());
            tmp.erase(t);
            if (isPalindrome(tmp)) return true;
        }
        return false;
    }
};
//双指针+切片
class Solution_1 {
public:
    bool isPalindrome(string s){
        for (int i = 0,j = s.length()-1;i < j; i ++,j --)
            if (s[i] != s[j]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        for (int i = 0,j = n - 1; i < j; i ++,j --) {
            if (s[i] == s[j]) continue;
            //优化 因为不用重复判断已经走过的地方
            //string a = s.substr(i,j - i),b = s.substr(i+1,j - i);
            string a = s.substr(0,i) + s.substr(i+1,n - i - 1),b = s.substr(0,j) + s.substr(j+1,n - j - 1);
            if (isPalindrome(a) || isPalindrome(b)) return true;
            else return false; 
        }
        return true;
    }
};
