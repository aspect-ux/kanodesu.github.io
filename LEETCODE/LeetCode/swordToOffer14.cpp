#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        string tmp;
        int n = s1.length(),m = s2.length();
        for(int i = 0; i < m - n + 1; i++){
            tmp = s2.substr(i,n);
            sort(tmp.begin(),tmp.end());
            if(s1 == tmp) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    
    system("pause:");
    return 0;
}