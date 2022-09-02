#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*class Solution {
public:
    unordered_set<int> diagonal1;
    unordered_set<int> diagonal2;
    unordered_set<int> column; //存放某列是否空闲
    int ans = 0;
    
    void dfs(int row,int n){
        if(n == row) {
            ans ++;
            return;
        }
        for(int j = 0; j < n;j ++){
            if(column.find(j)  == column.end() && diagonal1.find(row+j)==diagonal1.end()
            && diagonal2.find(row-j)==diagonal2.end()){
                diagonal1.insert(row+j);
                diagonal2.insert(row-j);
                column.insert(j);
                dfs(row + 1,n);
                diagonal1.erase(row + j);
                diagonal2.erase(row - j);
                column.erase(j);
            }
        }
    }
    int totalNQueens(int n) {
        dfs(0,n);
        return ans;
    }
};*/
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }

private:
    int res = 0;
};
int main(){
   
    system("pause:");
    return 0;
}