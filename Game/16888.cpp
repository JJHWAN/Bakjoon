#include <iostream>

using namespace std;
using ll = long long;

#define MAXNUM 1000100
// 백준 16888 루트 게임

bool dp[MAXNUM];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 각 플레이어는 턴을 번갈아 가며, 1보다 크거나 같은 완전 제곱수 x를 하나 고르고, N에서 x를 뺀다.
	// 0을 만드는 사람이 승리.

	// 1 <= T <= 10^5, 1<= N <= 10^6

	// N이 어떤 수의 완전 제곱수이면 항상 선공이 승리.
	// 모든 자연수는 완전 제곱수의 합으로 분해 가능?
	// 완전 제곱수 => 1, 4, 9, 16, ..
	// 완전 제곱수에 1이 포함되기 때문에 분해는 항상 가능하다.

	// 선공 입장에서 내가 지는 판이면, 상대방이 다시 선공일 때 지는 수로 만드려고 노력.

	dp[1] = true;

	int k = 1, j;
	for (int i = 2; i < MAXNUM; i++) {
		if (i == (k + 1) * (k + 1)) {
			dp[i] = true; k++;
		}
		else {
			for (j = 1; j <= k; j++) {
				if (!dp[i - j * j]) {
					dp[i] = true; break;
				}
			}
			if (j > k) 
				dp[i] = false;
		}
	}

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (dp[n])
			cout << "koosaga" <<"\n";
		else
			cout << "cubelover" << "\n";
	}



	return 0;
}