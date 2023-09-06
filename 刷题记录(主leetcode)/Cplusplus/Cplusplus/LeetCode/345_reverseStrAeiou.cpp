#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> hash = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0, j = s.length() - 1; i <= j;i++,j--){
            while(i <= j && hash.find(s[i])==hash.end()){
                i ++;
            }
            while(i<= j &&hash.find(s[j])==hash.end()){
                j --;
            }
            swap(s[i],s[j]);
        }
        return s;
    }
};
int main(){
    
    system("pause:");
    return 0;
}