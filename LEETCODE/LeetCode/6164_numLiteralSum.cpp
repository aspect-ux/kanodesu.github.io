#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int literalParse(int num){
        string s = to_string(num);
        int sum = 0;
        for(char c : s){
            sum += c - 48;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> hash;
        int temp,ans = 0;
        for(int i = 0;i < nums.size(); i++){
            temp = literalParse(nums[i]);
            if(hash.find(temp) != hash.end()){
                cout<<1<<endl;
                auto it = hash.find(temp);
                ans = max(ans,(*it).second + nums[i]);
                if((*it).second < nums[i]){
                    hash.erase(temp);
                }
                else continue;
            }
            hash.insert({temp,nums[i]});
            cout<<temp<<endl;
        }
        return ans;
    }
};
int main(){
   
    system("pause:");
    return 0;
}