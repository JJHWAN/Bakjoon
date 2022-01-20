#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>


using namespace std;

int D[31] = {0, };

int main(void) {

	int n;
	scanf("%d", &n);

	D[0] = 1;
	D[1] = 0;
	D[2] = 3;

	// 3*N 크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수를 구해보자

	// D[2] = 3 (2*3의 벽을 채우는 경우는 3개)
	// D[4] = D[2] * D[2] + (2*3으로 나뉘지 않는 4*3 크기의 벽 (2개))
	// D[i] = D [i-2] * 3 + (D[i - 2k] * 2) <k = 1 ~ 2k <= i>; 
	
	for (int i = 4; i <= 30; i+=2) {
		D[i] += D[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			D[i] += D[i - j] * 2;
		}
	}

	printf("%d", D[n]);

	return 0;
}