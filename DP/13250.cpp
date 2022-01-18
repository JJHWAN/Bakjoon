#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;


double DP[8];

int main(void) {

	int n;
	double result = 0, tmp = 0;
	scanf("%d", &n);

	// f(x) = (f(x-1) + f(x-2)+ ... + f(x-6))*(1/6);
	// f(x) - f(x-1) = (f(x-1) - f(x-7)) * 1/6;
	// f(x) = f(x-1) + (f(x-1) - f(x-7)) * 1/6;
	
	// 초기값 설정
	DP[0] = 1;
	DP[1] = 1; tmp = 1 + 1;

	for (int i = 2; i < 7; i++) {
		DP[i] = (1.0 / 6) * (7 - i) + (1.0 / 6) * tmp;
		tmp += DP[i] +1;
	}
	DP[7] = (1.0 / 6) * tmp;

	if (n < 8) {
		cout << fixed;
		cout.precision(13);
		cout << DP[n];
		return 0;
	}

	int idx = 8;

	while (idx <= n) {
		DP[0] = DP[7] + (DP[7] - DP[1])* (1.0 / 6);
		for (int i = 1; i < 7; i++) {
			DP[i] = DP[i + 1];
		}
		DP[7] = DP[0];
		idx++;
	}
	cout << fixed;
	cout.precision(13);
	cout << DP[0];

	return 0;
}