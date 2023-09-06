#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//========================仅供个人学习，酌情参考================================== 
//====================包含了查找和排序的各种常见算法===============================
// 部分代码参考了：https://www.runoob.com/w3cnote/ten-sorting-algorithm.html 
#define MAXLENGTH 10
typedef struct
{
	int key;
	int val;
}KeyValueType;
typedef struct
{
	KeyValueType Element[MAXLENGTH+1];
	int length;
}KeyValueList;

// 索引表结构
typedef struct
{
    int maxKey;     // 索引区间的最大键值
    int address;    // 索引区间的起始地址（下标）
}Index;

// 顺序排序类 
class Find
{
public: 
// 方便起见不用结构体，直接在int数组里查找 
	void InitArr()
	{
		cin>>n;
		for (int i = 0; i < n; i ++)
		{
			// 简单初始化一下 
			arr[i] = i;
		}
	}
	int BinSearch(int x)
	{
		int low = 0,high = n,mid = (high - low)/2 + low;
		while (low <= high)
		{
			if (arr[mid] = x)
			{
				return mid;
			}
			else if (arr[mid] < x)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
			mid = (high - low)/2 + low;
		}
		return -1;
	}

	int BlockSearch(Index *index, int indexLen, int x)
	{
	    // 先折半查找索引表，找到关键值的索引区间
	    int low = 0,high = n,mid = (high - low)/2 + low;
	    while (low < high)
	    {
	    	// index.maxKey存储了最大的值 
	        if (x == index[mid].maxKey)
	        {
	            break;
	        }
	        else if (x < index[mid].maxKey)
	        {
	        	// TODO:这里尤其注意，我们是用最大值进行比较
				// 但是同时，如果我们发现该最大值大于x，我们没有把握说这个x是在找到的这个块，还是前一个。
				// 所以如果high = mid - 1,有可能会错过正确答案。 
	            high = mid;
	        }
	        else
	        {
	            low = mid + 1;
	        }
	        mid = (high - low)/2 + low;
	    }
	    
	    // 跳出循环，mid就是要找的索引,就能确定块的start和end 
	    int start = index[mid].address, end;
	    if (mid == indexLen - 1)
	    {
	        end = n;
	    }
	    else
	    {
	        end = index[mid + 1].address;
	    }
	    
	    // 最后顺序查找返回索引下标 
	    for (int i = start; i < end; i++)
	    {
	        if (x == arr[i])
	        {
	            return i;
	        }
	    }
	    return -1;
	}

private:
	int arr[MAXLENGTH];
	int n;
};

// 用于二叉搜索树 
struct TreeNode {
    int key; // 存储key 
    TreeNode *left;
    TreeNode *right;
    TreeNode() : key(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : key(x), left(left), right(right) {}
};
static TreeNode *root;

#define RANK 10 
// 用于m叉搜索树 也就是B树 
// 申请RANK+1的大小 ，0号空间不使用 
struct BTreeNode {
    int keyNum;  // 存储key的数量 
    int key[RANK+1]; // 因为叶子结点不放信息了，所以只能让父结点存储子结点的信息 
    BTreeNode *p; // 父结点 ，这里如果要当前 
    BTreeNode *ptr[RANK+1]; //子树数组 
	BTreeNode() : keyNum(RANK),p(nullptr)
	{
		for (int i = 1; i < RANK+1; i ++)
		{
			key[i] = i;
			ptr[i] = nullptr;
		}
	}
};
static BTreeNode *b;

// 二叉排序类 
class BSTFind
{
public:
	// 创建二叉搜索树（排序树）,使用int作key 
	// key是唯一标识不重复 
	void CreateBST()
	{
		int key;
		TreeNode *bst = nullptr;
		scanf("%d",&key);
		while (key != -1)
		{
			Insert(bst,key);
			scanf("%d",&key);
		} 
	}
	void Insert(TreeNode *bst,int key)
	{
		if (bst == nullptr)
		{
			TreeNode *node = new TreeNode(key);
			bst = node;
		}
		else if (bst->key > key)
			Insert(bst->left,key);
		else 
			Insert(bst->right,key);
	}
	TreeNode* Search(TreeNode *bst,int key)
	{
		if (!bst) return nullptr;
		
		if (key == bst->key)
			return bst;
		else if (key < bst->key)
			return Search(bst->left,key);
		else 
			return Search(bst->right,key);		
	} 
};

//==================排序部分===============================
//方便起见，使用int[]排序
#define ARRSIZE 10
int arr[ARRSIZE] = {0,2,3,4,1,5}; 
class Sort
{
public:
	Sort()
	{	
	} 
	// 冒泡 
	void BubbleSort()
	{
		int t[ARRSIZE];
		for (int i = 0; i < ARRSIZE - 1; i ++)
		{
			for (int j = 1; j < ARRSIZE; j ++)
			{
				if (arr[i] > arr[j]) 
				{
					swap(arr[i],arr[j]);
				}
			}
		}
	}
	// 插入排序
	// 略
	void InsertSort()
	{
		
	}	
	
	// 二分插入排序
	void BinInsertSort(int n)
	{
		int insert;
		for (int i = 0; i < n; i ++)
		{
			int low = 0, high = i,mid = (high - low)/2 + low;
			
			
			// 假设边输入边插入，也可以用事先存储的数据 
			cin >> insert;
			
			// 第一个数直接放在第一位 
			if (i == 0) {
				arr[0] = insert;
				continue;
			}
			
			while (low <= high)
			{
				if (arr[mid] > insert)
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
				mid = (high - low)/2 + low;
			}
			// 因为要想插入还需要移动后面的数据
			// 数组中已有i个数,正在插入第i+1个数 
			for (int j = i; j >= low; j --)
			{
				arr[j + 1] = arr[j]; 
			} 
			arr[low] = insert;
			cout<<low<<endl;
		}
		
		for (int i = 0; i < n; i ++)
		{
			cout<<arr[i]<<' ';
		}
	} 
	
	// 表插入排序（链表存储）原理一样，只是有序表变成了有序链表 
	
	
	// 简单选择
	void SimpleSelect(int n)
	{
		int k;
		for (int i = 0; i < n - 1; i ++)
		{
			k = i;
			for (int j = i + 1; j < n; j ++)
			{
				if (arr[i] > arr[j])
					k = j;
			}
			if (k != i) 
				swap(arr[i],arr[k]);
		} 
	} 
	
	// 树选择O(nlog2n)
	// 略
	
	// 堆排序
	// 让当前堆顶的数下沉，值最小的话就沉入最底 
	void createMaxHeap(int start, int end) {
	    //建立父节点指标和子节点指标
	    int dad = start;
	    int son = dad * 2 + 1;
	    while (son <= end) { //若子节点指标在范围内才做比较
	        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
	            son++;
	            
	        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
	            return;
	        else { //否则交换父子内容再继续子节点和孙节点比较
	            swap(arr[dad], arr[son]);
	            dad = son;
	            son = dad * 2 + 1;
	        }
	    }
	}
	void heapSort(int len) {
		// 从小到大排序，创建大根堆，从最后一个非叶子父结点开始
		for(int i = (len-2)/2; i >= 0; i --)
			createMaxHeap(i, len - 1);
		
		// 输出大根堆 
		for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
        cout << endl;
        
	    /*for (int i = (len-1) / 2; i >= 0; i--)
	        createMaxHeap(i, len - 1);*/
	    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
	    for (int i = len - 1; i > 0; i--) {
	    	// 把当前堆最大值放到最后 与之交换 
	        swap(arr[0], arr[i]);
	        // 重新让堆顶最大 
	        createMaxHeap(0, i - 1);
	    }
	}
	
	// 归并排序
	// 非递归 
	template<typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
	void merge_sort(T arr[], int len) 
	{
		T *a = arr;
		T *b = new T[len]; // 存储归并排序后的结果 
		for (int seg = 1; seg < len; seg += seg) 
		{
			for (int start = 0; start < len; start += seg + seg) 
			{
				int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
				int k = low;
				int start1 = low, end1 = mid;
				int start2 = mid, end2 = high;
				while (start1 < end1 && start2 < end2) // 比较 
					b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
				while (start1 < end1)
					b[k++] = a[start1++];
				while (start2 < end2)
					b[k++] = a[start2++];
			}
			T *temp = a;
			a = b;
			b = temp;
		}
		if (a != arr) {
			for (int i = 0; i < len; i++)
				b[i] = a[i];
			b = a;
		}
		delete[] b;
	} 	
	
	// 递归
	void merge_sort_recursive(int arr[], int reg[], int start, int end) 
	{
	  if (start >= end)
	    return;
	  int len = end - start, mid = (len >> 1) + start;
	  int start1 = start, end1 = mid;
	  int start2 = mid + 1, end2 = end;
	  merge_sort_recursive(arr, reg, start1, end1);
	  merge_sort_recursive(arr, reg, start2, end2);
	  int k = start;
	  while (start1 <= end1 && start2 <= end2)
	    reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	  while (start1 <= end1)
	    reg[k++] = arr[start1++];
	  while (start2 <= end2)
	    reg[k++] = arr[start2++];
	  for (k = start; k <= end; k++)
	    arr[k] = reg[k];
	}

	void merge_sort(int arr[], const int len) {
	  int reg[len];
	  merge_sort_recursive(arr, reg, 0, len - 1);
	}
	
	
	// 快排，递归
	int Paritition(int A[], int low, int high) {
	   int pivot = A[low];
	   while (low < high) {
	     while (low < high && A[high] >= pivot) {
	       --high;
	     }
	     A[low] = A[high];
	     while (low < high && A[low] <= pivot) {
	       ++low;
	     }
	     A[high] = A[low];
	   }
	   A[low] = pivot;
	   return low;
	 }

	 void QuickSort(int A[], int low, int high)
	 {
	   if (low < high) {
	     int pivot = Paritition(A, low, high);
	     QuickSort(A, low, pivot - 1);
	     QuickSort(A, pivot + 1, high);
	   }
	 }
	 
	// 基数排序
	int maxbit(int data[], int n) //辅助函数，求数据的最大位数
	{
	    int maxData = data[0];              ///< 最大数
	    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
	    for (int i = 1; i < n; ++i)
	    {
	        if (maxData < data[i])
	            maxData = data[i];
	    }
	    int d = 1;
	    int p = 10;
	    while (maxData >= p)
	    {
	        //p *= 10; // Maybe overflow
	        maxData /= 10;
	        ++d;
	    }
	    return d;
	/*    int d = 1; //保存最大的位数
	    int p = 10;
	    for(int i = 0; i < n; ++i)
	    {
	        while(data[i] >= p)
	        {
	            p *= 10;
	            ++d;
	        }
	    }
	    return d;*/
	}
	void radixsort(int data[], int n) //基数排序
	{
	    int d = maxbit(data, n);
	    int *tmp = new int[n];
	    int *count = new int[10]; //计数器
	    int i, j, k;
	    int radix = 1;
	    for(i = 1; i <= d; i++) //进行d次排序
	    {
	        for(j = 0; j < 10; j++)
	            count[j] = 0; //每次分配前清空计数器
	        for(j = 0; j < n; j++)
	        {
	            k = (data[j] / radix) % 10; //统计每个桶中的记录数
	            count[k]++;
	        }
	        for(j = 1; j < 10; j++)
	            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
	        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
	        {
	            k = (data[j] / radix) % 10;
	            tmp[count[k] - 1] = data[j];
	            count[k]--;
	        }
	        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
	            data[j] = tmp[j];
	        radix = radix * 10;
	    }
	    delete []tmp;
	    delete []count;
	} 
};


int main() {
	// 查找算法需要new Find对象
	// ...
	
	// =====排序示例 =======
	// 创建排序对象 
    Sort s;
    // 堆排序示例 
    s.heapSort(6);
    // 输出 
    for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}

