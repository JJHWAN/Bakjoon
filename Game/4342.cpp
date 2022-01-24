#include <iostream>

using namespace std;
using ll = long long;

int solve(ll a, ll b, bool player) {
	// a > b

	if (a % b == 0) {
		return player;
	}

	if (a / b == 1) {
		// 현재 플레이어에게 조정 권한 X
		return solve(b, a % b, !player);
	}
	else {
		// a = kb + m이라고 했을 때,
		// (b, m)이 만약 현재 플레이어가 넘겨주면 지는 숫자 조합이면,
		// 현재 플레이어는 (k-1)만 빼고 넘겨주면 (b,m)을 받아올 수 있다.
		// 반대로 이기는 판이면, kb를 빼고 넘겨주면 상대방에게 (b, m) 강요 가능
		return player;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a = 1, b = 1;
	while (1) {
		cin >> a >> b;
		if (a + b == 0) break;
		if (a < b) {
			ll tmp = a;
			a = b;
			b = tmp;
		}
		if (!solve(a, b, 0))
			cout << "A wins" << "\n";
		else
			cout << "B wins" << "\n";
	}
	return 0;
}