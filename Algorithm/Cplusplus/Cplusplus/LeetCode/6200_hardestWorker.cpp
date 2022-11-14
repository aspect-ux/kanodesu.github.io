#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int index = 0,value = logs[0][1];
        vector<int> ans;
        ans.push_back(logs[0][0]);
        for (int i = 1; i < logs.size(); i ++)
        {
            if(logs[i][1] - logs[i - 1][1] >= value)
            {
                value = logs[i][1] - logs[i - 1][1];
                if(logs[i][1] - logs[i - 1][1] != value) {
                    ans.resize(0);
                    ans.push_back(logs[i][0]);
                }
                else ans.push_back(logs[i][0]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};
int main(){
    
    system("pause:");
    return 0;
}