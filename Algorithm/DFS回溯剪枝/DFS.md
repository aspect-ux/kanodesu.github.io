## DFS

### 得到数组的所有长度为k的排列

```c++
class Solution {
public:
	.....
    void dfs(){
        if(){
        	....
            return;
        }
        for(int i = 0;i < n;i++){
            if(status[i]) continue;
            status[i] = 1;
			.....
            dfs();
            status[i] = 0;
        }
    }
    int func() {
		....
        dfs();
        return ans;
    }
};
```

