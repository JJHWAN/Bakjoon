#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

int arr[MAX + 1];
vector <int> v;

int main(void) {

	int n = 0, k;

	while(1){
		scanf("%d", &k);
		if (!k) break;
		v.push_back(k); n++;
	}
	int i, j;

	arr[1] = 0;
	for (i = 2; i <= MAX; i++) {
		arr[i] = 1;
		for (j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				arr[i] = 0; break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 3; j <= (v[i] / 2); j += 2) {
			if (arr[j] && arr[v[i] - j]) {
				printf("%d = %d + %d\n", v[i], j, v[i] - j);
				break;
			}
		}
		if (j > v[i] / 2) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}