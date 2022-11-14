#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(),transactions.end(),[&](vector<int>&a,vector<int>&b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);});
        long long money = 0,ans = 0;
        // c[0][0]  c[1][0] - c[0][1]>0
        for(int i = 0; i < transactions.size(); i ++){
            if(transactions[i][0] - transactions[i-1][1] > 0){
                money += transactions[i][0] - transactions[i-1][1];
            }
        }
        return money;
    }
};
int main(){
    
    system("pause:");
    return 0;
}