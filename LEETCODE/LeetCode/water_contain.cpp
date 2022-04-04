#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int i=0,j=height.size()-1;
        while(i!=j)
        {
            if(height[j]>height[i]){
                i++;
            }
            else
            j--;
            maxarea=max(maxarea,min(height[j],height[i])*(j-i));
        }
        return maxarea;

    }
};
int main()
{
    system("pause:");
    return 0;
}