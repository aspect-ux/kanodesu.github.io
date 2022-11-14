#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
// class Solution {
// public:
// //abc
// //bca
//     vector<int> vis;
//     vector<vector<int>> swapable;
//     int ans = 0;
//     void backtrace(string s1,string s2,int pos)
//     {
//         if(pos == s1.length()){
//             ans ++;
//             return;
//         }
//         for(auto &c : swapable[pos])
//         {
//             if(vis[pos]) continue;
//             vis[pos] = 1;
//             swap(swapable[pos],swapable[c]);
//             backtrace(s1,s2,pos + 1);
//             vis[pos] = 0;
//         }
//         if(swapable[pos].size()==0) backtrace(s1,s2,pos + 1);
//     }
//     int kSimilarity(string s1, string s2) {
//         int m = s2.length(),k = 0;
//         swapable.resize(m);
//         vis.resize(m); 
//         for(int i = 0; i < m; i ++)
//         {
//             if(s1[i] == s2[i]) {vis[i]=1;continue;}
//             for(int j = 0; j < m; j ++){
//                 if(s1[i] != s1[j]){
//                     continue;
//                 }
//                 swapable[i].push_back(j);//0 2   
//             }   
//         }
//         backtrace(s1,s2,0);
//         return ans;
//     }
// };
//--------------Astar--------------------启发式搜索
class Solution {
public:
    int minSwap(const string &s1, const string &s2, const int &pos) {
        int tot = 0;
        for (int i = pos; i < s1.size(); i++) {
            tot += s1[i] != s2[i];
        }
        return (tot + 1) / 2;
    }

    int kSimilarity(string s1, string s2) {
        typedef tuple<int, int, int, string> State;
        int n = s1.size();
        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_set<string> visit;
        pq.emplace(0, 0, 0, s1);
        visit.emplace(s1);
        while (!pq.empty()) {
            auto [_, cost, pos, cur] = pq.top();
            pq.pop();
            if (cur == s2) {
                return cost;
            }
            while (pos < n && cur[pos] == s2[pos]) {
                pos++;
            }
            for (int j = pos + 1; j < n; j++) {
                if (s2[j] == cur[j]) {
                    continue;
                }
                if (s2[pos] == cur[j]) {
                    swap(cur[pos], cur[j]);
                    if (!visit.count(cur)) {
                        visit.emplace(cur);
                        pq.emplace(cost + 1 + minSwap(s2, cur, pos + 1), cost + 1, pos + 1, cur);
                    }
                    swap(cur[pos], cur[j]);
                }
            }
        } 
        return 0;
    }
};
int main(){
    Solution s;
    cout<<s.kSimilarity("","");
    system("pause:");
    return 0;
}