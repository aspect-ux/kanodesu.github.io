#include<iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        // if(n == 0) return 0;
        // if(n == 1) return 1;
        // return fib(n - 1) + fib(n - 2);
        //动态规划
        int a = 0,b = 1,c = 0;
        if(n == 0) return a;
        if(n == 1) return 1;
        for(int i = 0; i < n - 1; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
int main(){
   
    system("pause:");
    return 0;
}