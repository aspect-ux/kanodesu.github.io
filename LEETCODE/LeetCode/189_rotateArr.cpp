#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
       int gcd(int a , int b){
        return a%b==0? b:gcd(b,a%b);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

/* class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,n = nums.size(),j = k,start;
        k = k%n;
        if(k == 0)return;
        vector<int> table(n,0);
        start = nums[0];
        for(int i = 0;i < n; i++){
            if(table[j]) continue;
            cout<<"?"<<endl;
            j = (i + k)%n;
            start = nums[i];
            while(1){
                temp = nums[j];
                nums[j] = start;
                table[j] = 1;
                start = temp;
                if(j < k&& n%k == 0){
                    j += 1;
                    start = nums[j];
                    if(j == k) break;
                }
                if(j == 0 && n%k)break;
                j = (j + k)%n;
            }
        }
       
    }
}; */
int main(){
   
    system("pause:");
    return 0;
}