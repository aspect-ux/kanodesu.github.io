#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int count(string t){
        int res = 0;
        for(char c:t){
            if(c == ' ')
            res ++;
        }
        return ++res;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> hash; // name cnt
        for(int i = 0; i < senders.size(); i++){
            hash[senders[i]] += count(messages[i]);
        }
        string ans = "",max = ans;
        //要返回字典序最大，那么排序hash就行
        vector<vector<string>> v(hash.size(),vector<string>(2,0));
        int n = 0;
        for(auto c : hash){
            v[n][0] = c.first;
            v[n][1] = to_string(c.second); 
            n++;
        }
        sort(v.begin(),v.end());
        for(int j = 0 ; j < hash.size(); j++){
            if(v[j][1] >= max){   // = 很关键
                max = v[j][1];
                ans = v[j][0];
            }
        }
        return ans;
    }
};
int main(){
    system("pause:");
    return 0;
}