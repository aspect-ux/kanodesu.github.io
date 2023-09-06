#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
int main(){
    int n = 0;
    //cin>>n;
    unordered_set<int> hash;
    vector<int> res(16,0);
    vector<vector<int>> ans(16,vector<int>());
    vector<int> row(16);
    vector<vector<int>> dp={{1,2,3,4},{3,4,5,6},{1,6,3,4},{4,2,5,3}};
    for(int i=0;i<4;i++){
        for(int j=0;j<1;j++){   
            hash.insert(dp[i][j]);   
        }
    }
     for(int i=1;i<4;i++){
        unordered_set<int> hash1;
        for(int j=0;j<4;j++){   
              if(hash.find(dp[i][j])!=hash.end()){
               //第一行中有，就放入hash1;
                hash1.insert(dp[i][j]);
              }
        }
        hash = hash1; //更新hash
        hash1.clear();
    }
    for(auto c:hash){
        row.push_back(c);
    }
    sort(row.begin(),row.end());
    for(auto c:hash){
       cout<<c<<' '<<endl;
    }
    system("pause:");
    return 0;
}