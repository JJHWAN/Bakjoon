#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

// LCS problem

using namespace std;
using ll = long long;

string s1, s2;
ll dp[1010][1010] = {0, };

int main(void) {

	getline(cin, s1);
	getline(cin, s2);

	if (s1[0] == s2[0]) dp[0][0] = 1;

	for (int i = 1; i < s1.size(); i++) {
		if (s1[i] == s2[0]) dp[i][0] = 1;
		else dp[i][0] = dp[i - 1][0];
	}

	for (int i = 1; i < s2.size(); i++) {
		if (s2[i] == s1[0]) dp[0][i] = 1;
		else dp[0][i] = dp[0][i - 1];
	}

	int len1 = s1.size(), len2 = s2.size();

	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	printf("%lld", dp[len1 - 1][len2 - 1]);

	return 0;
}