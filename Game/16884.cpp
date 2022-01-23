#include <iostream>

using namespace std;
using ll = long long;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		// n*n 크기의 체스판에 나이트를 배치할 수 있으며,
		// 각 플레이어는 나이트의 공격을 받지 않는 곳에만 새로운 나이트를 배치 가능하다.
		// 더 이상 배치할 수 없는 플레이어가 패배

		// 선공이 어딜 놓든 가운데 점을 원점으로 해서 점대칭을 취해 반대 위치에 놓으면 된다
		// 그러면, 선공이 놓은 나이트가 공격 가능한 위치의 점대칭이 후공의 점대칭이고,
		// 이렇게 턴이 진행되다보면, 후공이 끝나고 나면, 남은 위치는 매번 짝수
		// -> 점대칭 기준으로 완전한 대칭이기 때문에

		// N이 짝수면 항상 선공이 패배하지만,
		// N이 홀수이면, 선공이 가운데 원점에 해당하는 부분에 첫 수를 두게 되면, 
		// 후공이 선공이 되는 것과 같은 효과를 내기 때문에, 선공이 승리한다.

		if (n % 2 == 1) cout << "koosaga" << "\n";
		else cout << "cubelover" << "\n";
	}

	return 0;
}