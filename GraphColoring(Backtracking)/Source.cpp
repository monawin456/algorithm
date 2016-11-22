#include<iostream>

void m_coloring(int i);
bool promising(int i);

int n; //number of vertices
int m; //number of colors
int **W; //graph
int *vcolor; //result

int i; //index
bool coloring;
int num; //number of all cases

int main() {
	//set condition
	n = 5;

	W = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		W[i] = new int[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			W[i][j] = 0;
		}
	}
	W[1][2] = 1;	W[1][3] = 1;	W[1][4] = 1;
	W[2][1] = 1;	W[2][3] = 1;	W[2][5] = 1;
	W[3][1] = 1;	W[3][2] = 1;	W[3][4] = 1;	W[3][5] = 1;
	W[4][1] = 1;	W[4][3] = 1;	W[4][5] = 1;
	W[5][2] = 1;	W[5][3] = 1;	W[5][4] = 1;

	vcolor = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		vcolor[i] = 0;
	}

	//start coloring
	m = 1;
	i = 0;
	coloring = false;
	num = 0;

	while(!coloring){
		m_coloring(i);
		m++;
		i = 0;
	}

	std::cout << "Least number of colors: " << m << std::endl;
	std::cout << "Number of all cases: " << num << std::endl;

	//delete condition
	for (int i = 0; i <= n; i++) {
		delete[]W[i];
	}
	delete[]W;

	delete[]vcolor;

	//end
	return 0;
}

void m_coloring(int i) {
	int color;
	if (promising(i)) {
		if (i == n) {
			for (int i = 1; i <= n; i++) {
				std::cout << "v" << i << "=" << vcolor[i] << " ";
			}
			std::cout << std::endl;
			coloring = true;
			num++;
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
		}
	}
}

bool promising(int i) {
	int j;
	bool pSwitch;
	pSwitch = true;
	j = 1;
	while (j<i && pSwitch) {
		if (W[i][j] && (vcolor[i] == vcolor[j])) {
			pSwitch = false;
		}
		j++;
	}
	return pSwitch;
}
