#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector <ll> price, road;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;

	cin >> n;
	road.resize(n - 1);
	price.resize(n);

	for (int i = 0; i < n - 1; i++)
		cin >> road[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	ll sum = 0, min_idx = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += price[min_idx] * road[i];
		if (price[i + 1] < price[min_idx])
			min_idx = i + 1;
	}

	cout << sum;

	return 0;
}