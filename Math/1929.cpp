#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

int arr[MAX+1];

int main(void) {

	int m, n;
	scanf("%d %d", &m, &n);


	arr[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		arr[i] = 1;
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				arr[i] = 0; break;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i]) printf("%d\n", i);
	}

	return 0;
}
