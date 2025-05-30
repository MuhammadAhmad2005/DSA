#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<conio.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

void Bubble(int x[], int n) {
	int hold, j, pass;
	int switched = true;
	int comparisons = 0;
	int exchanges = 0;

	for (pass = 0; pass < n - 1 && switched == true; pass++) {
		switched = false;
		for (j = 0; j < n - pass - 1; j++) {
			comparisons++;  // each comparison in if
			if (x[j] > x[j + 1]) {
				switched = true;
				exchanges++;  // swap counted as exchange
				hold = x[j];
				x[j] = x[j + 1];
				x[j + 1] = hold;
			}
		}
	}
	cout << "Bubble Sort: Comparisons = " << comparisons << ", Exchanges = " << exchanges << endl;
}

void insertionSort(int x[], int n) {
	int j, k, y;
	int comparisons = 0;
	int exchanges = 0;  // moving elements counted as exchanges

	for (k = 1; k < n; k++) {
		y = x[k];
		j = k - 1;
		while (j >= 0) {
			comparisons++;  // for each comparison y < x[j]
			if (y < x[j]) {
				x[j + 1] = x[j];
				exchanges++;  // shifting element is an exchange
				j--;
			}
			else {
				break;
			}
		}
		x[j + 1] = y;
		exchanges++;  // placing y in the right place counted as exchange
	}
	cout << "Insertion Sort: Comparisons = " << comparisons << ", Exchanges = " << exchanges << endl;
}

void selectionSort(int x[], int n) {
	int key;
	int comparisons = 0;
	int exchanges = 0;

	for (int a = 0; a < n; a++) {
		key = a;
		for (int b = a + 1; b < n; b++) {
			comparisons++;  // each comparison x[b] < x[key]
			if (x[b] < x[key]) key = b;
		}
		if (key > a) {
			exchanges++;  // swapping elements
			int temp = x[a];
			x[a] = x[key];
			x[key] = temp;
		}
	}
	cout << "Selection Sort: Comparisons = " << comparisons << ", Exchanges = " << exchanges << endl;
}

void heapSort(int x[], int n) {
	vector<int> heap(x, x + n); 
	int exchanges = 0;

	make_heap(heap.begin(), heap.end());

	for (int i = n - 1; i >= 0; i--) {
		pop_heap(heap.begin(), heap.begin() + i + 1);
		x[i] = heap[i];
		exchanges++;  // Each pop_heap swaps the root to end
	}

	cout << "Heap Sort (STL): Estimated Exchanges = " << exchanges << endl;
}

void printArray(const char* label, int x[], int n) {
	cout << label;
	for (int i = 0; i < n; i++) cout << x[i] << " ";
	cout << "\n";
}

int main() {

	// Execution time
	/*time_t start, end;
	char szInput[25];
	double dif;

	time(&start);
	cout << "\nPlease, enter your name: ";
	cin >> szInput;

	time(&end);
	dif = difftime(end, start);

	cout << "\nHi " << szInput<<"! ";
	cout << "\nIt took you " << dif << " seconds to type your name. " << endl;*/

	const int max = 100;
	int n;
	cout << "Enter array size: ";
	cin >> n;

	int arr[max];
	for (int i = 0; i < n; i++) {
		arr[i] = rand()%100; 
	}

	int* bubbleArr = new int[n];
	int* insertArr = new int[n];
	int* selectArr = new int[n];
	int* heapArr = new int[n];

	for (int i = 0; i < n; i++) {
		bubbleArr[i] = arr[i];
		insertArr[i] = arr[i];
		selectArr[i] = arr[i];
		heapArr[i] = arr[i];
	}

	
	auto start = high_resolution_clock::now();
	Bubble(bubbleArr, n);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	cout << "Bubble Sort Time: " << duration.count() << " ms\n";

	auto start1 = high_resolution_clock::now();
	insertionSort(insertArr, n);
	auto end1 = high_resolution_clock::now();
	auto duration1 = duration_cast<nanoseconds>(end - start);
	cout << "Insertion Sort Time: " << duration1.count() << " ms\n";

	auto start2 = high_resolution_clock::now();
	selectionSort(selectArr, n);
	auto end2 = high_resolution_clock::now();
	auto duration2 = duration_cast<nanoseconds>(end - start);
	cout << "Selection Sort Time : " << duration2.count() << " ms\n";

	auto start3 = high_resolution_clock::now();
	heapSort(heapArr, n);
	auto end3 = high_resolution_clock::now();
	auto duration3 = duration_cast<nanoseconds>(end - start);
	cout << "Heap Sort Time : " << duration3.count() << " ms\n";

	// Display results
	printArray("Original Array: ", arr, n);
	printArray("Bubble Sort:    ", bubbleArr, n);
	printArray("Insertion Sort: ", insertArr, n);
	printArray("Selection Sort: ", selectArr, n);
	printArray("Heap Sort :  ", heapArr, n);

	// Clean up
	delete[] arr;
	delete[] bubbleArr;
	delete[] insertArr;
	delete[] selectArr;
	delete[] heapArr;
	
	_getch();
	return 0;
}