#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int convertTime(string current, string correct) {
        vector<int> v={60,15,5,1};
        int cnt = 0;
        int gh = (correct[0] -48)*10 + correct[1] -48;
        int gl =  (correct[3] -48)*10 + correct[4] -48;
        int ch = (current[0] -48)*10 + current[1] -48;
         int cl =  (current[3] -48)*10 + current[4] -48;
         int ans = (gh*60+gl) - (ch*60+cl);
         if(ans<0) ans = 1440 + ans;
        for(int i = 0;i < v.size(); i++){
            while(ans - v[i] >= 0){
                cnt++;
                ans = ans -v[i];
                
            }
        }
        return cnt;
        
    }
};
int main(){
    Solution s;
 s.convertTime("02:30", "04:35");


    system("pause:");
    return 0;
}