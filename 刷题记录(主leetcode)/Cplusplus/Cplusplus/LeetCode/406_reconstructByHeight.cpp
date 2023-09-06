#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        int m = people.size();
        vector<vector<int>> ans(m,vector<int>(2));
        for(int i = 0; i < m; i ++){
            ans[people[i][1]][0] = people[i][0];
            ans[people[i][1]][1] = people[i][1];
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}