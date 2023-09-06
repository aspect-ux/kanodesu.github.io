#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> hash;
        int sum = 0,flag = 0;
        for(char c : s)hash[c] ++;
        for(auto &[x,y] : hash){
            if(y %2 == 0) sum += y;
            else{
                sum += y - 1;
                flag = 1;
            }
        }
        if(!flag) return sum;
        return sum + 1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}
