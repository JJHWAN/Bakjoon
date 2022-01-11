#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int D1[301], D2[301], stair[301];

int main(void) {

	int n;

	stair[0] = D1[0] = D2[0] = 0;

	// 1. 계단은 한 번에 1개 또는 2개씩 오를 수 있다.
	// 2. 연속된 3개의 계단을 모두 밟아서는 안 된다.
	// 3. 마지막 도착 계단을 밟아야 한다.

	// DP + 연속 계단 개수 고려
	// D[i] = max(D[i-1], D[i-2]) + 현재 계단 점수
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	if (n == 1) {
		printf("%d", stair[1]);
		return 0;
	}

	// 한칸 연속 불가능 (i-1번재 칸에서 한칸 전진해서 도달) 
	D1[1] = stair[1]; D1[2] = stair[1] + stair[2];
	// 가능 (i-2번째 칸에서 2칸 전진해서 도달)
	D2[1] = 0; D2[2] = stair[2];

	for (int i = 3; i <= n; i++) {
		D1[i] = D2[i - 1] + stair[i];
		D2[i] = max(D1[i - 2], D2[i-2]) + stair[i];
	}

	printf("%d", max(D1[n], D2[n]));


	return 0;
}