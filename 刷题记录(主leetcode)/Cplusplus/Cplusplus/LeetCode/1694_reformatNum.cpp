#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reformatNumber(string number) {
        int n = number.length();
        string num1,num2;
        for (int i = 0; i < n; i ++)
        {
            if(number[i] == '-'||number[i] == ' ') continue;
            num1 += number[i];
        }
        int m = num1.size(),a = m / 3,b = m%3;
        if(b != 2) {a --,b += 3;}
        for(int i = 0; i < m; i ++)
        {
            if(!a) break;
            if(i%3==0) {num2 += '-'+num1[i];a--;}
            else num2 += num1[i];
        }
        if(b == 4) num2.insert(num2.begin() + num2.size() - 2,'-');

        return num2;
    }
};
int main(){
    
    system("pause:");
    return 0;
}