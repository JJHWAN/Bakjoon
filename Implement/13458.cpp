#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#define MAXNUM 1000000

using namespace std;

int n, b, c, remain;
long long result = 0;

int arr[MAXNUM];
int dp[MAXNUM+1] = {0, };

int main(void) {

	int i, tmp, tmp_result;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}

	scanf("%d %d", &b, &c);

	for (i = 0; i < n; i++) {
		if (dp[arr[i]] == 0) {
			tmp = arr[i] - b;
			tmp_result = 1;
			if (tmp > 0) {
				remain = tmp % c;
				if (remain == 0) {
					tmp_result += tmp / c;
				}
				else {
					tmp_result += tmp / c + 1;
				}
			}
			dp[arr[i]] = tmp_result;
		}
		result += dp[arr[i]];
	}

	printf("%lld", result);

	return 0;
}