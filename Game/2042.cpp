#include <iostream>

#define MAXNUM 1000001

using namespace std;
using ll = long long;

ll v[MAXNUM];
ll tree_max[4 * MAXNUM];

long long init(int start, int end, ll node) {
	if (start == end) 
		return tree_max[node] = v[start];
	int mid = (start + end) / 2;
	return tree_max[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, ll node, int idx, ll diff) {
	// 범위 넘어가면 갱신 X
	if (idx < start || end < idx) return;
	// 내려가면서 업데이트
	tree_max[node] += diff;
	// 리프 노드인 경우
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

long long sum(int start, int end, ll node, int left, int right) {

	// 범위 밖에 있는 경우
	if (left > end || right < start) return 0;
	// 범위 내부에 있는 경우
	if (left <= start && end <= right) return tree_max[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	ll a, b, c;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	init(0, n - 1, 1);
	
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, n-1, 1, b-1, c - v[b-1]);
			// v 업데이트 안 해주면, 나중에 다시 바꿀 때, 에러
			v[b - 1] = c;
		}
		else {
			cout << sum(0, n-1, 1, b-1, c-1) << "\n";
		}
	}

	return 0;
}