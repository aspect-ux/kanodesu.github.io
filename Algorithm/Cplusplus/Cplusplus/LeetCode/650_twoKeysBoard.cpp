#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i < n / i; i ++){
            while(n % i == 0){
                res += i;
                n /= i;
            }
            if(n > 1) res += n;
        }
        return res;
    }
};
int main(){
    
    system("pause:");
    return 0;
}