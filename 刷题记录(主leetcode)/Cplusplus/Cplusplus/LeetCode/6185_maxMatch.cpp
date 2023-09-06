#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = min(trainers.size(),players.size()),cnt = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        for(int i = 0,j=0; i < players.size()&&j<trainers.size(); j++){
            if(players[i] <= trainers[j]){
                cnt ++;
                i++;
            }
        }
        return cnt;


    }
};
int main(){
   
    system("pause:");
    return 0;
}