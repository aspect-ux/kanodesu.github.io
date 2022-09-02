#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
int n;
vector<bool> status;
vector<vector<int>> ret;
vector<int> track;
//[1,2,3],[1,3,2],[2,1,3]....
class Solution {
public:
void backTrack(vector<int> &nums) {
    if (track.size() == n) {
        ret.push_back(track);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!status[i]) {
            status[i] = true;
            track.push_back(nums[i]);
            backTrack(nums);
            track.pop_back();
            status[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    n = nums.size();
    status.resize(n, false);
    backTrack(nums);
    return ret;
}
};*///链接：https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
/*class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output); //push_back
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
        //结束函数但回溯没有结束
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};*/
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> v;
//         sort(nums.begin(),nums.end());
//         do{
//             v.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));
//         return v;

//     }
// };
//由此可以带来思路，即 1,2,3,4


class Solution {
public:
    vector<int> res;
    vector<int> status;
    void dfs(vector<vector<int>>& ans,vector<int>& nums){

        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!status[i]){
                status[i] = true;
                res.push_back(nums[i]);
                dfs(ans,nums);
                res.pop_back();
                status[i] = false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        status.resize(nums.size(),false);
        dfs(ans,nums);
        return ans;

    }
};



int main(){
    Solution s;
    vector<int> nums= {0,-1,2};
    vector<vector<int>> v;
    v=s.permute(nums);
    for(int i = 0;i < v.size(); i++){
        for(int j = 0; j< nums.size(); j++){
            cout<<v[i][j];

        }
        cout<<endl;
    }


    system("pause:");
    return 0;
}