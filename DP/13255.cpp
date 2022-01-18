#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

// 백준 동전 뒤집기

using namespace std;

int K[51];

int main(void) {

	int n, k;
	
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
		scanf("%d", &K[i]);

	// 각 차례마다 각각의 동전이 뒤집어질 확률은 p = (K[i]/n)
	// 현재 동전이 n개중 앞면인 동전의 개수의 기대값을 E라고 하면,
	// K[i]가 적용된 이후의 다시 기대값이 E 기대값은, E * (1-p) + (n - E) * p
	
	double result = n;
	for (int i = 0; i < k; i++) {
		double tmp = 0;
		tmp += result * (1.0 - ((double)K[i]/ n));
		tmp += (n - result) * ((double)K[i] / n);
		result = tmp;
	}

	cout << fixed;
	cout.precision(13);
	cout << result;

	return 0;
}