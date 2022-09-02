#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<int> hash(edges.size(),0);
        for(int i = 0;i < edges.size(); i++){
            hash[edges[i]] += i;
        }
        int maxv = 0,maxi = 0;
        for(int i = 0;i < edges.size(); i++){
            if(edges[i] > maxv){
                maxv = edges[i];
                maxi = i;
            }
        }
        return maxi;
    }
};
int main(){
   
    system("pause:");
    return 0;
}