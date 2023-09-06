#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//========================��������ѧϰ������ο�================================== 
//====================�����˲��Һ�����ĸ��ֳ����㷨===============================
// ���ִ���ο��ˣ�https://www.runoob.com/w3cnote/ten-sorting-algorithm.html 
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

// ������ṹ
typedef struct
{
    int maxKey;     // �������������ֵ
    int address;    // �����������ʼ��ַ���±꣩
}Index;

// ˳�������� 
class Find
{
public: 
// ����������ýṹ�壬ֱ����int��������� 
	void InitArr()
	{
		cin>>n;
		for (int i = 0; i < n; i ++)
		{
			// �򵥳�ʼ��һ�� 
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
	    // ���۰�����������ҵ��ؼ�ֵ����������
	    int low = 0,high = n,mid = (high - low)/2 + low;
	    while (low < high)
	    {
	    	// index.maxKey�洢������ֵ 
	        if (x == index[mid].maxKey)
	        {
	            break;
	        }
	        else if (x < index[mid].maxKey)
	        {
	        	// TODO:��������ע�⣬�����������ֵ���бȽ�
				// ����ͬʱ��������Ƿ��ָ����ֵ����x������û�а���˵���x�����ҵ�������飬����ǰһ����
				// �������high = mid - 1,�п��ܻ�����ȷ�𰸡� 
	            high = mid;
	        }
	        else
	        {
	            low = mid + 1;
	        }
	        mid = (high - low)/2 + low;
	    }
	    
	    // ����ѭ����mid����Ҫ�ҵ�����,����ȷ�����start��end 
	    int start = index[mid].address, end;
	    if (mid == indexLen - 1)
	    {
	        end = n;
	    }
	    else
	    {
	        end = index[mid + 1].address;
	    }
	    
	    // ���˳����ҷ��������±� 
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

// ���ڶ��������� 
struct TreeNode {
    int key; // �洢key 
    TreeNode *left;
    TreeNode *right;
    TreeNode() : key(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : key(x), left(left), right(right) {}
};
static TreeNode *root;

#define RANK 10 
// ����m�������� Ҳ����B�� 
// ����RANK+1�Ĵ�С ��0�ſռ䲻ʹ�� 
struct BTreeNode {
    int keyNum;  // �洢key������ 
    int key[RANK+1]; // ��ΪҶ�ӽ�㲻����Ϣ�ˣ�����ֻ���ø����洢�ӽ�����Ϣ 
    BTreeNode *p; // ����� ���������Ҫ��ǰ 
    BTreeNode *ptr[RANK+1]; //�������� 
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

// ���������� 
class BSTFind
{
public:
	// ������������������������,ʹ��int��key 
	// key��Ψһ��ʶ���ظ� 
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

//==================���򲿷�===============================
//���������ʹ��int[]����
#define ARRSIZE 10
int arr[ARRSIZE] = {0,2,3,4,1,5}; 
class Sort
{
public:
	Sort()
	{	
	} 
	// ð�� 
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
	// ��������
	// ��
	void InsertSort()
	{
		
	}	
	
	// ���ֲ�������
	void BinInsertSort(int n)
	{
		int insert;
		for (int i = 0; i < n; i ++)
		{
			int low = 0, high = i,mid = (high - low)/2 + low;
			
			
			// ���������߲��룬Ҳ���������ȴ洢������ 
			cin >> insert;
			
			// ��һ����ֱ�ӷ��ڵ�һλ 
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
			// ��ΪҪ����뻹��Ҫ�ƶ����������
			// ����������i����,���ڲ����i+1���� 
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
	
	// �������������洢��ԭ��һ����ֻ������������������� 
	
	
	// ��ѡ��
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
	
	// ��ѡ��O(nlog2n)
	// ��
	
	// ������
	// �õ�ǰ�Ѷ������³���ֵ��С�Ļ��ͳ������ 
	void createMaxHeap(int start, int end) {
	    //�������ڵ�ָ����ӽڵ�ָ��
	    int dad = start;
	    int son = dad * 2 + 1;
	    while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
	        if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
	            son++;
	            
	        if (arr[dad] > arr[son]) //������ڵ�����ӽڵ���������ϣ�ֱ����������
	            return;
	        else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
	            swap(arr[dad], arr[son]);
	            dad = son;
	            son = dad * 2 + 1;
	        }
	    }
	}
	void heapSort(int len) {
		// ��С�������򣬴�������ѣ������һ����Ҷ�Ӹ���㿪ʼ
		for(int i = (len-2)/2; i >= 0; i --)
			createMaxHeap(i, len - 1);
		
		// �������� 
		for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
        cout << endl;
        
	    /*for (int i = (len-1) / 2; i >= 0; i--)
	        createMaxHeap(i, len - 1);*/
	    //�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
	    for (int i = len - 1; i > 0; i--) {
	    	// �ѵ�ǰ�����ֵ�ŵ���� ��֮���� 
	        swap(arr[0], arr[i]);
	        // �����öѶ���� 
	        createMaxHeap(0, i - 1);
	    }
	}
	
	// �鲢����
	// �ǵݹ� 
	template<typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)���\���ӹ���
	void merge_sort(T arr[], int len) 
	{
		T *a = arr;
		T *b = new T[len]; // �洢�鲢�����Ľ�� 
		for (int seg = 1; seg < len; seg += seg) 
		{
			for (int start = 0; start < len; start += seg + seg) 
			{
				int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
				int k = low;
				int start1 = low, end1 = mid;
				int start2 = mid, end2 = high;
				while (start1 < end1 && start2 < end2) // �Ƚ� 
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
	
	// �ݹ�
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
	
	
	// ���ţ��ݹ�
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
	 
	// ��������
	int maxbit(int data[], int n) //���������������ݵ����λ��
	{
	    int maxData = data[0];              ///< �����
	    /// ������������������λ����������ԭ������ÿ�����ж���λ������΢�Ż��㡣
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
	/*    int d = 1; //��������λ��
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
	void radixsort(int data[], int n) //��������
	{
	    int d = maxbit(data, n);
	    int *tmp = new int[n];
	    int *count = new int[10]; //������
	    int i, j, k;
	    int radix = 1;
	    for(i = 1; i <= d; i++) //����d������
	    {
	        for(j = 0; j < 10; j++)
	            count[j] = 0; //ÿ�η���ǰ��ռ�����
	        for(j = 0; j < n; j++)
	        {
	            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
	            count[k]++;
	        }
	        for(j = 1; j < 10; j++)
	            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
	        for(j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
	        {
	            k = (data[j] / radix) % 10;
	            tmp[count[k] - 1] = data[j];
	            count[k]--;
	        }
	        for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
	            data[j] = tmp[j];
	        radix = radix * 10;
	    }
	    delete []tmp;
	    delete []count;
	} 
};


int main() {
	// �����㷨��Ҫnew Find����
	// ...
	
	// =====����ʾ�� =======
	// ����������� 
    Sort s;
    // ������ʾ�� 
    s.heapSort(6);
    // ��� 
    for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}

