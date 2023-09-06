#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int first,second;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                first = arr[i];
                second = arr[j];
                for(int k = j + 1; k < n; k++){
                    if(first+second == arr[k]){
                        first = second;
                        second = arr[k];
                        dp[i][j] ++;
                    }
                }
                
            }

        }
        int max = dp[0][0],r = 0,c = 0;
        for(int i = 0 ;i < n;i ++){
            for(int j = 0;j < n;j ++){
                if(dp[i][j] > max){
                    max = dp[i][j];
                    r = i;
                    c = j;
                }
            }
        }
        return max;
    }
};
int main(){
    system("pause:");
    return 0;
}