#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> n1,n2;
        unordered_map<int,bool> share;
        unordered_map<int,bool> hash1;
        unordered_map<int,bool> hash;//放交集
        for(int i = 0;i < nums1.size(); i++){ //将nums1放入hash
        if(hash.find(nums1[i])==hash.end())
            hash.insert({nums1[i],false});

        }
        for(int i = 0;i < nums2.size(); i++){ //将nums2中unique的数字放入n2,并将非unique的数字放入share
            if(hash.find(nums2[i]) == hash.end())
            {
                if(hash1.find(nums2[i]) == hash.end()){
                     hash1.insert({nums2[i],true});
                    n2.push_back(nums2[i]);
                }
                     

            }
            else{
                if(share.find(nums2[i])==share.end()) //确保不重复输入
                share.insert({nums2[i],true});
            }
        }
        unordered_map<int,bool>::iterator it =hash.begin();
        for(;it != hash.end(); it++){  //再次比较nums1中与share相同的元素
                       
            if(share.find((*it).first) == share.end())//如果nums1中unique就
            {
                n1.push_back((*it).first);       

            }
        }
        ans.push_back(n1);
        ans.push_back(n2);
        return ans;


        
    }
};
int main(){
    Solution s;
    vector<int> nums1={1,2,3},nums2={2,4,6};
    vector<vector<int>> ans = s.findDifference(nums1,nums2);
    for(int i = 0; i <ans[0].size() ;i++){
        cout<<ans[0][i];
    }
    cout<<" ";
     for(int i = 0; i <ans[1].size() ;i++){
        cout<<ans[1][i];
    }
    system("pause:");
    return 0;
}