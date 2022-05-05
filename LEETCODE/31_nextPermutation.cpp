#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
//https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
class Solution {
public:
   vector<int>& nextPermutation(vector<int>& nums) {
          vector<int> ans,start;
          start = nums;  //保留初始顺序
            do{
                ans.push_back(caculate(nums)); //插入元素
            }while(next_permutation(nums.begin(),nums.end()));
            sort(ans.begin(),ans.end());
            return deCaculate(parseVector(ans, start));

    }
    int caculate(vector<int>& nums){
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res = res*10+nums[i];
        }
        return res;

    }
    vector<int>& deCaculate(int res){
        vector<int> v;
        int b;
        while(res>0){
            b = res%10;
            v.push_back(b);//输入尾位
            res = res /10;   
        }
        return v;
    }
    int parseVector(vector<int>& ans,vector<int>& start){
        for(int i = 0;i < ans.size(); i++){
            if(caculate(start)== ans[i]){
                if(i == ans.size() -1)
                return ans[0];//如果找不到下一个，就返回第一个
                return ans[i+1];  //找到下一个后返回
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> v={1,2,3},ans;
    ans=s.nextPermutation(v);
    for(int i=0;i<3;i++){
        cout<<ans[i];

    }
   
    system("pause:");
    return 0;
}
