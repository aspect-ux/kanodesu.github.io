#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        int s = num;
        if(s == 0) return "0";
        if(s<0) num = - num;
        while(num > 0){
            ans.push_back(num%7 + 48);
            num/=7;
        }
        if(s<0) ans.push_back('-');
        reverse(ans.begin(),ans.end());
        
        return ans;

    }
};
int main(){
   
    system("pause:");
    return 0;
}