#include<iostream>
#include<queue>
using namespace std;
// class Solution {
// public:
//     int integerReplacement(int n) {
//         queue<int> qu;
//         qu.push(n);
//         int cnt = 0,e;
//         while(!qu.empty()){
//             int m = qu.size();
//             for(int i = 0; i < m; i++){
//                  e = qu.front();
//                  if(e%2){
//                     if(e - 1 == 1) return cnt + 1;
//                     qu.push(e+1);
//                     qu.push(e-1);
//                 }else{
//                     if(e/2 == 1) return cnt + 1;
//                     qu.push(e/2);
//                 }
//                 qu.pop();
//             }
//             cnt ++; 
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1){
            return 0;
        }
        if(n%2){
            return min(integerReplacement(((n == INT_MAX)?(n+1)/2:n)+1),integerReplacement(n - 1)) + 1 + (n == INT_MAX?1:0);
        }
        return integerReplacement(n/2) + 1;
    }
};
int main(){
   
    system("pause:");
    return 0;
}