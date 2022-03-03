#include <iostream>
#include <memory.h>
using namespace std;
using ll = long long;

int n;
ll maze[101][101], checked[101][101], dp[101][101];

ll dfs(int x, int y) {

    if (x == n - 1 && y == n - 1) return 1;
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    if (maze[x][y] == 0) return 0;

    if (dp[x][y] > 0) {
        return dp[x][y];
    }
    else {
        if (checked[x][y]) return 0;
        
        int k = maze[x][y];

        dp[x][y] = 0;
        dp[x][y] += dfs(x + k, y);
        dp[x][y] += dfs(x, y + k);

        if (dp[x][y] == 0) checked[x][y] = 1;

        return dp[x][y];
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(maze, -1, sizeof(maze));
    memset(dp, 0, sizeof(dp));
    memset(checked, 0, sizeof(checked));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    
    dp[n - 1][n - 1] = 1;
    dfs(0, 0);
    cout << dp[0][0];

    return 0;
}