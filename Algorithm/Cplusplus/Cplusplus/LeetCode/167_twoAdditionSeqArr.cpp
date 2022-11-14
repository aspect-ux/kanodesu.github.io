#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0, j = numbers.size() - 1;;){
            if(numbers[i] + numbers[j] > target){
                j --;
            }else if(numbers[i] + numbers[j] == target) return {i+1,j+1};
            else if(numbers[i] + numbers[j] < target) i ++;
        }
        return {};
    }
};
int main(){
    
    system("pause:");
    return 0;
}