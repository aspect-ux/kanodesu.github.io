#### 插入排序+冒泡排序
插入排序
```C++
for(int i = 0;i < nums.size(); i++){
    target = nums[i];
    j = i;
    for(;j <= i; j++){
        if(target > nums[j + 1]){
            nums[j] = nums[j + 1];
        }
        else break;
    }
    if(j > i){
        nums[j + 1] = target;
    }
}
```