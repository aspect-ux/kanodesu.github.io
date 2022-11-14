#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int commonFactors(int a, int b) {
        int m = max(a,b),n = min(a,b),cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(m%i == 0&&n%i == 0) cnt ++;
        }
        return cnt;
    }
};
int main(){
    
    system("pause:");
    return 0;
}