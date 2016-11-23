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
	n = 25;

	W = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		W[i] = new int[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			W[i][j] = 0;
		}
	}
	W[1][2] = 1; W[1][3] = 1;
	W[2][1] = 1; W[2][3] = 1; W[2][4] = 1;
	W[3][1] = 1; W[3][2] = 1; W[3][4] = 1; W[3][5] = 1;
	W[4][2] = 1; W[4][3] = 1; W[4][5] = 1; W[4][6] = 1; W[4][7] = 1;
	W[5][3] = 1; W[5][4] = 1; W[5][6] = 1; W[5][13] = 1;
	W[6][4] = 1; W[6][5] = 1; W[6][7] = 1; W[6][12] = 1; W[6][13] = 1;
	W[7][4] = 1; W[7][6] = 1; W[7][8] = 1; W[7][9] = 1; W[7][11] = 1;
	W[8][7] = 1; W[8][9] = 1; W[8][10] = 1;
	W[9][7] = 1; W[9][8] = 1; W[9][10] = 1; W[9][11] = 1;
	W[10][8] = 1; W[10][9] = 1; W[10][11] = 1; W[10][17] = 1; W[10][18] = 1; W[10][19] = 1;
	W[11][7] = 1; W[11][9] = 1; W[11][10] = 1; W[11][12] = 1; W[11][17] = 1;
	W[12][6] = 1; W[12][11] = 1; W[12][13] = 1; W[12][16] = 1; W[12][17] = 1;
	W[13][5] = 1; W[13][6] = 1; W[13][12] = 1; W[13][14] = 1; W[13][15] = 1; W[13][16] = 1;
	W[14][13] = 1; W[14][15] = 1;
	W[15][13] = 1; W[15][14] = 1; W[15][16] = 1;
	W[16][12] = 1; W[16][13] = 1; W[16][15] = 1; W[16][17] = 1; W[16][25] = 1;
	W[17][10] = 1; W[17][11] = 1; W[17][12] = 1; W[17][16] = 1; W[17][18] = 1; W[17][22] = 1; W[17][25] = 1;
	W[18][10] = 1; W[18][17] = 1; W[18][19] = 1; W[18][20] = 1; W[18][21] = 1; W[18][22] = 1;
	W[19][10] = 1; W[19][18] = 1; W[19][20] = 1;
	W[20][18] = 1; W[20][19] = 1; W[20][21] = 1;
	W[21][18] = 1; W[21][20] = 1; W[21][23] = 1;
	W[22][17] = 1; W[22][18] = 1; W[22][24] = 1; W[22][25] = 1;
	W[23][21] = 1; W[23][24] = 1;
	W[24][22] = 1; W[24][23] = 1; W[24][25] = 1;
	W[25][16] = 1; W[25][17] = 1; W[25][22] = 1; W[25][24] = 1;

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
			/*
			for (int i = 1; i <= n; i++) {
				std::cout << "v" << i << "=" << vcolor[i] << " ";
			}
			std::cout << std::endl;
			*/
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
