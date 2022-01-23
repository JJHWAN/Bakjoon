#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
using ll = long long;

vector <pair<int, int>> v;

ll dp[510][510];

int main(void) {

	int n, r, c, j;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &r, &c);
		v.push_back(make_pair(r, c));
	}

	// dp[i][j] : i번째 행렬부터 j번째 행렬 곱 중에서 최선

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = 0;

	for (int i = 0; i < n-1; i++) {
		dp[i][i] = 0;
	}

	for (int d = 1; d < n; d++) {
		for (int i = 0; i < n - d; i++) {
			j = i + d;
			for (int k = i; k < j; k++) {
				if (!dp[i][j])
					dp[i][j] = dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second;
				else
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second);
			} 
		}
	}

	printf("%lld", dp[0][n - 1]);


	return 0;
}