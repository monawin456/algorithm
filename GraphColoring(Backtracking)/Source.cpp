#include<iostream>

bool m_coloring(int i);
bool promising(int i);

int n;
int m;
int **W;
int *vcolor;

int main() {
	n = 5;
	m = 4;

	W = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		W[i] = new int[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			W[i][j] = 0;
		}
	}

	vcolor = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		vcolor[i] = 0;
	}

	W[1][2] = 1;	W[1][3] = 1;	W[1][4] = 1;
	W[2][1] = 1;	W[2][3] = 1;	W[2][5] = 1;
	W[3][1] = 1;	W[3][2] = 1;	W[3][4] = 1;	W[3][5] = 1;
	W[4][1] = 1;	W[4][3] = 1;	W[4][5] = 1;
	W[5][2] = 1;	W[5][3] = 1;	W[5][4] = 1;

	int i = 1;
	m_coloring(i);

	for (int i = 0; i <= n; i++) {
		delete[]W[i];
	}
	delete[]W;

	delete[]vcolor;

	return 0;
}

bool m_coloring(int i) {
	int color;
	if (promising(i)) {
		if (i == n) {
			// cout << vcolor[1] through vcolor[n];
			for (int i = 1; i <= n; i++) {
				std::cout << "v" << i << "=" << vcolor[i] << " ";
			}
			std::cout << std::endl;
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
		}
	}
	else {
		return false;

	}
	return true;
}

bool promising(int i) {
	int j;
	bool mSwitch;
	mSwitch = true;
	j = 1;
	while (j<i && mSwitch) {
		if (W[i][j] && (vcolor[i] == vcolor[j])) {
			mSwitch = false;
		}
		j++;
	}
	return mSwitch;
}
