#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //dir = -1 0 1 2  右 下 左 上
    int ans = 0,nx = 0;
    int inthe(int a,int b,vector<string>& plate){
        return a>=0&&a<plate.size()&&b>=0&&b<plate[0].size();
    }
    void dfs(int x,int y,int& num, vector<string>& plate,int dir){
        if(!num) return;
        num --;
        int tx,ty;
        if(x == 2&&y==1&&num == 3)
        cout<<dir<<endl;
        if(dir == -1){tx = x;ty = y + 1;
                            if(inthe(tx,ty,plate)){
                                if(plate[tx][ty] == 'W'){
                                    dfs(tx,ty,num,plate,2);
                                }else if(plate[tx][ty] == 'E'){
                                    dfs(tx,ty,num,plate,0);
                                }else if(plate[tx][ty] == '.'){
                                    dfs(tx,ty,num,plate,-1);
                                }else{
                                ans ++;
                                return;
                            }
        }
        }
        else if(dir == 0){
                    tx = x + 1;ty = y;
                    if(inthe(tx,ty,plate)){
                    if(plate[tx][ty] == 'W'){
                        dfs(tx,ty,num,plate,-1);
                    }else if(plate[tx][ty] == 'E'){
                        dfs(tx,ty,num,plate,1);
                    }else if(plate[tx][ty] == '.'){
                        dfs(tx,ty,num,plate,0);
                    }else{
                        ans ++;
                        return;
                    }
            }
        }
        //l
        else if(dir == 1){tx = x; ty = y - 1;
        if(inthe(tx,ty,plate)){
            if(plate[tx][ty] == 'W'){
                    dfs(tx,ty,num,plate,0);
                }else if(plate[tx][ty] == 'E'){
                    dfs(tx,ty,num,plate,2);
                }else if(plate[tx][ty] == '.'){
                    dfs(tx,ty,num,plate,1);
                }else{
                    ans ++;
                    return;
                }
        }

        }
        else {tx = x - 1; ty = y;
              
        if(inthe(tx,ty,plate)){ 
         if(plate[tx][ty] == 'W'){
                    dfs(tx,ty,num,plate,1);
                }else if(plate[tx][ty] == 'E'){
                    cout<<"E";
                    dfs(tx,ty,num,plate,-1);
             
                }else if(plate[tx][ty] == '.'){
                    dfs(tx,ty,num,plate,2);
                }else{
                    ans ++;
                    return;
                }
            }
        }

    }
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        int dir = 0;
        vector<vector<int>> res;
        for(int i = 0; i < plate.size(); i ++){
            for(int j = 0; j < plate[0].size(); j ++){
                nx = num;
                if(plate[i][j] == '.'){
                    if(i == 0 ) dir = 0;
                    else if(j == plate[0].size() - 1) dir = 1;
                    else if(j == 0) dir = -1;
                    else if(i == plate.size() - 1)dir = 2;
                    else continue;
                    dfs(i,j,nx,plate,dir);
                    if(ans) res.push_back({i,j});
                    ans = 0;
                }
            }
        }
        return res;
    }
};
int main(){
    
    system("pause:");
    return 0;
}