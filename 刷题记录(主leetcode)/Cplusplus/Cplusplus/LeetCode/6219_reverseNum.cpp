#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int reverseInteger(int a) {
        int b = 0;
        while(a > 0){
            b = b * 10 + a %10;
            a/=10;
        }
        return b;
    }
    bool sumOfNumberAndReverse(int num) {
        for (int i = num; i >= 0; i --) {
            if (reverseInteger(i) + i == num) return true;
        } 
        return false;
    }
};
int main(){
    
    system("pause:");
    return 0;
}