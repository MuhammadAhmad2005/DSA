#include<iostream>
#include<algorithm>
using namespace std;

// Sequential search with comparison count
int sequential(int x[], int n, int key, int& comparisons) {
	for (int i = 0; i < n; i++) {
		comparisons++;
		if (key == x[i])return i;
	}
	return -1;
}

// Binary search
int binary(int x[], int n, int key,int& comparisons) {
	int low = 0;
	int hi = n - 1;
	while (low <= hi) {
		int mid = (low + hi) / 2;
		comparisons++;
		if (key == x[mid])
			return mid;
		comparisons++;
		if (key < x[mid])
			hi = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main() {
	int N,cmp;
	cout << "Enter size of array (N): ";
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		arr[i] = rand() % 100;

	int* sortedArr = new int[N];
	for (int i = 0; i < N; i++)
		sortedArr[i] = arr[i];
	sort(sortedArr, sortedArr + N);


	cout << "\n--- Sequential Search ---";
	cmp = 0;
	sequential(arr, N, 50, cmp);
	cout << "\nSuccessful Search Comparisons: " << cmp;

	cmp = 0;
	sequential(arr, N,-1, cmp);
	cout << "\nUnsuccessful Search Comparisons: " << cmp;

	cout << "\n\n--- Binary Search ---";
	cmp = 0;
	binary(sortedArr, N, 29, cmp);
	cout << "\nSuccessful Search Comparisons: " << cmp;

	cmp = 0;
	binary(sortedArr, N, -1, cmp);
	cout << "\nUnsuccessful Search Comparisons: " << cmp;

	delete[] arr;
	delete[] sortedArr;

	return 0;
}
