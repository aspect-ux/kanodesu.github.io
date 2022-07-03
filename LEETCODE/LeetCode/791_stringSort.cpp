#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> hash;
         unordered_map<char,int> cnt;
       //这里要注意，循环中可能因erase动态改变循环次数,所以要提前固定好次数,所以一定要调整j
        for(int j = 0;j < order.size(); j++){
            if(s.find(order[j])>=s.size()){
                order.erase(j,1);
                j--;//!!!!
            }
        }
        for(int i = 0; i < order.size(); i ++){
            hash[order[i]] = i;
            cnt[order[i]] = 0;
        }
        //此时得到一个精简版order<=s;
        string ans = order,temp;
        for(char c:s){
            if(hash.find(c)!=hash.end()){
                if(cnt[c]){
                    ans.insert(hash[c] + cnt[c],1,c);//to_string只能将整数转字符串，字符会默认成ascii
                }
                cnt[c]++;
                hash[c] = //错了，刻舟求剑.....
            }
            else temp.push_back(c);  
        }
        ans += temp;
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.customSortString("cbafg","abcd");
    system("pause:");
    return 0;
}