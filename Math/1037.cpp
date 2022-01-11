#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector <int> v;

int main(void) {

	int n, k;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
	}

	sort(v.begin(), v.end());

	printf("%d", v[0] * v[n - 1]);

	return 0;
}