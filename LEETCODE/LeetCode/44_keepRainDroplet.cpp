#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
/*
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		// left[i]表示i左边的最大值，right[i]表示i右边的最大值
		vector<int> left(n), right(n);
		for (int i = 1; i < n; i++) {
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = max(right[i + 1], height[i + 1]);
		}
		int water = 0;
		for (int i = 0; i < n; i++) {
			int level = min(left[i], right[i]);
			water += max(0, level - height[i]);
		}
		return water;
	}
};*/


class Solution {
public:
    int trap(vector<int>& height) {
        //1.低放水，2.高更新不放水，3.最高不放水，最高夹最高放水，那么可以记录一下最高的个数，到一个减一个，最后一个不放水，其他都放水
        //双指针1
        //dfs2
        int water = 0,pivot = height[0],high = 0;
        //先找到最高的下标
        int max = 0;
        for(int i = 0; i < height.size(); i++){
            if(max < height[i]){
                max  = height[i];
            }

        }
        cout<<"max:"<<max<<endl;
        int n = 0;
          for(int i = 0; i < height.size(); i++){
            if(max == height[i]){
               n++;
            }
        } //此时n为最高点的个数
        high = n;
        int i,j = i =0;
        //开始遍历
        for( i = 0; i < height.size(); i++){
            if(height[i] == max){ //当等于制高点时
                high--;          //high减少
                 if(high == 0 && height[i] == max) break;
            }
            //1如果第二个更低，那就要在第二个位置放水
            if(pivot > height[i+1] && high){ //如果后面还有最高点并且左边更高那就放水 
           //i+1蓄水,累加
           cout<<"m:"<<pivot - height[i+1]<<' '<<i+1<<"high:"<<high<<endl;
            water +=pivot - height[i+1];
            }
                //更新左pivot
            if(pivot < height[i+1]){
                //更新pivot
                pivot = height[i+1];
            }
        }
        pivot = height[height.size()-1];
         for(j = height.size() - 1; j > i + 1;  j--){
            //1如果第二个更低，那就要在第二个位置放水
            if(pivot > height[j-1]){ //如果后面还有最高点并且左边更高那就放水 
           //j-1蓄水,累加
           cout<<"m:"<<pivot - height[j-1]<<' '<<i+1<<"high:"<<high<<"index:"<<j-1<<endl;
            water +=pivot - height[j-1];
            }

            //更新右pivot
            if(pivot <height[j-1]){
                pivot = height[j-1];
            }
        }

        return water;
    }
};

  /*   else if(pivot >height[i+1] && !high){ //如果没有制高结点，那下一个必定不会放水
                if(pivot == max) //当前为制高点
                pivot = height[i+1]; //此时要重置基准点,!!!!此时面临一个问题，要不要回溯，不用回溯还好，但
                //一旦要回溯，即最后一个点比基准点低，那么制高点
                //无论如何最后一个点都不放水，
                water += pivot - height[i+1];
                cout<<"m:"<<i+1<<"pivot:"<<pivot<<"water:"<<pivot-height[i+1]<<endl;
            }*/
            //2.加入左边更低，显然不能蓄水了
           /*  if(height[j] == max){ //当等于制高点时
                high--;          //high减少
            }
            //1如果第二个更低，那就要在第二个位置放水
            if(pivot > height[j-1] && high){ //如果后面还有最高点并且左边更高那就放水 
           //j-1蓄水,累加
           cout<<"m:"<<pivot - height[j-1]<<' '<<i+1<<"high:"<<high<<endl;
            water +=pivot - height[j-1];
            }

        
            //更新右pivot
            if(pivot <height[j-1]){
                pivot = height[j-1];
            }*/
int main(){
    Solution s;
    vector<int>height ={0};
    cout<<s.trap(height);
    system("pause:");
    return 0;
}