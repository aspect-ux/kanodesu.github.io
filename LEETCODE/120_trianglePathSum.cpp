#include<iostream>
#include<vector>
using namespace std;
/*class Solution {  //超时了....
public:
    int flag = 0;
     void backtrace(vector<vector<int>>& triangle,int pos,int j,int ans,int n,vector<int> &res){
        if(pos == n){
            if(!flag)
            res.push_back(ans);
            flag++;
            res[0] = min(res[0],ans);
            return;
        }
        int m = ans + triangle[pos][j];
         if(j<=pos){
             backtrace(triangle,pos + 1,j,m,n,res);
         }
       
        if(j+1<=pos){
            m = ans + triangle[pos][j+1];
            backtrace(triangle,pos + 1,j + 1,m,n,res);
        }
       
     }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(),ans = 0;
        vector<int> res;
        backtrace(triangle,0,0,ans,n,res);
        return res[0];

    }*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    return triangle[0][0];


    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<s.minimumTotal(v);
    system("pause:");
    return 0;
}