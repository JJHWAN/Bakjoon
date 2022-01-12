#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int arr[100000][2];

int main(void) {

	int n, t;
	scanf("%d", &t);

	while (t-- > 0) {
		int** ans;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i][0]);

		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i][1]);

		ans = (int**)malloc(sizeof(int*) * 3);
		for (int i = 0; i < 3; i++)
			ans[i] = (int*)malloc(sizeof(int) * n);
		// DP로 해결 가능?
		// ans[0][i]는 i번째 열에서 위에 있는 스티커를 선택 했을때 최대값
		// ans[1][i]는 i번째 열에서 아래 있는 스티커를 선택 했을때 최대값
		// ans[2][i]는 i번째 열에서 스티커를 선택하지 않은 최대값
		ans[0][0] = arr[0][0];
		ans[1][0] = arr[0][1];
		ans[2][0] = 0;

		for (int i = 1; i < n; i++) {
			ans[0][i] = max(ans[1][i - 1], ans[2][i - 1]) + arr[i][0];
			ans[1][i] = max(ans[0][i - 1], ans[2][i - 1]) + arr[i][1];
			ans[2][i] = max(ans[0][i - 1], ans[1][i - 1]);
		}

		printf("%d\n", max(ans[0][n - 1], max(ans[1][n - 1], ans[2][n - 1])));

		for (int i = 0; i < 3; i++)
			free(ans[i]);
		free(ans);
	}

	return 0;
}