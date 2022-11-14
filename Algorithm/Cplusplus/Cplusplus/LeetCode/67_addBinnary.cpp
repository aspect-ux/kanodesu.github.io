#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(),n = b.length(),i = 0,tmp,fc = 0;
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(i<m||i<n){
            tmp = (int)(i<m?(a[i]-48):0) +(int) (i<n?(b[i]-48):0)+ fc;
            ans += '0' + (tmp >=2?(tmp-2) : tmp); 
            if(tmp >=2) fc = 1;
            else fc = 0;
            i++;
        }
        if(fc == 1)ans+='1';
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.addBinary("11","1");
    system("pause:");
    return 0;
}