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

	// �Ź� ��� ���Ҹ� ��ȸ�ϸ鼭 ã�°� �ð� �ʰ�
	// arr[i]�� �ε����� �˻��� ������ �غ���.

	ll tmp = v[0].first;
	int idx= 0;

	ans[v[0].second] = 0; // v������ index ����

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