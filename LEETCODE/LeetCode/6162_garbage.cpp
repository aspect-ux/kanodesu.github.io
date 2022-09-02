#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(),ans1 = 0,ans2 = 0,ans3 = ans2,in1=0,in2=0,in3=0;
        vector<int> dpM(n,0),dpP(n,0),dpG(n,0);
        for(int i = 0;i < n;i++){
            for(char c : garbage[i]){
                if(c == 'M')
                {
                    dpM[i] += 1;
                    in1 = i;
                }
                if(c == 'P')
                {
                    dpP[i] += 1;
                    in2 = i;
                }
                if(c == 'G')
                {
                    dpG[i] += 1;
                    in3 = i;
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(dpM[i])
                ans1 += (i == 0?0:travel[i-1]) + 1*dpM[i];
            if(dpP[i])
                ans2 += (i == 0?0:travel[i-1]) + 1*dpP[i];
            if(dpG[i])
                ans3 += (i == 0?0:travel[i-1]) + 1*dpG[i];
        }
        return ans1+ans2+ans3;

    }
};
int main(){
   
    system("pause:");
    return 0;
}