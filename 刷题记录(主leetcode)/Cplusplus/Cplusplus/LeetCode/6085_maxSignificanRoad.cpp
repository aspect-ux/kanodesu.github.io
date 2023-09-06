#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //1.求出度数排行2.求出最大值
        //int n = roads.size();
        unordered_map<int,int> select;
        unordered_map<int,vector<int>> relation;
        vector<vector<int>> hash(n,vector<int>(n+1,0));  //多一个用来存次数
        for(int i = 0 ; i < n; i++){
           hash[roads[i][0]][0] ++;
           hash[roads[i][1]][0] ++;//把roads所有数遍历一遍并将度数存入hash第一列
           hash[roads[i][0]][1] = roads[i][0]; //把城市序号存入第二列
           hash[roads[i][1]][1] = roads[i][1];
        }
        sort(hash.begin(),hash.end());
        for(int i = 0; i < n; i++){
            select[hash[i][1]] = n - i;   //建立查询表
        }
        for(int i = 0 ; i < n; i++){
            relation[roads[i][0]].push_back(roads[i][1]);
        }
        long long ans = 0;
        for(auto c : relation){
            for(auto m : c.second){
                ans += select[m] + select[c.first];
            }
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}