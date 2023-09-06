#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n = orders.size(),diff = 0;
        priority_queue<int,vector<int>,greater<int>> pq_asc;
        priority_queue<int,vector<int>,less<int>> pq_desc;
        unordered_map<int,int> hash_asc,hash_desc;
        for (int i = 0; i < n; i ++) {
            if (orders[i][3] == 0)
            {
                if(pq_asc.size())
                {
                    diff = orders[i][0] - pq_asc.top();
                    if (diff >= 0)
                    {
                        hash_asc.erase(pq_asc.top());
                    }  
                }
                pq_desc.push(orders[i][0]);
                hash_asc[orders[i][0]] += orders[i][1];
            }else
            {
                pq_asc.push(orders[i][0]);
                hash_asc[orders[i][0]] += orders[i][1];
            }
        }
    }
};