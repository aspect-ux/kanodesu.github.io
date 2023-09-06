#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int reverseInteger(int a) {
        int b = 0;
        while(a > 0){
            b = b * 10 + a %10;
            a/=10;
        }
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> hash;
        int cnt = 0;
        for (auto c : nums) hash.insert(c);
        for (auto c : nums) {
            hash.insert(reverseInteger(c));
        }
        return hash.size();
    }
};
int main(){
    
    system("pause:");
    return 0;
}