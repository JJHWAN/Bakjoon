#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


int main(void) {

	int n, k, i, j;
	int arr[100], DP[100][10001] = { 0, };

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
	// 동전의 가치는 100,000 보다 작거나 같은 자연수
	// 구하는 최대 가치는 10,000

	// DP[i][k]는 i번째 동전까지 사용해 합이 k가 되는 경우의 수

	 
	for (i = 0; i < n; i++) {
		DP[i][0] = 1; // 0원인 경우, 아무 동전도 내지 않는 경우의 수가 항상 존재
	}

	for (i = 0; i < n; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= arr[i]) {
				DP[i][j] = DP[i][j - arr[i]] + DP[i - 1][j];
				// 1. i번째 동전까지 활용한 더 작은 수
				// 2. i-1번째 동전까지만 쓴 경우
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}

	printf("%d\n", DP[n - 1][k]);

	return 0;
}