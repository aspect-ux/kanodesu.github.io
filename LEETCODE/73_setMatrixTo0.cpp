#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row,column;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(int r : row){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[r][i] = 0;
            }
        }
         for(int c : column){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][c] = 0;
            }
        }
    }
};
int main(){
    system("pause:");
    return 0;
}