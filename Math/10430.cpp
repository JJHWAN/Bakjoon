#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int main(void) {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int r1, r2;
	r1 = (a + b) % c;
	r2 = (a * b) % c;
	printf("%d\n%d\n%d\n%d\n", r1, r1, r2, r2);

	return 0;
}