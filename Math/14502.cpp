#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


int max_clear = 0, n, m;
int dir[4][2] = { {0, 1}, {0, -1}, {+1, 0}, {-1, 0} };

void check(int x1, int x2, int x3, int y1, int y2, int y3, int arr2[9][9]) {
	if (x1 == x2 && y1 == y2) return;
	if (x1 == x3 && y1 == y3) return;
	if (x2 == x3 && y2 == y3) return;

	int arr[9][9];
	memcpy(arr, arr2, sizeof(arr));

	int change = 0, cnt = 0;

	arr[x1][y1] = 1; arr[x2][y2] = 1; arr[x3][y3] = 1;
	while (1) {
		change = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 2) {
					for (int k = 0; k < 4; k++) {
						if (i + dir[k][0] > n || i + dir[k][0] == 0) continue;
						if (j + dir[k][1] > m || j + dir[k][1] == 0) continue;
						if (arr[i + dir[k][0]][j + dir[k][1]] == 0) {
							arr[i + dir[k][0]][j + dir[k][1]] = 2;
							change++;
						}
					}
				}
			}
		}
		if (change == 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (arr[i][j] == 0) cnt++;
				}
			}
			break;
		}
		
	}

	if (cnt > max_clear) {
		max_clear = cnt;
	}
}

int main(void) {

	int arr[9][9];
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i+1][j+1]);
		}
		//getchar();
	}
	int x1, x2, x3;
	int y1, y2, y3;

	for (x1 = 1; x1 <= n; x1++) {
		for (x2 = x1; x2 <= n; x2++) {
			for (x3 = x2; x3 <= n; x3++) {
				for (y1 = 1; y1 <= m; y1++) {
					if (arr[x1][y1] != 0) continue;
					for (y2 = 1; y2 <= m; y2++) {
						if (arr[x2][y2] != 0) continue;
						for (y3 = 1; y3 <= m; y3++) {
							if (arr[x3][y3] != 0) continue;
							check(x1, x2, x3, y1, y2, y3, arr);
						}
					}
				}
			}
		}
	}

	printf("%d", max_clear);

	return 0;
}