#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         //三个不满 retrun false
//         //三个满，如果4一样，是重开还是连续，要看下一个是否有第二个，无return false 有 必定连接，多余的放入栈中。
//         int n = nums.size(),cnt = 1;
//         vector<stack<int>> v;
//         for(int i = 0; i < n; i++){
//             stack<int> st;
//             while(i < n && st.size()!=3){
//                 if(st.empty() || st.top() + 1 == nums[i]){
//                     st.push(nums[i]);
//                     i ++;
//                 }
            
//             }
//             if(i == n && st.size()!=3) return false;
//             else if(i == n && st.size() == 3) return true;
//             else if(st.size() == 3) v.push_back(st);
//             else{
//                 while(i < n && st.top()==nums[i]){
//                     i ++;
//                 }
//             }


//         }
//     }
// };
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
//         for (auto& x : nums) {
//             if (mp.find(x) == mp.end()) {
//                 mp[x] = priority_queue<int, vector<int>,greater<int>>();
//             }
//             if (mp.find(x - 1) != mp.end()) {
//                 int prevLength = mp[x - 1].top();
//                 mp[x - 1].pop();
//                 if (mp[x - 1].empty()) {
//                     mp.erase(x - 1);
//                 }
//                 mp[x].push(prevLength + 1);
//             } else {
//                 mp[x].push(1);
//             }
//         }
//         for (auto it = mp.begin(); it != mp.end(); ++it) {
//             priority_queue<int, vector<int>,greater<int>> queue = it->second;
//             if (queue.top() < 3) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
//1 1 2 2 3 3
//
// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
//         unordered_map<int, int> cnt, subs;
//         for (int e : nums) ++cnt[e];
//         for (int e : nums)
//             if (!cnt[e]) continue;
//             else if (subs[e-1]) { --cnt[e]; --subs[e-1]; ++subs[e]; }
//             else if (cnt[e+1] && cnt[e+2]) { --cnt[e]; --cnt[e+1]; --cnt[e+2]; ++subs[e+2]; }
//             else return false;
//         return true;
//     }
// };

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> hash1,hash2;
        for(auto c : nums) hash1[c] ++;
        for(auto c : nums){
            if(!hash1[c]) continue;
            if(hash2[c - 1]){
                hash2[c - 1] --;
                hash2[c] ++; 
            }else if(hash1[c+1] && hash1[c+2]){
                hash2[c+2] ++;
                hash1[c] --; hash1[c + 1] --; hash1[c + 2] --;
            }else return false;
        }
        return true;
    }
};
int main(){
   
    system("pause:");
    return 0;
}

// 1 2 3 3 4 5
// 1 2 3    3 4 5

//1,2,3,3,4,4,5,5
// 1 2 3   3 4 5  4 5

//3 4 5   4 5