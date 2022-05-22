#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> margin;
        int cnt = 0,j = 0,tmp;
        for(int i = 0 ;i < capacity.size(); i++){
            tmp = capacity[i] - rocks[i];
            if(tmp == 0){
                cnt ++;
            }
            else{
                margin.push_back(tmp);
            }
        }
        sort(margin.begin(),margin.end());
        while(j<margin.size()&&additionalRocks >= margin[j]){
            additionalRocks -= margin[j];
            cnt ++;
            j++;
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<int> a ={10,2,2},b={2,2,0};
    cout<<s.maximumBags(a,b,100);
    system("pause:");
    return 0;
}