#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
using ll = long long;

#define MAXNUM 1000000

ll f[MAXNUM + 1];
ll result[MAXNUM + 1] = { 0, };
vector<int> v;


int main(void) {

	// N이 주어지면 -> 1, 2, 3, 4 ..., N을 몫으로 가지는 수들을 검사
	int n, t, i;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}

	// g(x) = f(x) + g(x-1)

	
	for (i = 1; i <= MAXNUM; i++) {
		for (int j = 1; i * j <= MAXNUM; j++) {
			f[i * j] += i;
		}
	}

	result[1] = 1;
	for (i = 2; i <= MAXNUM; i++) {
		result[i] = result[i - 1] + f[i];
	}


	for (i = 0; i < t; i++) {
		printf("%lld\n", result[v[i]]);
	}

	return 0;
}