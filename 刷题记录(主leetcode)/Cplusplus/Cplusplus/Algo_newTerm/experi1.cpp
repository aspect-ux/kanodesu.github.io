#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    unordered_map<int,int> hash;
    void recordNum(vector<int>&a){
        for(int c : a){
            cout<<hash[c]+1<<' ';
            hash[c]++;
        }

    }
};
int main(){
    int n = 0;
    cout<<"INPUT N:"<<endl;
    cin>>n;
    cout<<"INPUT ARRAY:"<<endl;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin>>a[i];
    }
    Solution s;
    s.recordNum(a);
    system("pause:");
    return 0;
}