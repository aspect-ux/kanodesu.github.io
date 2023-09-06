#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
// 24 * 60
    int parseString(string t)
    {
        return ((t[1] - '0') + (t[0] - '0') * 10) * 60 + ((t[4] - '0') + (t[3] - '0') * 10);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int a1 = parseString(event1[0]),a2 = parseString(event1[1]);
        int b1 = parseString(event2[0]),b2 = parseString(event2[1]);
        if (a1 > a2) a1 = a1 - 24*60;
        if (b1 > b2) b1 = b1 - 24*60;
        int c1 = max(a1,b1),c2 = min(a2,b2);
        return c2 - c1 >= 0;
    }
};
int main(){
    
    system("pause:");
    return 0;
}