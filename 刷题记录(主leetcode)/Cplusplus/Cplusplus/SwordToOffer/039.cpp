#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //单调递增栈，当前如果需要弹出的话， 栈顶那个元素是矩阵高，当前遍历的元素是矩阵的宽的最右边，栈顶的下一个元素是矩阵的宽的最左边，这样求以栈顶元素为展开的面积
    int largestRectangleArea(vector<int>& heights){
        int maxArea = 0, n = heights.size();
        stack<int> stk;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                int k = stk.top(); //求以它的高度来展开的矩形面积
                stk.pop();
                maxArea = max(maxArea, (i - 1 - (stk.empty() ? -1 : stk.top())) * heights[k]);
            }
            stk.push(i);
        }
        while(!stk.empty()){  //栈内所剩元素为未处理元素，且为递增序列
            int  k = stk.top();
            stk.pop();
            maxArea = max(maxArea, (n - 1 - (stk.empty() ? - 1 : stk.top())) * heights[k]);
        }
        return maxArea;
    }
};