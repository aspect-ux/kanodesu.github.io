#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size(),t1 = 0,t2 = 0,t3 = 0,ans = 0;
        for(int i = 0; i < n - 1; i ++){
            if(temperatureA[i+1] - temperatureA[i] > 0 &&temperatureB[i+1] - temperatureB[i] > 0){
                t1 ++;
            } else if(temperatureA[i+1] - temperatureA[i] == 0 &&temperatureB[i+1] - temperatureB[i] == 0){
                t2++;
            }else if(temperatureA[i+1] - temperatureA[i] < 0 &&temperatureB[i+1] - temperatureB[i] < 0){
                t3 ++;
            }else{
                t1 = 0,t2 = 0,t3 = 0;
            }
            ans = max(ans,t1+t2+t3);
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}