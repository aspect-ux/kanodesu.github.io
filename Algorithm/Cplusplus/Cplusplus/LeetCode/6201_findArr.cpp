#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 1 0 1 0
// 1 1 1 1
// 0 1 0 1
//A^B = C   A^A = 0
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        arr[0] = pref[0];
        for(int i = 1; i < pref.size(); i ++)
        {
            arr[i] = pref[i - 1] ^ pref[i];
        }
        return arr;
    }
};
int main(){
    
    system("pause:");
    return 0;
}