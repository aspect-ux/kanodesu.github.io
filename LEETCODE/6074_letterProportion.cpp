#include<iostream>
using namespace std;
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0,ans = 0;
        for(char c : s){
            if(c == letter){
                cnt ++;
            }
        }
        return cnt*100/s.length();
    }
};
int main(){

    system("pause:");
    return 0;
}