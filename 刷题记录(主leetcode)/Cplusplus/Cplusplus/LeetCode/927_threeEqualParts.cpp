#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size(),cnt = 0;
        vector<int> dp(n,0);
        for (int i = 1; i < n; i ++)
        {
            if(arr[i] == 1)
            cnt ++;
        }
        if(cnt == 0) return {0,2};
        if(cnt % 3 != 0) return {-1,-1};
        int len = cnt/3,first = 0,second = 0,third = 0,tmp = 0;
        for (int i = 0; i < n; i ++)
        {
            if(arr[i] == 1)
            {
                tmp ++;
                if(tmp == 1){
                    first = i;
                }else if(tmp == len + 1){
                    second = i;
                }else if(tmp == 2*len + 1){
                    third = i;
                }
            }
        }
        while(third < n)
        {
            if(arr[first] == arr[second]&&arr[second] == arr[third])
            {
                tmp ++;
                first++;
                second++;
                third++;
                continue;
            }else return {-1,-1};
        }
        return {first - 1,second - 1};
    }
};
int main(){
    
    system("pause:");
    return 0;
}