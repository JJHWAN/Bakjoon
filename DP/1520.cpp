#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int m, n;
int map[501][501];
int D[501][501] = { -1, };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int x, int y);

int dfs(int x, int y) {


	if (x == m - 1 && y == n - 1) return 1;

	if (D[x][y] == -1) {
		// 처음 진출한 경우,
		D[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			if (x + dir[i][0] < 0 || x + dir[i][0] >= m) continue;
			if (y + dir[i][1] < 0 || y + dir[i][1] >= n) continue;
			if (map[x + dir[i][0]][y + dir[i][1]] < map[x][y])
				D[x][y] += dfs(x + dir[i][0], y + dir[i][1]);
		}
	}

	return D[x][y];
}

int main(void) {

	scanf("%d %d", &m, &n);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// DFS + DP? or backtracking?
	// 무지성 DFS 결과 -> 시간 초과!
	// 1. 항상 내리막길로만 이동 가능하다

	printf("%d", dfs(0, 0));


	return 0;
}