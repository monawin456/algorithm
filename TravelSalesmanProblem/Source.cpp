#include<iostream>
#include<cmath>

#define myInf 9999 //define infinity

void travel(int n, int **W, int **P, int& minlength); //tsp function
int countBit(int bit); //count one bit in bit stream
void printPath(int n, int **P, int minlength); //print path use P array

int main() {
	//size of node
	int n = 4;
	//int n = 3;
	//int n = 5;

	//make W array
	int **W = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		W[i] = new int[n + 1];
	}
	//reset W value
	for (int i = 0; i <= n; i++) {
		W[0][i] = 0;
		W[i][0] = 0;
	}
	//input value
	W[1][1] = 0;		W[1][2] = 2;		W[1][3] = 9;		W[1][4] = myInf;
	W[2][1] = 1;		W[2][2] = 0;		W[2][3] = 6;		W[2][4] = 4;
	W[3][1] = myInf;	W[3][2] = 7;		W[3][3] = 0;		W[3][4] = 8;
	W[4][1] = 6;		W[4][2] = 3;		W[4][3] = myInf;	W[4][4] = 0;
	/*
	W[1][1] = 0;		W[1][2] = 40;		W[1][3] = 10;
	W[2][1] = 30;		W[2][2] = 0;		W[2][3] = 50;
	W[3][1] = myInf;	W[3][2] = 20;		W[3][3] = 0;
	*/
	/*
	W[1][1] = 0;		W[1][2] = 10;		W[1][3] = 15;		W[1][4] = 35;		W[1][5] = 20;
	W[2][1] = 10;		W[2][2] = 0;		W[2][3] = 20;		W[2][4] = 45;		W[2][5] = 30;
	W[3][1] = 15;		W[3][2] = 20;		W[3][3] = 0;		W[3][4] = 30;		W[3][5] = 25;
	W[4][1] = 35;		W[4][2] = 45;		W[4][3] = 30;		W[4][4] = 0;		W[4][5] = 5;
	W[5][1] = 20;		W[5][2] = 30;		W[5][3] = 25;		W[5][4] = 5;		W[5][5] = 0;
	*/

	//make P array
	int **P = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		P[i] = new int[pow(2, n) - 1];
	}
	//reset P value
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < pow(2, n) - 1; j++) {
			P[i][j] = 0;
		}
	}

	//length of path
	int minlength = 0;

	//calculate TSP and print path
	travel(n, W, P, minlength);
	printPath(n, P, minlength);

	//delete W array
	for (int i = 0; i <= n; i++) {
		delete[]W[i];
	}
	delete[]W;

	//delete P array
	for (int i = 0; i <= n; i++) {
		delete[]P[i];
	}
	delete[]P;

	return 0;
}

void travel(int n, int **W, int **P, int& minlength) {
	int i, j, k;
	int maxBit = pow(2, n); //for calculate ...111110
	int m = 2;
	int mBit = 0;
	int tmp = 0;

	//make D array
	int **D = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		D[i] = new int[maxBit - 1];
	}
	//reset D value
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < maxBit - 1; j++) {
			D[i][j] = 0;
		}
	}

	for (i = 2; i <= n; i++) { //v(i) - v(1)
		D[i][0] = W[i][1];
	}
	for (k = 1; k <= n - 2; k++) { //number of subset's element
		for (i = 2; i <= n; i++) { //all vertics without v(1)
			for (j = 2; j < maxBit; j = j + 2) { //all subsets
				if (countBit(j) == k && !(j&(int)(pow(2, i - 1)))) { //all subsets have k element and without v(i)
					while (true) {
						mBit = pow(2, m - 1);
						if (mBit&j) { //check j contain m
							tmp = W[i][m] + D[m][j - mBit];
							if (tmp < D[i][j] || D[i][j] == 0) { //store minimum value
								D[i][j] = tmp;
								P[i][j] = m; //store previously index
							}
						}
						if (m == n) {
							break;
						}
						else {
							m++;
						}
					}
					m = 2;
					mBit = 0;
					tmp = 0;
				}
			}
		}
	}
	while (true) {
		mBit = pow(2, m - 1);
		tmp = W[1][m] + D[m][maxBit - 2 - mBit];
		if (tmp < D[1][(int)(maxBit - 2)] || D[1][(int)(maxBit - 2)] == 0) {
			D[1][(int)(maxBit - 2)] = tmp;
			P[1][(int)(maxBit - 2)] = m;
		}
		if (m == n) {
			break;
		}
		else {
			m++;
		}
	}
	m = 2;
	mBit = 0;
	tmp = 0;
	minlength = D[1][(int)(maxBit - 2)];

	//Debug (Print D Array)
	/*
	for (int i = 0; i < n + 1; i++) {
	for (int j = 0; j < maxBit - 1; j++) {
	if (D[i][j] < myInf) {
	printf("%3d", D[i][j]);
	}
	else {
	printf(" IF");
	}
	}
	std::cout << std::endl << std::endl;
	}
	*/

	//delete D array
	for (int i = 0; i <= n; i++) {
		delete[]D[i];
	}
	delete[]D;
}

int countBit(int bit) {
	int tmp = bit;
	int count = 0;
	while (tmp) {
		tmp = tmp & (tmp - 1); //remove right one bit
		count++;
	}
	return count;
}

void printPath(int n, int **P, int minlength) {
	int i = 1;
	int j = pow(2, n) - 2;
	int v = 0;
	std::cout << "Path: v1 -> ";
	while (j) {
		v = P[i][j];
		std::cout << "v" << v << " -> ";
		i = v; //previously index
		j = j - pow(2, v - 1);
	}
	std::cout << "v1" << std::endl;
	std::cout << "Length: " << minlength << std::endl;
}
