#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
using ll = long long;

ll input[1010], dp[1010] = { 0, };

int main(void) {

	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &input[i]);

	// dp[x]는 x번째 원소를 포함하는 가장 큰 부분 수열의 합
	dp[0] = input[0];
	for (int i = 1; i < n; i++) {
		dp[i] = input[i];
		for (int j = 0; j < i; j++) {
			// dp[j] : j번째 원소를 포함하는 가장 큰 부분 수열의 합과 비교해서 업데이트
			if (dp[i] > dp[j])
				dp[i] = max(dp[i], dp[j] + input[i]);
		}
	}

	ll result = 0;

	for (int i = 0; i < n; i++)
		result = max(result, dp[i]);

	printf("%lld", result);

	return 0;
}