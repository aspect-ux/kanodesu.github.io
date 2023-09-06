#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int n = flowerbed.size(),flag = 0, place = 0;
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            n --; 
            flowerbed[0] = 1;
        }
        for(int i = 1; i < n - 1; i++){
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                n --;
            }
        }
        if(flowerbed[n - 1] == 0 && flowerbed[n - 2] == 0) n --;
        if(n == 0) return true;
        return false;
    }
};
int main(){
   
    system("pause:");
    return 0;
}