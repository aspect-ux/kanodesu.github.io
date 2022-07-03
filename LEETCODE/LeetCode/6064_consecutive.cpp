#include<iostream>
#include<vector>
#include<algorithm> //find 格式有点像sort
using namespace std;
/* 再次超时，对于枚举法，超时第一时间看数据，换一种思路枚举
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0,tmp = 0;
        for(int i = bottom ; i <= top; i++){
           if(find(special.begin(),special.end(),i) == special.end()){ //返回it迭代器
                tmp ++;
           }    
           else{
               tmp = 0;
           }
           ans = max(ans,tmp);
        }
        return ans;
    }
};*/
//special 数量级为1e5,top则是1e9
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0,pre;
        sort(special.begin(),special.end());
        pre = special[0];
        for(int i = 1 ; i < special.size(); i++){
            ans = max(ans,special[i] - pre - 1);
            pre = special[i];
        }
        return max(ans,max(special[0] - bottom,top - special[special.size() - 1]));
    }
};
int main(){
    
    system("pause:");
    return 0;
}