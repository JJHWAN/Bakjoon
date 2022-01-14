#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
using ll = long long;
vector <int> A, B;

bool cmp(int a, int b) {
	return a < b ? 0 : 1;
}

int main(void) {

	ll s = 0;
	int n, tmp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		A.push_back(tmp);
	}

	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		B.push_back(tmp);
	}	

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < n; i++)
		s += A[i] * B[n- 1 - i];

	printf("%lld", s);


	return 0;
}