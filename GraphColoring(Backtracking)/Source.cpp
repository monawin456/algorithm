void m_coloring(index i) {
	int color;
	if (promising(i))
		if (i == n) cout << vcolor[1] through vcolor[n];
		else
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
}
bool promising(index i) {
	int j; bool switch;
	switch = TRUE;
	j = 1;
	while (j<i && switch) {
		if (W[i][j] && vcolor[i] == vcolor[j]) switch = FALSE;
		j++;
	}
	return switch;
}
