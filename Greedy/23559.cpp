#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

vector <pair<int, int>> v;

// ���� 23559 �� ����

// Greedy ������, ������ �ִ�ȭ �ϴ� �����̴�.
// 1000�� ¥�� ���, 5000�� ¥�� ���� �����ϴµ� ���� ���� ������ �־�����,
// (5000�� �� ��)  - (1000�� �� ��)�� ũ�� ������ �����ϸ�, 
// �տ��� ���� �� �� �ִ� �� K���� �̿��ؼ� �����ϸ� �ȴ�.

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
			// �� ������ ���
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