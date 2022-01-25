#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// n이 주어졌을 때, k개의 inversion을 만드는 문제
int v[4243] = { 0, };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, k, cnt = 0;

	cin >> n >> k;

	// k개 
	// idx 0에서는 n-1개 가능
	// idx 1에서는 n-2개 가능
	// ...

	for (int i = 0; i < n; i++) {
		if (k >= n - 1 - i) {
			v[i] = n - cnt++;
			k -= n - 1 - i;
		}
	}

	cnt = 1;
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			v[i] = cnt++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << "\n";
	

	return 0;
}