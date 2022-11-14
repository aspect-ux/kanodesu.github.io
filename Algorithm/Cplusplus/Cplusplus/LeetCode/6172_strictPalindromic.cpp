#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string binParse(int b){
        string m = "";
        while(b>0){
            m  += (b%2 + '0');
            b/=2;
        }
        return m;
    }
    bool isStrictlyPalindromic(int n) {
        string tmp1,tmp2;
        for(int i = 2;i < n-1;i++){
            tmp1  = binParse(i);
            tmp2 = tmp1;
            reverse(tmp1.begin(),tmp1.end());
            if(tmp1!=tmp2) return false;

        }
        return true;
    }
};
int main(){
   
    system("pause:");
    return 0;
}