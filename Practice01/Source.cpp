#include<iostream>

using namespace std;

void seqsearch(int n, int S[], int x, int &location, int &iter);
void binsearch(int n, int S[], int x, int &location, int &iter);
int fib(int n, int &iter);
int fib2(int n, int &iter);
void copy(int A[], int A1, int A2, int B[], int B1, int B2);
void merge(int h, int m, int U[], int V[], int S[], int &iter);
void mergesort(int n, int S[], int &iter);
void partition(int S[], int low, int high, int& pivotpoint, int &iter);
void quicksort(int S[], int low, int high, int &iter);

int main() {

	int S[20000] = { 0 };
	int n = 1000;
	int n2 = 10;
	int n3 = 100;
	int x = 1;
	int location = 0;
	int iter = 0;

	seqsearch(n, S, x, location, iter);
	cout << "SeqSearch" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	location = 0;
	binsearch(n, S, x, location, iter);
	cout << "BinSearch" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	cout << endl;
	location = 0;
	iter = 0;

	fib(n2, iter);
	cout << "Fib1" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	iter = 0;
	fib2(n2, iter);
	cout << "Fib2" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	cout << endl;
	iter = 0;

	for (int i = 1; i <= n3; i++) {
		S[i] = n3 + 1 - (i);
	}
	mergesort(n3, S, iter);
	cout << "MergeSort" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	iter = 0;

	for (int i = 1; i <= n3; i++) {
		S[i] = n3 + 1 - (i);
	}
	quicksort(S, 1, n3, iter);
	cout << "QuickSort" << endl;
	cout << "Iter : " << iter << endl;
	cout << endl;
	cout << endl;
	iter = 0;

	return 0;

}

void seqsearch(int n, int S[], int x, int &location, int &iter) {
	location = 1;
	iter = 0;
	while (location <= n && S[location] != x) {
		iter++;
		location++;
	}
	if (location > n) {
		location = 0;
	}
}

void binsearch(int n, int S[], int x, int &location, int &iter) {
	int low, high, mid;
	low = 1;
	high = n;
	location = 0;
	iter = 0;
	while (low <= high && location == 0) {
		iter++;
		mid = (low + high) / 2;
		if (x == S[mid]) {
			location = mid;
		}
		else if (x < S[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
}

int fib(int n, int &iter) {
	iter++;
	if (n <= 1) {
		return n;
	}
	else {
		return fib(n - 1, iter) + fib(n - 2, iter);
	}
}

int fib2(int n, int &iter) {
	int i;
	int *f = new int[n + 1];
	int result = 0;
	f[0] = 0;
	iter++;
	if (n > 0) {
		f[1] = 1;
		iter++;
		for (i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
			iter++;
		}
	}
	result = f[n];
	delete f;
	return result;
}

void copy(int A[], int A1, int A2, int B[], int B1, int B2) {
	while (true) {
		B[B1] = A[A1];
		if (B1 == B2 || A1 == A2) {
			break;
		}
		B1++;
		A1++;
	}
}

void merge(int h, int m, int U[], int V[], int S[], int &iter) {
	int i, j, k;
	i = 1; j = 1; k = 1;
	while (i <= h && j <= m) {
		if (U[i] < V[j]) {
			S[k] = U[i];
			i++;
			iter++;
		}
		else {
			S[k] = V[j];
			j++;
			iter++;
		}
		k++;
	}
	if (i > h)
		//copy V[j] through V[m] to S[k] through S[h + m];
		copy(V, j, m, S, k, h + m);
	else
		//copy U[i] through U[h] to S[k] through S[h + m];
		copy(U, i, h, S, k, h + m);
}

void mergesort(int n, int S[], int &iter) {
	if (n > 1) {
		const int h = n / 2;
		const int m = n - h;
		int *U = new int[h + 1];
		int *V = new int[m + 1];
		//copy S[1] through S[h] to U[1] through U[h];
		copy(S, 1, h, U, 1, h);
		//copy S[h + 1] through S[n] to V[1] through V[m];
		copy(S, h + 1, n, V, 1, m);
		mergesort(h, U, iter);
		mergesort(m, V, iter);
		merge(h, m, U, V, S, iter);
		delete U;
		delete V;
	}
}

void partition(int S[], int low, int high, int& pivotpoint, int &iter) {
	int tmp;
	int i, j;
	int pivotitem;
	pivotitem = S[low]; //pivotitem을 위한 첫번째 항목을 고른다
	j = low;
	for (i = low + 1; i <= high; i++)
		if (S[i] < pivotitem) {
			j++;
			tmp = S[i];
			S[i] = S[j];
			S[j] = tmp;
			iter++;
		}
	pivotpoint = j;
	tmp = S[low];
	S[low] = S[pivotpoint];
	S[pivotpoint] = tmp;
}

void quicksort(int S[], int low, int high, int &iter) {
	int pivotpoint;
	if (high > low) {
		partition(S, low, high, pivotpoint, iter);
		quicksort(S, low, pivotpoint - 1, iter);
		quicksort(S, pivotpoint + 1, high, iter);
	}
}
