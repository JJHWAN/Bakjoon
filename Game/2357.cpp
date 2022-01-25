#include <iostream>

using namespace std;
using ll = long long;

ll v[100001], tree_max[400004], tree_min[400004];

long long init_max(int start, int end, int node) {
	if (start == end) return tree_max[node] = v[start];
	int mid = (start + end) / 2;
	ll left = init_max(start, mid, node * 2);
	ll right = init_max(mid + 1, end, node * 2 + 1);
	return tree_max[node] = max(left, right);
}

long long find_max(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree_max[node];
	int mid = (start + end) / 2;
	return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));
}

long long init_min(int start, int end, int node) {
	if (start == end) return tree_min[node] = v[start];
	int mid = (start + end) / 2;
	ll left = init_min(start, mid, node * 2);
	ll right = init_min(mid + 1, end, node * 2 + 1);
	return tree_min[node] = min(left, right);
}

long long find_min(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return tree_min[node];
	int mid = (start + end) / 2;
	ll l = find_min(start, mid, node * 2, left, right);
	ll r = find_min(mid + 1, end, node * 2 + 1, left, right);
	if (l == -1) return r;
	if (r == -1) return l;
	return min(l, r);
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, l, r;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	init_max(0, n - 1, 1);
	init_min(0, n - 1, 1);

	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		cout << find_min(0, n - 1, 1, l - 1, r - 1) << " ";
		cout << find_max(0, n - 1, 1, l - 1, r - 1) << "\n";
	}

	return 0;
}