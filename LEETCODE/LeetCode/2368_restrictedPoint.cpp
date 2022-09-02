#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> temp,test;
        vector<vector<int>> hash(n);

        for(int i = 0;i < edges.size(); i++){
            if(find(restricted.begin(),restricted.end(),edges[i][0])!=restricted.end()
            ||find(restricted.begin(),restricted.end(),edges[i][1])!=restricted.end()){
                continue;
            }
            hash[edges[i][0]].push_back(edges[i][1]);
            hash[edges[i][1]].push_back(edges[i][0]);
            cout<<hash[0][0]<<endl;
        }

        stack<int> st;
        int out = 0;
        st.push(0);
        test.insert(0);
        temp.insert(0);
        while(!st.empty()){
            out = st.top();
            st.pop();
            if(hash[out].size() == 0)break;
            for(int c : hash[out]){
                cout<<c<<endl;
                temp.insert(c);
                if(test.find(c)==test.end())
                {
                    st.push(c);
                    test.insert(c);
                }

            }
        }

        return test.size();
    }
};
int main(){
   
    system("pause:");
    return 0;
}