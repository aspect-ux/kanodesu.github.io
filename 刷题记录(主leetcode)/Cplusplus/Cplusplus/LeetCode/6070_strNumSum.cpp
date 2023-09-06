#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            int cnt = s.length()/k;
            string t="";
             for(int i = 0;i < cnt; i++){
                 int sum = 0;
                 for(int j = 0;j < k; j++){
                     sum += s[i*k+j] - 48;
                 }
                 t += to_string(sum);    
            }
            int sum1 = 0;
            for(int j = 0;j < s.length() - k*cnt; j++){
                sum1 += (s[cnt * k + j] - 48);
            }
            if(s.length() != cnt*k)  //除不通
            {
                t += to_string(sum1);
            }
            s = t;
        }
        return s;     
    }
};
int main(){
    Solution s;
    int a;
    cout<<s.digitSum( "1234",2);
    
    system("pause:");
    return 0;
}