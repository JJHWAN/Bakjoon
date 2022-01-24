#include <iostream>

using namespace std;
using ll = long long;

bool dp[100100];

// 백준 22846 인증된 쉬운 게임

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 초기 모니터에는 1이 쓰여있고,
	// 각 플레이어는 약수를 모니터에 쓰여있는 수의 약수를 더 할수 있다.
	// 입력된 K를 넘어가는 플레이어가 패배
	int k;

	cin >> k;

	dp[1] = false;	dp[2] = true;
	dp[3] = false;	dp[4] = false;
	dp[5] = false;	dp[6] = true;
	dp[7] = false;

	// K가 1 ~ N 까지 연속된 자연수를 모두 약수로 가지고, N+1은 약수가 아니라고 하면,
	// K - (N+1)이 화면에 올라와 있으면? K로 바로 갈 수 없고, K - i (1<=i<=N) 로 오게 된다.
	// i는 전제에 따라 항상 K - i의 약수이기 때문에, K - i에서 항상 K로 갈 수 있다.
	// 즉, K - (N+1)을 받으면 받은 사람의 패배이다. 

	// 7의 경우, N = 1 => 5를 받으면 받으면 패배
	// 8의 경우, N = 3 => 5를 받으면 패배

	int i, j;
	for (i = 8; i <= k; i++) {
		for (j = 2;; j++) {
			if ((i % j)) break;
		}
		dp[i] = dp[i - j];
	}

	if (dp[k])
		cout << "Kali";
	else
		cout << "Ringo";


	return 0;
}