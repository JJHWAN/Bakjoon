#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

int main(void) {

	int a, b, r1, r2;

	scanf("%d %d", &a, &b);

	r1 = gcd(a, b);
	r2 = a * b / r1;

	printf("%d\n%d\n", r1, r2);

	return 0;
}