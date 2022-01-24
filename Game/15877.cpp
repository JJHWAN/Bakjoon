#include <iostream>

using namespace std;
using ll = long long;

// 백준 15877 Apples and Bannas

bool dp[1010][1010];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 각 플레이어는 본인 턴에
	// 1. 하나의 바나나		2. 하나의 사과
	// 3. 세개의 바나나와 하나의 사과
	// 4, 하나의 바나나와 세개의 사과
	// 를 삭제할 수 있다. 마지막으로 과일을 모두 지우는 플레이어가 승리
	// 과일이 초기값부터 주어지지 않으면 B가 즉시 승리

	int a, b;
	cin >> a >> b;

	if (!a && !b) {
		cout << "Bob";
		return 0;
	}
	dp[0][0] = false;
	
	int i, j;
	for (i = 0; i <= 1000; i++) {
		for (j = 0; j <= 1000; j++) {
			dp[i][j] = false;
			if (i - 1 >= 0 && j - 3 >= 0) {
				if (!dp[i - 1][j - 3]) dp[i][j] = true;
			}
			if (j - 1 >= 0 && i - 3 >= 0) {
				if (!dp[i - 3][j - 1]) dp[i][j] = true;
			}
			if (j - 1 >= 0) {
				if (!dp[i][j - 1]) dp[i][j] = true;
			}
			if (i - 1 >= 0) {
				if (!dp[i - 1][j]) dp[i][j] = true;
			}
		}
	}

	if (dp[a][b])
		cout << "Alice";
	else
		cout << "Bob";

	return 0;
}