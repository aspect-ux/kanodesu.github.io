#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
//重写sort的cmp函数要设为static
    bool static sortFloat(pair<int,int>&ans,pair<int,int> ans1){
       /*  pair<int,int> temp;
        for(int i=0;i<ans.size() - 1;i++){
            for(int j=i+1;j<ans.size();i++){
                if(ans[i].first*ans[j].second > ans[j].first*ans[i].second){
                    temp = ans[i];
                    ans[i] = ans[j];
                    ans[j] = temp;
                }
            }
            k--;
            if(k == 0){
                return;
            }
        } */
        return ans.first*ans1.second < ans1.first*ans.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>> ans;
        pair<int,int> res;
        for(int i = 0;i < arr.size() - 1;i++){
            for(int j = i + 1;j < arr.size();j++){
                 ans.push_back({arr[i],arr[j]});
            }
        }
        sort(ans.begin(),ans.end(),sortFloat);

        return {ans[k-1].first,ans[k-1].second};
    }
};
int main(){
   
    system("pause:");
    return 0;
}