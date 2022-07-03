#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int cnt = 0,margin = 0,j,n = answers.size();
        sort(answers.begin(),answers.end());
        for(int i = 0; i < n; i++){
            j = answers[i];
            if(j >= n){
                j = n - 1;
            }
            if(answers[i] == answers[j]){
                cnt += answers[i] + 1;
            }
            while(answers[i] != answers[j]){ 
                j --;
                margin ++; //少了
            }
            cnt += margin;
        }
        return cnt;
    }
};
int main(){

    system("pause:");
    return 0;
}