#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
using ll = long long;

ll n, k;
ll arr[2020202] = { 0, }, checked[2020202] = { 0, };


int main(void) {


	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &k);
		arr[k]++;
	}

	if (!arr[0]) {
		printf("0"); return 0;
	}
	if (!arr[1]) {
		printf("1"); return 0;
	}

	for (ll i = 1; i < 2020202; i++) {
		if (!arr[i]) continue;
		for (ll j = 1; j < 2020202; j++) {
			if (i * j > 2020202) break;
			if (!arr[j]) continue;
			checked[i*j] = 1;
		}
	}

	for (int i = 2; i < 2020202; i++) {
		if (checked[i]) continue;
		printf("%d", i);
		break;
	}

	return 0;
}