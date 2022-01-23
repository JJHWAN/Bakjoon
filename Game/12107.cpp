#include <iostream>

// A, B의 약수 지우기 게임
// 1 ~ N 까지의 자연수가 적혀 있고,
// 각 사람은 자신의 턴에 칠판에 적힌 자연수 하나와 그 자연수의 약수를 지운다.
// 마지막 숫자를 지우는 사람이 승리

// 숫자가 하나 남거나, 남은 숫자들이 모두 가장 큰 남은 숫자의 약수인 경우
// 턴을 잡은 사람이 패배한다.

// 1은 모든 해의 약수이다. => 어떤 수를 선택하든 1은 지워진다.
// 1. 선공이 지는 형태의 N이면, 1만 지우고 짝수에게 넘겨주고,
// 2. 이기는 형태의 뭔지는 모르겠지만 이기는 수를 두면 된다.

using namespace std;
using ll = long long;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;

	if (n == 1) cout << "B";
	else cout << "A";

	return 0;
}