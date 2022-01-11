#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

int arr[1001] = { 0, };
vector <int> v;

int main(void) {
	
	int n, k;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
	}

	arr[1] = 0;
	for (int i = 2; i <= 1000; i++) {
		arr[i] = 1;
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				arr[i] = 0; break;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[v[i]]) cnt++;
	}

	printf("%d", cnt);

	return 0;
}
