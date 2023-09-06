#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size(),l = 0,r = n - 1,mid = (r - l)/2 + l;
        for(int i = 0; i < m; i ++){
            if(matrix[i][0] > target) continue;
            while(l <= r){
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] > target) r = mid - 1;
                else l = mid + 1;
                mid = (r - l)/2 + l;
            }
            cout<<1;
            l = 0;
            r = n - 1;
            mid = (r - l)/2 + l;
        }
        return false;
    }
};
int main(){
    
    system("pause:");
    return 0;
}