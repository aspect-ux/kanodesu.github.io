#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct cmp1{
        bool operator()(const pair<int,int> l,const pair<int,int> r)
        {
            if (l.first != r.first)return l.first > r.first;
             else return l.second < r.second;
        }
    };
    bool static cmp(const pair<int,int> & l,const pair<int,int> &r)
    {
        if (l.first != r.first)return l.first > r.first;
             else return l.second < r.second;
    }
    int caculateScore(unordered_set<string> &positive,unordered_set<string> &negative,string report)
    {
        int n = report.length(),score = 0;
        for (int i = 0; i < n; i ++) {
            string remark;
            while (i < n && report[i] != ' ')
            {
                remark += report[i];
                i ++;
            }
            if (positive.find(remark) != positive.end()) score += 3;
            if (negative.find(remark) != negative.end()) score -= 1;
        }
        return score;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback,
     vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positive,negative;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> pq;
        vector<pair<int,int>> v;
        vector<int> res;
        for (auto c : positive_feedback) positive.insert(c);
        for (auto c : negative_feedback) negative.insert(c);
        int n = report.size();
        for (int i = 0; i < n; i ++) {
            //pq.push({caculateScore(positive,negative,report[i]),student_id[i]});
            v.push_back({caculateScore(positive,negative,report[i]),student_id[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for (int i = 0 ; i < k; i ++) {
            //res.push_back(pq.top().second);
            //pq.pop();
            res.push_back(v[i].second);
        }
        return res;
    }
};