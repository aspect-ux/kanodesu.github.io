#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         int n  = num.length();
//         if(n == 0) return "0";
//         string res;
//         int flag = 0;
//         string :: iterator it,it1 = num.begin();
        
//         for(int i = 0; i < n; i ++){
//             it = min_element(it1,it1 + k + 1);
//             if(*it != num[i]) {
//                 k --;
//                 num[i] = 'a';
//             }
//             if(num[i] != 'a')
//                 if(num[i] != '0' || flag)
//                 {
//                     res += num[i];
//                     flag = 1;
//                 }
//             it1 ++;
//         }
//         if(res.empty()) return "0";
//         return res;
//     }
// };
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n  = num.length();
        if(n == 0) return "0";
        string res;
        int flag = 0,i;
        stack<char> st;
        for(i = 0; i < n - 1; i ++){
            
            if(num[i + 1] >= num[i]){
                st.push(num[i]);
            }else{
                k --;
                if(k == 0) break;
            }
        }
        while(!st.empty()){
            
                
        }
        
        return res;
    }
};
int main(){
   
    system("pause:");
    return 0;
}