#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
using ll = long long;

vector <pair<ll, int>> v;
vector <ll> ans(1000100);

int main(void) {

	int n;
	ll x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		v.push_back(make_pair(x, i));
	}
	sort(v.begin(), v.end());

	// 매번 모든 원소를 순회하면서 찾는건 시간 초과
	// arr[i]를 인덱스로 검색을 가능케 해보자.

	ll tmp = v[0].first;
	int idx= 0;

	ans[v[0].second] = 0; // v에서의 index 저장

	for (int i = 1; i < n; i++) {
		if (tmp != v[i].first) {
			ans[v[i].second] = ++idx;
			tmp = v[i].first;
		}
		else {
			ans[v[i].second] = idx;
		}
	}
	
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);

	return 0;
}