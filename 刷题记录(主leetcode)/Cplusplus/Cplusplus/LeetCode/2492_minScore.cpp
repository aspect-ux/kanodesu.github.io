#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> e[n + 1],v[n + 1];
        for (auto &road : roads)
        {
            e[road[0]].push_back(road[1]);
            v[road[0]].push_back(road[2]);
            e[road[1]].push_back(road[0]);
            v[road[1]].push_back(road[2]);
        }
        int ans = 1e9;
        //bfs
        queue<int> q;
        bool vis[n + 1];
        memset(vis,0,sizeof(vis));
        q.push(1);vis[1] = true;
        while (!q.empty())
        {
            int sn = q.front();q.pop();
            for (int i= 0; i < e[sn].size(); i ++) {
                ans = min(ans,v[sn][i]);
                int fn = e[sn][i];
                if (vis[fn]) continue;
                q.push(fn);vis[fn] = true;
            }
        }
        return ans;
    }
};