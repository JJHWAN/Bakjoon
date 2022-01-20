#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
using ll = long long;

ll map[1010][1010], dp[1010][1010];

int main(void) {
	
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%lld", &map[i][j]);

	dp[0][0] = map[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + map[i][0];
	for (int j = 1; j < m; j++)
		dp[0][j] = dp[0][j - 1] + map[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + map[i][j];
		}
	}

	printf("%lld", dp[n - 1][m - 1]);

	return 0;
}