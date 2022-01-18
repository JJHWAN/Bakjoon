#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;
using ll = long long;

ll W[17][17];
ll dp[(1 << 17)][17];

int main(void) {

	int n, x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &W[i][j]);

	ll ans = INT_MAX;
	// dp[x][i] : x의 켜져있는 bit의 도시를 모두 방문했고, 
	// 마지막으로 방문한 도시가 i일때 최소 비용

	for (int ii = 0; ii < n; ii++) {
		for (int i = 1; i < (1 << n); i++)
			for (int j = 0; j < n; j++) dp[i][j] = INT_MAX;
		// 시작점 설정
		dp[(1 << ii)][ii] = 0;
		for (int i = 0; i < (1 << n); i++) {
			// 모든 경우
			for (int j = 0; j < n; j++) {
				// j 점을 선택한 경로 i가 아닌 경우
				if (!(i & (1 << j))) continue;
				for (int k = 0; k < n; k++) {
					// j->x로 가는 간선
					// 길이 없거나, 이미 가본 경우 pass
					if (!W[j][k] || (i & (1 << k))) continue;
					// 도달했다고 기록.
					x  = i | (1 << k);
					// dp 업데이트, 기존 dp vs (j, k) 간선을 거친 경우
					dp[x][k] = min(dp[x][k], dp[i][j] + W[j][k]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			// ii를 시작점으로 하는 경로의 최댓값
			// + i가 종점인 경우
			if (W[i][ii])
				ans = min(ans, dp[(1 << n) - 1][i] + W[i][ii]);
		}
	}

	printf("%lld", ans);

	return 0;
}