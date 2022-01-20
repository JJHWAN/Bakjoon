#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

// LIS problem
using namespace std;
using ll = long long;

int n;
bool dp[220][220];

void solve(char* s1, char* s2, char* s3, int k, int idx1, int idx2) {
	
	// 최소 편집 거리 문제와 굉장히 유사
	// dp[i][j] : 첫번째 문자열에서 i번째 문자까지 사용,
	// 두번째 문자열에서 j번째 문자까지 사용해서 3번째 문자열을 구현 가능? (T/F)

	// dp[i-1][j] or dp[i][j-1] 에서 부터 올 수 있다.

	int len1 = strlen(s1), len2 = strlen(s2);
	dp[0][0] = true;

	for (int i = 1; i <= len1; i++) {
		if (dp[i - 1][0] && s1[i - 1] == s3[i - 1])
			dp[i][0] = true;
		else dp[i][0] = false;
	}

	for (int i = 1; i <= len2; i++) {
		if (dp[0][i - 1] && s2[i - 1] == s3[i - 1])
			dp[0][i] = true;
		else
			dp[0][i] = false;
	}

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
				// s1과 비교
				dp[i][j] = true;
			}
			else if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
				// s2와 비교
				dp[i][j] = true;
			}
			else
				dp[i][j] = false;
		}
	}
}

int main(void) {

	scanf("%d", &n);

	char s1[220], s2[220], s3[420];

	for (int i = 0; i < n; i++) {
		scanf("%s %s %s", s1, s2, s3);
		printf("Data set %d: ", i + 1);
		
		memset(dp, 0, sizeof(dp));
		solve(s1, s2, s3, 0, 0, 0);
		if (dp[strlen(s1)][strlen(s2)] == 1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}