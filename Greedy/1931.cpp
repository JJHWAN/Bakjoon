#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

// 백준 1931 회의실 배정 문제
// 앞에서 부터 제일 빨리 끝나는 강의부터 배정하는 전략

// 위의 전략에 따르면 n번째로 선택한 강의가 종료 후,
// 남은 강의들은 어차피 종료 시간이 현재 시각보다 늦는다.
// 다른 강의를 선택했다면? 더 늦은 시간에 n번째 강의 완료이므로,
// 같거나, 더 적은 수의 강의만 배정가능하다. 그러므로, 최선의 경우가 아니다.

int n;

vector <pair<ll, ll>> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}

	sort(v.begin(), v.end());

	ll cur_time = -1, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].second >= cur_time) {
			// 다음 회의 선택
			cnt++;
			cur_time = v[i].first;
		}
		// 이전 회의 종료 시각 > 지금 위치의 회의 시작 시간
	}

	cout << cnt;

	return 0;
}