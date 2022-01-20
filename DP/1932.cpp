#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
using ll = long long;

ll dp[501][501], arr[501][501];
int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= i; j++)
			scanf("%lld", &arr[i][j]);
	
	// dp[x][y] 는 아래서부터 해당 삼각형 위치까지 얻을 수 있는 최대값
	for (int i = 0; i < n; i++)
		dp[n - 1][i] = arr[n - 1][i];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
		}
	}

	printf("%lld", dp[0][0]);

	return 0;
}