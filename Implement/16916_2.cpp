#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;
using ll = long long;

string S, pattern;
ll poly_s = 0, poly_p = 0;

int main(void) {

	ll k = 1;

	getline(cin, S);
	getline(cin, pattern);

	if (S.size() < pattern.size()) {
		printf("0"); return 0;
	}

	for (size_t i = 0; i < pattern.size(); i++) {
		poly_p += k * (pattern[i] - 'a' + 1);
		poly_s += k * (S[i] - 'a' + 1);
		k *= 27;
	}
	k /= 27;

	for (size_t i = pattern.size(); i < S.size(); i++) {
		if (poly_p == poly_s) {
			break;
		}
		poly_s -= (S[i - pattern.size()] - 'a' + 1);
		poly_s = poly_s / 27;
		poly_s += k * (S[i] - 'a' + 1);
	}

	if (poly_p == poly_s)
		printf("1");
	else
		printf("0");

	return 0;
}