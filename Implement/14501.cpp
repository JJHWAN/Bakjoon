#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 1<=n<=15, brute force with recursion

int n, i, x, y;
vector <pair <int, int>> v;

int func(int);

int func(int k) {

	if (k == n) return 0;

	if (v[k].first + k > n) return func(k + 1);
	return max(v[k].second + func(k + v[k].first), func(k + 1));
}


int main(void) {
	
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	printf("%d", func(0));

	return 0;
}