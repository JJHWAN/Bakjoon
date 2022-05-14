#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int map[101][101];
int n, C, E;

void print_arr() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}


int main(void) {

	cin >> n;
	cin >> C >> E;

	int k = 1, t = 1, i, j, tmp = 0;

	i = 0;

	memset(map, 0, sizeof(map));

	while (tmp < C && i< 2*n) {
		if (i < n) {
			for (j = i; j >= 0; j--) {
				if (tmp == C) break;
				map[j][i - j] = 1; tmp++;
				if (j + 1 < n) map[j + 1][i - j] = -1;
				if (i - j + 1 < n) map[j][i - j + 1] = -1;
			}
		}
		else {
			for (j = i - n + 1; j < n; j++) {
				if (tmp == C) break;
				map[i- j][j] = 1; tmp++;
				if (j + 1 < n) map[i-j][j+1] = -1;
				if (i- j + 1 < n) map[i-j+1][j] = -1;
			}
		}
		i++;
	}

	tmp = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == -1) map[i][j] = 0;
			else if (map[i][j] == 0) {
				if (tmp >= E) continue;
				map[i][j] = 2;
				tmp++;
			}
		}
	}

	if (tmp == E) {
		cout << "1\n";
		print_arr();
	}
	else cout << "-1\n";


	return 0;
}