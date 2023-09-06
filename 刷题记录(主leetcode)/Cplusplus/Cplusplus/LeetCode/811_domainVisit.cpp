#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> ans;
    unordered_map<string,int> hash;
    void domainParse(string s)
    {
        int i = 0;
        string visit;
        while(s[i] != ' '){
            visit += s[i];
            i ++;
        }
        visit += ' ';
        i ++;
        while(i < s.size())
        {
            hash[s.substr(i)] += stoi(visit);
            while(s[i] != '.'){
                i ++;
                if(i == s.size()) break;
            }i++;
        }
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        for(int i = 0; i < n; i ++)
        {
            domainParse(cpdomains[i]);
        }
        for(auto c : hash) ans.push_back(to_string(c.second) + ' ' + c.first);
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}