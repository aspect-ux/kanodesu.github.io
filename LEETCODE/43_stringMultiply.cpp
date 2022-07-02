#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int toInt(char c){
        return c - 48;
    }
    string multiply(string num1, string num2) {
        string ans;
        int fc = 0,m = num1.size(),n = num2.size(),tmp,leave = 0,res = 0;
        for(int i = n - 1; i >= 0; i++){
            for(int j = m - 1; j >= 0; j++){
                tmp = toInt(num2[i]) * toInt(num1[j]);
                leave = tmp%10;
                fc = tmp/10;          //计算当前进位
                res += leave*10 + fc;
            }
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}