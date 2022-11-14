#include<iostream>
using namespace std;
class Solution {
    // 0 1 2 3 4
public:
    int mySqrt(int x) {
        long long mid,low = 0,high = x;
        while(low <= high){
            mid = (low + high)/2;
            if(mid * mid > x){
                high = mid;
            }
            else if(mid * mid < x){
                low = mid;
            }
            else return mid;
            if(low + 1 == high) break;
        }
        if(high * high == x) return high;
        return (low + high)/2;
    }
};
int main(){
   
    system("pause:");
    return 0;
}