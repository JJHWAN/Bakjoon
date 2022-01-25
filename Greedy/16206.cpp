#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int arr[1001];

int cmp(int a, int b) {
	return a > b ? 1 : 0;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, cnt = 0;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] % 10 == 0) {
			m -= (arr[i] / 10 - 1);
			cnt += (arr[i] / 10);
			if (m < 0) {
				cnt += m - 1;
				m = 0; break;
			}
			arr[i] = 0;
		}
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		if (arr[i] < 10) break;
		if (!m) break;
		m -= (arr[i] / 10);
		cnt += (arr[i] / 10);
		if (m < 0) {
			cnt += m; break;
		}
	}
	cout << cnt;

	return 0;
}