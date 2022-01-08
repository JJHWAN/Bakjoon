#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
using ll = long long;

int main(void) {
	int t;
	ll n;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%lld", &n);
		if (n % 9 == 0 || n % 3 == 2) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}