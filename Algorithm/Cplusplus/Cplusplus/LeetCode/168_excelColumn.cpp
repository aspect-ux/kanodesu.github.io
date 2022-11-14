#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int a0 = (columnNumber - 1) % 26;
            ans += a0 + 'A';
            columnNumber = (columnNumber - a0) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.convertToTitle(701);
    system("pause:");
    return 0;
}