#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int fl = 0;
    int istrue(int c){
        if(c == 2 || c == 3 || c == 0){fl = 1;return fl;}
        if(c == 1) {
            fl = 0;
            return fl;
        }
        if(c>= 3 && (c-3) != 1)
        {
            c-=3;
            istrue(c);
        }
        else {
            c-=2;
            istrue(c);
        }
        return fl;
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> hash;
        for(int i = 0;i < tasks.size(); i++){
            if(hash.find(tasks[i]) == hash.end()){
                hash.insert({tasks[i],1});  //没有就插入
            }
            else{
                hash[tasks[i]] ++;
            }
        }
        for(auto c:hash){
            cout<<c.first<<' '<<c.second<<endl;
        }
        int flag = 0;
        for(auto c: hash){
            if(istrue(c.second)){
                continue;
            }
            else flag = 1;
        }
        if(flag) return -1;
        else {
            int ans = 0,temp = 0;
                for(auto c: hash){
                    while(c.second>=3 &&(c.second - 3) != 1){
                        ans ++;
                        c.second -= 3;
                    }
                    while(c.second % 2 == 0 && c.second != 0){
                         c.second -= 2;
                         ans++;
                    }
                     cout<<ans - temp<<endl;
                     temp = ans;
                   
                }
                return ans; 
            }
             
    }
};
int main(){
    Solution s;
    vector<int> tasks={66,66,63,61,63,63,64,66,66,65,66,65,61,67,68,66,62,67,61,64,66,60,69,66,65,68,63,60
    ,67,62,68,60,66,64,60,60,60,62,66,64,63,65,60,69,63,68,68,69,68,61};
    cout<<s.minimumRounds(tasks);
    system("pause:");
    return 0;
}