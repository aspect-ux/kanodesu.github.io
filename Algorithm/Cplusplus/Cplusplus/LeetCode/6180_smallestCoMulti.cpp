#include<iostream>
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n == 1) return 2;
        else{
            for(int i = n; i < 301; i ++){
                if(i % 2 == 0 && i%n==0)
                    return i;
            }
        }
        return 0;
    }
};
int main(){
   
    system("pause:");
    return 0;
}
