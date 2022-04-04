#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> hash;
        unordered_map<int,int>::iterator it;
        vector<vector<int>> ans;
        vector<int> temp,temp1;
        for(int  i = 0; i < matches.size(); i++){
           if(hash.find(matches[i][0]) == hash.end()){ //不存在才能插入
                hash.insert({matches[i][0],0});
            }
             if(hash.find(matches[i][1]) == hash.end()){ //不存在才能插入
             hash.insert({matches[i][0],0});
            }
            hash[matches[i][1]]+=1;   //输的次数增加
        }
  
        for(it = hash.begin();it != hash.end(); it++){
            if((*it).second == 0){
                temp.push_back((*it).first);
            }
           if((*it).second == 1){
                temp1.push_back((*it).first);
            }
        }
        sort(temp.begin(),temp.end());
        sort(temp1.begin(),temp1.end());
        ans.push_back(temp);
        ans.push_back(temp1);
        return ans;


        
    }
};
int main(){
    vector<vector<int>> ans,matches={{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    Solution s;
    ans = s.findWinners(matches);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    }
    system("pause:");
    return 0;
}