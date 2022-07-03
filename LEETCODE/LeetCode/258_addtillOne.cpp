#include<iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int x = num,b = 0,sum = 0;
        while(!(sum <10 && sum > 0)){
             while(x>0){
                sum += x%10;
                x/=10;
            }
        }
        return sum;   
    }
};
int main(){
    system("pause:");
    return 0;
}