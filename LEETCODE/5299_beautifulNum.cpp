#include<iostream>
using namespace std;
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for(int i = 0; i < s.size() - k + 1; i++){
            int tmp = stoi(s.substr(i,k));
            if(num%tmp==0&& tmp != 0){
                ans ++;
            }
            if(tmp == 0) continue;
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}