#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 백준 17965번 Absolute Game 문제
// 입력으로는 두 플레이어에게 같은 길이의 int 형 배열 2개가 들어온다.
// 플레이어 A, B가 존재하며, 플레이어는 자기 턴마다 본인의 배열에서 하나의 원소를 지워야한다.
// 원소가 하나 남았을 때, 두 플레이어 원소 간의 Abs-Difference를 크게 하는 것이 A의 목표이다.
// 반대로 B의 목표는 최대한 작게 하는 것이다.

// 서로 최선의 수를 둔다고 만 했을 때, Abs-Diffference 는?

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, tmp;
	
	vector <ll> a, b;

	cin >> n;

	ll A, ans = -1e12;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}

	// Abs-difference : 두 원소 사이의 차이의 절대값
	// A-B 원소 사이에 차이가 가장 작은 원소끼리 간선이 이어져 있다고 생각하면
	// 그러면 A 입장에서 뭘 지우던지, B는 간선이 이어져 있지 않은 원소만 지우면 된다.	
	// B는 결국 그러면 A가 무슨 원소를 남기던 그 차이가 최소인 원소를 남길 수 있다.

	// 그러므로, 우리는 A[i] 마다의 최적 답을 구해서 서로 비교하면 된다.


	for (int i = 0; i < n; i++) {
		A = 1e12;
		for (int j = 0; j < n; j++) {
			A = min(A, abs(b[j] - a[i]));
		}
		ans = max(ans, A);
	}

	cout << ans;

	return 0;
}