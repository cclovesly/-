#include <bits/stdc++.h>
#define MAXSIZE 10
using namespace std;

void iniArr(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 20;
	}
}

void showArr(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "------------";
}

//冒泡排序
void bubSort(int arr[], int length) {
	while (length--)
	{
		for (int i = 0; i < length; i++) {
			if (arr[i + 1] < arr[i]) {
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

//选择排序
void selectSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		int k = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[k]) {
				k = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;

	}
}


//插入排序
void insertSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;

		// 将元素arr[i]插入到已排序的序列arr[0..i-1]中  
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//插入新的元素
void insertElement(int arr[], int length, int newElement) {
	int i;
	for (i = length - 1; (i >= 0 && arr[i] > newElement); i--) {
		arr[i + 1] = arr[i]; // 将元素向后移动  
	}
	arr[i + 1] = newElement; // 插入新元素  

	// 注意：由于数组大小固定，这里的“插入”实际上是覆盖了数组的最后一个元素。  
	// 在实际应用中，您可能需要重新分配数组的大小来真正插入一个新元素。  
}

//希尔排序
void shellSort(int arr[], int length) {
	int h = 1;
	int t = length / 3;
	while (h<t)
	{
		h = 3 * h - 1;
	}
	while (h >= 1) {
		for (int i = h; i < length; i++) {
			for (int j = i; j >= h && arr[j] < arr[j - h]; j--) {
				int temp = arr[j];
				arr[j] = arr[j - h];
				arr[j - h] = temp;
			}
		}
		h /= 3;
	}
}

//快速排序
void quickSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left;
	int j = right;
	int pivot = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= pivot)
			j--;
			arr[i] = arr[j];
		while (i < j && arr[i] <= pivot)
					i++;
			arr[j] = arr[i];
	}
	//当j=i时，轴确定
	arr[i] = pivot;
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}

//归并排序
//默认序列a与序列b都是有序序列
void mergesort1(int aArr[], int alen, int bArr[], int blen, int* temp) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < alen && j < blen)
	{
		//使用三目运算符使代码更加简洁
		temp[k++] = aArr[i] < bArr[j] ? aArr[i++] : bArr[j++];
	}
	while (i < alen)
	{
		temp[k++] = aArr[i++];
	}
	while (j < blen)
	{
		temp[k++] = bArr[j++];
	}
}

//无序序列，将其拆分开，让其成为有序的多个序列
void merge(int arr[], int low, int mid, int higth, int* temp) {
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= higth)
	{
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= higth) {
		temp[k++] = arr[j++];
	}
	for (i = low; i <= higth; i++) {
		arr[i] = temp[i];
	}
}

void merge_sort(int arr[], int low, int higth, int* temp) {
	if (low >= higth) {
		return;
	}
	int mid = low + (higth - low) / 2;//(low+higth)/2;
	merge_sort(arr, low, mid, temp);
	merge_sort(arr, mid + 1, higth, temp);
	merge(arr, low, mid, higth, temp);
}

void mergesort2(int arr[], int length) {
	int* temp = new int[length];
	assert(temp);
	merge_sort(arr, 0, length - 1, temp);
	delete[] temp;
}

//入堆（内堆）
void pushHeap(int* heap, int& size, int data) {
	heap[size] = data;
	int current = size;
	int parent = (current - 1) / 2;
	while (current > 0 && heap[current] < heap[parent]) {
		swap(heap[current], heap[parent]);
		current = parent;
		parent = (current - 1) / 2;
	}
	size++;
}

//出堆（内堆）
int popHeap(int* heap, int& size) {
	int val = heap[0];
	heap[0] = heap[size - 1];
	size--;
	int current = 0;
	int child = 2 * current + 1;
	while (child < size) {
		if (child + 1 < size && heap[child + 1] < heap[child])
			child++;
		if (heap[child] >= heap[current])
			break;
		swap(heap[child], heap[current]);
		current = child;
		child = 2 * current + 1;
	}
	return val;
}

//堆排序实现（内堆）
void heapsort1(int* arr, int length) {
	int* heap = new int[length];
	int heapSize = 0;
	for (int i = 0; i < length; i++) {
		pushHeap(heap, heapSize, arr[i]);
	}
	for (int i = 0; i < length; i++) {
		arr[i] = popHeap(heap, heapSize);
	}
	delete[] heap;
}

// 调整堆（外堆）
void heapify(int arr[], int n, int i) {
	int largest = i;  // 初始化最大元素为根节点
	int left = 2 * i + 1;  // 左子节点的索引
	int right = 2 * i + 2;  // 右子节点的索引

	// 如果左子节点大于根节点
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	// 如果右子节点大于当前最大节点
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	// 如果最大节点不是根节点
	if (largest != i) {
		swap(arr[i], arr[largest]);
		// 递归调整子树
		heapify(arr, n, largest);
	}
}

// 堆排序（外堆）
void heapSort(int arr[], int n) {
	// 构建最大堆（从最后一个非叶子节点开始）
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// 逐个从堆顶取出元素，放到已排序区间末尾
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);  // 将堆顶元素（最大值）交换到末尾
		heapify(arr, i, 0);  // 对剩余的元素重新进行堆化操作
	}
}

//偷懒直接定义临时数组空间
#define N 100
int temp[N];

//计数排序实现
void countsort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		temp[arr[i]]++;
	}
	for (int i = 0, j = 0; i < N; i++) {
		while (temp[i]--)
		{
			arr[j++] = i;
		}
	}
}
//优化后
//计数排序实现
void countsort(int arr[], int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int* count = (int*)malloc((max + 1) * sizeof(int)); // 动态分配计数数组
	// 初始化计数数组
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}
	// 统计每个元素的个数
	for (int i = 0; i < length; i++) {
		count[arr[i]]++;
	}
	// 根据计数数组重新填充原数组
	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
	free(count); // 释放动态分配的内存
}

//基数排序实现
void redixsort(int arr[], int length) {
	int max_num = *max_element(arr, arr + length); // 找到数组中的最大值
	int Temp[10][N]; // 初始化Temp数组
	for (int k = 1; max_num / k > 0; k *= 10) {
		// 动态分配Temp数组的空间
		int* count = new int[10](); // 计数数组，用于记录每个桶中元素的个数
		int* output = new int[length]; // 临时数组，用于存储排序后的结果
		// 将元素分配到Temp数组中
		for (int i = 0; i < length; i++) {
			int pos = (arr[i] / k) % 10;
			Temp[pos][count[pos]++] = arr[i];
		}
		// 从Temp数组中取回元素
		int pos = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < count[i]; j++) {
				arr[pos++] = Temp[i][j];
			}
		}
		delete[] count;
		delete[] output;
	}
}

//桶排序实现
void bucketsort(int arr[], int length) {
	int max_num = 0; // 初始化最大值为0
	// 计算数组中的最大值
	for (int i = 0; i < length; i++) {
		if (arr[i] > max_num) {
			max_num = arr[i];
		}
	}
	// 动态分配临时数组
	int* Temp = new int[max_num + 1];
	// 初始化Temp数组
	for (int i = 0; i <= max_num; i++) {
		Temp[i] = 0;
	}
	// 统计每个元素出现的次数
	for (int i = 0; i < length; i++) {
		Temp[arr[i]]++;
	}
	// 将排序后的元素放回原数组
	int index = 0;
	for (int i = 0; i <= max_num; i++) {
		while (Temp[i] > 0) {
			arr[index++] = i;
			Temp[i]--;
		}
	}
	// 释放动态分配的内存
	delete[] Temp;
}

int main() {
	srand((unsigned int)time(NULL));

	int arr[MAXSIZE];

	iniArr(arr, MAXSIZE);

	showArr(arr, MAXSIZE);

	cout << endl;

	bubSort(arr, MAXSIZE);
	//selectSort(arr, MAXSIZE);
	//insertSort(arr, MAXSIZE);
	//shellSort(arr, MAXSIZE);
	//quickSort(arr, 0, MAXSIZE - 1);
	//
	////简单定义两个有序序列
	//int aArr[5] = { 1,3,5,7,9 };
	//int bArr[3] = { 2,8,10 };
	//int temp[8];
	////打印数组
	//cout << "排序前的数组:";
	//showArr(aArr, 5);
	//cout << endl;
	//showArr(bArr, 3);
	//cout << endl;
	//mergesort1(aArr, 5, bArr, 3, temp);
	////排序后的数组
	//cout << "排序后的数组:";
	//showArr(temp, 8);

	//mergesort2(arr, MAXSIZE);

	//heapSort(arr, MAXSIZE);

	//heapsort1(arr, MAXSIZE);

	//countsort(arr, MAXSIZE);

	//redixsort(arr, MAXSIZE);

	//bucketsort(arr, MAXSIZE);

	showArr(arr, MAXSIZE);
	return 0;
}