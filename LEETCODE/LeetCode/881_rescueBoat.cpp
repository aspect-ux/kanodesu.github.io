#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0,n = people.size();
        sort(people.begin(),people.end());
        for(int i = 0,j = n - 1;i <= j;j --){
            if(i == j){ans++;break;}
            if(people[j] + people[i] <= limit) i++;
            ans++;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}