#### 插入排序+冒泡排序
插入排序
```C++
void insert_sort(vector<int> nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) { // n - 1轮次执行
            int target = nums[i], j = i - 1;
            for (; j >= 0; j--) {
                if (target < nums[j]) nums[j + 1] = nums[j];
                else break;
            }
            // j变动表示发生了移动，此时的插入对象数字 ≥ j位置的数字，故插入位置为j + 1
            if (j != i - 1) nums[j + 1] = target;
        }
        Print(nums);
}
```
链表实现插入排序 `leetcode `147

```c++
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* L = new ListNode(),*index = head->next,*q,* pre = L;//手动增加空结点
        L->next = head; 
        pre->next->next = nullptr;
        while(index){
            q = index->next;  //q用来存储
            while(pre->next && index->val >= pre->next->val){ //大于等于就往后移
                pre = pre->next;
            }
            index->next = pre->next; //插入
            pre->next = index;
            pre = L;          //重置
            index = q;
        }
        return L->next;
    }
};
```

冒泡排序
略