#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

vector<pair<ll, int>> v;
ll arr[1000001], checked[4 * 1000001] = { 0 , };

int cmp(pair<ll, int> a, pair<ll, int> b) {
	return a.first > b.first ? 1 : 0;
}

ll sum(int start, int end, int node, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return checked[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, int value) {
	if (idx < start || end < idx) return;
	checked[node] += value;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	ll ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(make_pair(arr[i], i));
	}

	sort(v.begin(), v.end(), cmp);

	// 세그먼트 트리의 arr[i]번째 원소에, 값이 i인 것의 개수를 저장
	// 즉, 세그먼트 트리의 각 원소는 구간 안에 속해 있는 값의 개수

	// 1. 우선 크기가 큰 순서대로 원소를 정렬
	// 2, 순서대로 원소를 순회하면서 그 원소의 idx 값에 대해 query(1, idx)를 정답에 더해준다.
	// => idx보다 큰 idx인데 value는 더 작은 경우를 찾는다.
	// 3. 그리고 update(idx, 1) (idx에 1을 더하는 연산) 을 하면 답을 알 수 있다.??

	for (int i = 0; i < n; i++) {
		int idx = v[i].second;
		ans += sum(0, n - 1, 1, 0, idx);
		update(0, n - 1, 1, idx, 1);
	}

	cout << ans;

	return 0;
}