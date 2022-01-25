#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

//vector <ll> v, tree;
#define MAX 1000001

ll v[MAX], tree[MAX * 4];

void update(int start, int end, int node, int left, int right, int value) {
	// 범위 밖을 벗어난 경우
	if (end < left || right < start) return ;
	// 완전히 범위 내부인 경우
	if (left <= start && end <= right) {
		tree[node] += value;
		return ;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
}

void init(int start, int end, int node){
	if (start == end) {
		tree[node] = v[start];
		return;
	}
	int mid = (start + end) / 2;
	tree[node] = 0;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}

ll findX(int start, int end, int node, int idx, ll ans) {
	// idx에 해당하는 리프 노드까지 이동하면서 거치는
	// 노드의 값들을 모두 누적해서 더해준다.
	// 어차피 구간 합의 정보를 물어보는 문제가 아니니까!
	if (idx < start || end < idx) return 0;
	ans += tree[node];
	if (start == end) return ans;
	int mid = (start + end) / 2;

	return findX(start, mid, node * 2, idx, ans) + findX(mid + 1, end, node * 2 + 1, idx, ans);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, t, m;
	int a, b, c, d;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	init(0, n - 1, 1);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(0, n - 1, 1, b - 1, c - 1, d);
		}
		else {
			cin >> b;
			cout << findX(0, n-1, 1, b-1, 0) << "\n";
		}
	}

	return 0;
}