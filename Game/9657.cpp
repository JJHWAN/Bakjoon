#include <iostream>

using namespace std;
using ll = long long;

bool dp[1010];
int n;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 상근이가 이기면 true, 창영이가 이기면 false
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	dp[4] = true;

	cin >> n;

	for (int i = 5; i <= n; i++) {
		if (!(dp[i - 1] && dp[i - 3] && dp[i - 4]))
			dp[i] = true;
		else dp[i] = false;
	}

	if (dp[n])
		cout << "SK";
	else
		cout << "CY";

	return 0;
}