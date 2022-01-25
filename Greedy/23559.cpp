#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

vector <pair<int, int>> v;

// 백준 23559 밥 문제

// Greedy 문제로, 이익을 최대화 하는 문제이다.
// 1000원 짜리 밥과, 5000원 짜리 밥이 존재하는데 각각 맛이 얼마인지 주어지고,
// (5000원 밥 맛)  - (1000원 밥 맛)을 크기 순으로 정렬하면, 
// 앞에서 부터 쓸 수 있는 돈 K원을 이용해서 선택하면 된다.

int cmp(pair<int, int> a, pair<int, int> b) {
	return (a.first - a.second) > (b.first - b.second) ? 1 : 0;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x, a, b, i, sum = 0;

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);

	for (i = 0; i < n; i++) {
		if (v[i].first - v[i].second > 0) {
			if (x - 5000 >= (n - 1 - i) * 1000) {
				sum += v[i].first;
				x -= 5000;
			}
			// 돈 부족한 경우
			else break;
		}
		else break;
	}

	for (; i < n; i++) {
		sum += v[i].second;
		x -= 1000;
	}

	cout << sum;

	return 0;
}