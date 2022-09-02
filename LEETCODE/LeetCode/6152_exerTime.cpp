#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hour0 = 0,hour1 = 0,n = energy.size(),sum0 =initialEnergy,sum1=initialExperience;
        for(int i = 0;i < n;i++){
            if(sum0 <= energy[i]){
                hour0 += energy[i] - sum0 + 1;
                sum0 +=  energy[i] - sum0 + 1;
            }
            if(sum1 <= experience[i]){
                hour1 += experience[i] - sum1 + 1;
                sum1 += experience[i] - sum1 + 1;
            }
            sum0 -= energy[i];
            sum1 += experience[i];
        }
        return hour0+hour1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}