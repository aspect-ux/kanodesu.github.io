#include<iostream>
#include<vector>
using namespace std;
// 10-7      1010 - 0111    3-4  011-100
//减少一个循环就过了.....
class Solution {  //从右向左开始reverse,返回最小翻转次数
public:
    int minBitFlips(int start, int goal) {
        //除以2得到余数即是最右位
        vector<int> g,s;
        int cnt = 0;
        int x = 0,y = 0;  // x-start, y-goal
        if(goal == 0){
            g.push_back(0);
        }
        if(start  == 0){
            s.push_back(0);
        }
        while(start > 0){   //理论来讲goal更长，
            x = start % 2;
            start /= 2;
            s.push_back(x);
        }
        while(goal > 0){
             y = goal % 2;
             goal /= 2;
             g.push_back(y);
        }
        
        int m = g.size() >s.size() ?g.size() - s.size():s.size()-g.size();
        int flag =  g.size() >s.size() ? 1:0;
            for(int i =0;i < m;i++){
                if(flag)
                s.push_back(0);
                else
                g.push_back(0);
            }

        //比对

        for(int i = 0; i < max(s.size(),g.size()); i++){
            if(s[i] != g[i]) cnt++;
           
        }
        return cnt;
        
    }
};
int main(){
    Solution s;
   cout<<s.minBitFlips(48,0);



    system("pause:");
    return 0;
}