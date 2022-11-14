#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size(),ans = 0;
        ListNode* p = head;
        while(!p)
        {
            auto it = find(nums.begin(),nums.end(),p->val);
            if(it != nums.end()){
                while(p && it != nums.end() && *it == p->val)
                {
                    p = p->next;
                    it ++;
                }
                ans ++;
            }
            
        }
        return ans;
    }
};
int main(){
    
    system("pause:");
    return 0;
}