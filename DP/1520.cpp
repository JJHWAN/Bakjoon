#include <iostream>
#include <memory.h>
using namespace std;
using ll = long long;

// M, N <= 500

int m, n;
int maze[501][501], dp[501][501], checked[501][501];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int x, int y) {

	if (dp[x][y] > 0) {
		// 이후 길의 개수가 구해져있는 dp[x][y]까지 도달했다면
		return dp[x][y];
	}
	else {
		// 이미 방문해서 확인한 좌표라면 => 길이 없는 곳이면 더 이상 확인하지 않고 돌아간다.
		if (checked[x][y]) return 0;

		int tempx, tempy, result, sum = 0;
		for (int i = 0; i < 4; i++) {
			tempx = x + dir[i][0];
			tempy = y + dir[i][1];
			if (tempx >= 0 && m > tempx && tempx >= 0 && n > tempy) {
				// 우리가 고려해야하는 위치내의 좌표라면
				// dfs를 이용해서 각 좌표의 값을 구해준다.
				if (maze[tempx][tempy] < maze[x][y]) {
					// 내려가는 지점이라면
					dp[x][y] += dfs(tempx, tempy);
				}
			}
		}
		
		if (dp[x][y] == 0)
			checked[x][y] = 1; // 여긴 길 없어요~
		return dp[x][y];
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	memset(maze, -1, sizeof(maze));
	memset(dp, 0, sizeof(dp));
	memset(checked, 0, sizeof(checked));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	// dp[x][y] -> (x, y) 부터 출구로 나가는 경우의 수
	// 상하좌우 모두 이동가능
	// 항상 높이가 더 낮은 지점으로만 이동 가능
	// -> 내가 이동한 지점으로부터 다시 올수는 없다.
	dp[m - 1][n - 1] = 1;
	dfs(0, 0);
	
	cout << dp[0][0];

	return 0;
}