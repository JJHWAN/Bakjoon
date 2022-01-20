#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
using ll = long long;

ll dp[1010];

int main(void) {

	int n;

	// 2*n 크기의 블록을 2*1, 1*2 크기의 블록으로 채우는 경우의 수
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	scanf("%d", &n);

	printf("%lld", dp[n]);


	return 0;
}