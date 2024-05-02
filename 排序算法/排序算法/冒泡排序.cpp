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

//ð������
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

//ѡ������
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


//��������
void insertSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;

		// ��Ԫ��arr[i]���뵽�����������arr[0..i-1]��  
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//�����µ�Ԫ��
void insertElement(int arr[], int length, int newElement) {
	int i;
	for (i = length - 1; (i >= 0 && arr[i] > newElement); i--) {
		arr[i + 1] = arr[i]; // ��Ԫ������ƶ�  
	}
	arr[i + 1] = newElement; // ������Ԫ��  

	// ע�⣺���������С�̶�������ġ����롱ʵ�����Ǹ�������������һ��Ԫ�ء�  
	// ��ʵ��Ӧ���У���������Ҫ���·�������Ĵ�С����������һ����Ԫ�ء�  
}

//ϣ������
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

//��������
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
	//��j=iʱ����ȷ��
	arr[i] = pivot;
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}

//�鲢����
//Ĭ������a������b������������
void mergesort1(int aArr[], int alen, int bArr[], int blen, int* temp) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < alen && j < blen)
	{
		//ʹ����Ŀ�����ʹ������Ӽ��
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

//�������У������ֿ��������Ϊ����Ķ������
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

//��ѣ��ڶѣ�
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

//���ѣ��ڶѣ�
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

//������ʵ�֣��ڶѣ�
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

// �����ѣ���ѣ�
void heapify(int arr[], int n, int i) {
	int largest = i;  // ��ʼ�����Ԫ��Ϊ���ڵ�
	int left = 2 * i + 1;  // ���ӽڵ������
	int right = 2 * i + 2;  // ���ӽڵ������

	// ������ӽڵ���ڸ��ڵ�
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	// ������ӽڵ���ڵ�ǰ���ڵ�
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	// ������ڵ㲻�Ǹ��ڵ�
	if (largest != i) {
		swap(arr[i], arr[largest]);
		// �ݹ��������
		heapify(arr, n, largest);
	}
}

// ��������ѣ�
void heapSort(int arr[], int n) {
	// �������ѣ������һ����Ҷ�ӽڵ㿪ʼ��
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// ����ӶѶ�ȡ��Ԫ�أ��ŵ�����������ĩβ
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);  // ���Ѷ�Ԫ�أ����ֵ��������ĩβ
		heapify(arr, i, 0);  // ��ʣ���Ԫ�����½��жѻ�����
	}
}

//͵��ֱ�Ӷ�����ʱ����ռ�
#define N 100
int temp[N];

//��������ʵ��
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
//�Ż���
//��������ʵ��
void countsort(int arr[], int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int* count = (int*)malloc((max + 1) * sizeof(int)); // ��̬�����������
	// ��ʼ����������
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}
	// ͳ��ÿ��Ԫ�صĸ���
	for (int i = 0; i < length; i++) {
		count[arr[i]]++;
	}
	// ���ݼ��������������ԭ����
	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
	free(count); // �ͷŶ�̬������ڴ�
}

//��������ʵ��
void redixsort(int arr[], int length) {
	int max_num = *max_element(arr, arr + length); // �ҵ������е����ֵ
	int Temp[10][N]; // ��ʼ��Temp����
	for (int k = 1; max_num / k > 0; k *= 10) {
		// ��̬����Temp����Ŀռ�
		int* count = new int[10](); // �������飬���ڼ�¼ÿ��Ͱ��Ԫ�صĸ���
		int* output = new int[length]; // ��ʱ���飬���ڴ洢�����Ľ��
		// ��Ԫ�ط��䵽Temp������
		for (int i = 0; i < length; i++) {
			int pos = (arr[i] / k) % 10;
			Temp[pos][count[pos]++] = arr[i];
		}
		// ��Temp������ȡ��Ԫ��
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

//Ͱ����ʵ��
void bucketsort(int arr[], int length) {
	int max_num = 0; // ��ʼ�����ֵΪ0
	// ���������е����ֵ
	for (int i = 0; i < length; i++) {
		if (arr[i] > max_num) {
			max_num = arr[i];
		}
	}
	// ��̬������ʱ����
	int* Temp = new int[max_num + 1];
	// ��ʼ��Temp����
	for (int i = 0; i <= max_num; i++) {
		Temp[i] = 0;
	}
	// ͳ��ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < length; i++) {
		Temp[arr[i]]++;
	}
	// ��������Ԫ�طŻ�ԭ����
	int index = 0;
	for (int i = 0; i <= max_num; i++) {
		while (Temp[i] > 0) {
			arr[index++] = i;
			Temp[i]--;
		}
	}
	// �ͷŶ�̬������ڴ�
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
	////�򵥶���������������
	//int aArr[5] = { 1,3,5,7,9 };
	//int bArr[3] = { 2,8,10 };
	//int temp[8];
	////��ӡ����
	//cout << "����ǰ������:";
	//showArr(aArr, 5);
	//cout << endl;
	//showArr(bArr, 3);
	//cout << endl;
	//mergesort1(aArr, 5, bArr, 3, temp);
	////����������
	//cout << "����������:";
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