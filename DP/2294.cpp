#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;

int arr[100];
long long D[100][10001] = { 0, };

int main(void) {

	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	// D[i][j] = i번째 동전을 까지 사용하면서, 
	// j의 가치를 표현하는 동전의 경우 중 동전의 최소 개수

	// 초기값은? 
	// D[i][j] = min(D[i-1][j], D[i][j-arr[i]])

	for (int i = 0; i < n; i++) {
		D[i][0] = 0;
		if(arr[i] <= 10000)
			D[i][arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		if (i % arr[0] == 0)
			D[0][i] = i / arr[0];
		else
			D[0][i] = INT_MAX;
	}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= arr[i])
				D[i][j] = min(D[i - 1][j], D[i][j - arr[i]] + 1);
			else
				D[i][j] = D[i - 1][j];
		}
	}

	if (D[n - 1][k] == INT_MAX) 
		printf("-1");
	else
		printf("%lld", D[n - 1][k]);
	
	return 0;
}