#### 二分查找
##### 1.leetcode 704
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*首先需明确二分查找要在有序序列的条件下进行*
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1,mid;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};
```
stl二分查找函数，需要头文件include< algorithm>
1.`upper_bound(v1.begin(),v1.end(),val);`查找大于val的第一个数
源码
```c++
template <class ForwardIterator, class T>
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
    ForwardIterator it;
    iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first,last);
    while (count>0)
    {
        it = first; step=count/2; std::advance (it,step);
        if (!(val<*it))  // 或者 if (!comp(val,*it)), 对应第二种语法格式
            { first=++it; count-=step+1;  }
        else count=step;
    }
    return first;
}
```
2.`lower_bound(v1.begin(),v1.end(),val);`
查找第一个不小于val的值，返回迭代器，结果大于等于val
源码
```c++
template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
    ForwardIterator it;
    iterator_traits<ForwardIterator>::difference_type count, step;
    count = distance(first,last);
    while (count>0)
    {
        it = first; step=count/2; advance (it,step);
        if (*it<val) {  //或者 if (comp(*it,val))，对应第 2 种语法格式
            first=++it;
            count-=step+1;
        }
        else count=step;
    }
    return first;
}
```
3.`binary_search()`
调用2.这里不再赘述。


33.搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。


```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```
