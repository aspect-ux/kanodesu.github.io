#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    struct Point{
        int x,y;
        Point(int a,int b):x(a),y(b) {};
    };
    int inthe(int a,int b,vector<vector<int>>& forest)
    {
        return a >=0&&a< forest.size() && b >=0 && b < forest[0].size() && forest[a][b] != 0;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(),n = forest[0].size(),start = 0 ,depth = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int> dp;
        queue<Point> qu;
        for (int i = 0; i < m; i ++){
            for (int j = 0; j < n; j ++){
                if(forest[i][j] > 1)
                    dp.push_back(forest[i][j]);
            }
        }
        sort(dp.begin(),dp.end());
        Point a(0,0);
        qu.push(a);
        vis[0][0] = 1;
        while(!qu.empty())
        {
            int n = qu.size();
            cout<<n<<endl;
            for (int i = 0; i < n; i ++){
                Point tmp = qu.front();
                qu.pop();
                cout<<tmp.x<<" "<<tmp.y<<endl;
                if(forest[tmp.x][tmp.y] == dp[start]){
                    cout<<" --"<<forest[tmp.x][tmp.y]<<"--- "<<endl;
                    start ++;
                    vector<vector<int>> t(m,vector<int>(n,0));
                    for(auto &c:vis)
                        for(auto &b:c)
                            b = 0;
                    while(!qu.empty()){
                        qu.pop();
                    }
                    n = 1;
                    vis[tmp.x][tmp.y] = 1;
                } 
                if(start == dp.size()) {return depth;}

                int tx = tmp.x,ty = tmp.y + 1;
                if(inthe(tx,ty,forest) && !vis[tx][ty]) {qu.push(Point(tx,ty));vis[tx][ty]=1;}
                tx = tmp.x + 1,ty = tmp.y;
                if(inthe(tx,ty,forest) && !vis[tx][ty]) {qu.push(Point(tx,ty));vis[tx][ty]=1;}
                tx = tmp.x,ty = tmp.y - 1;
                if(inthe(tx,ty,forest) && !vis[tx][ty]) {qu.push(Point(tx,ty));vis[tx][ty]=1;}
                tx = tmp.x - 1,ty = tmp.y;
                if(inthe(tx,ty,forest) && !vis[tx][ty]) {qu.push(Point(tx,ty));vis[tx][ty]=1;}
            }
            //cout<<start<<endl;
            depth ++;
        }

     {cout<<"?"<<endl;return -1;}
    }
};
int main(){
    
    system("pause:");
    return 0;
}