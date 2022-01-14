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

	// D[i] = 3*i의 크기의 벽을 1*2, 2*1 크기의 타일로 채우는 경우의 수
	// D[i-1] -> D[i] : 는 불가능
	// D[i-2] -> D[i] : 는 3*2 크기의 블록을 붙인다고 생각하니 Ok.
	// D[i-4] -> D[i] : 는 3*4 크기의 블록 붙이기 -> 이 중 D[i-2]에 포함되지 않는 경우는?
	// D[4] - (D[2] *D[2]) -> 2개 블록으로 나눠지는 경우 배제
	// D[i-6] -> D[i] : 는 3*6 크기의 블록을 붙이기 -> 분리 불가 블록만 추가 가능

	// 생각해보면 3*(2k) 꼴의 블록 중에서 더 작은 꼴로 분리하지 못하는 블록은
	// 1행과 2,3행이 한칸씩 어긋나서 전진하거나,
	// 3행과 1,2행이 한칸씩 어긋나서 전진하다가, 양쪽에 (2*1) 형태의 세로 블록을 만나는 경우 밖에 없다
	// 이 경우는 항상 2가지씩 존재하기 때문에 아래식을 유츄할 수 있다.
	for (int i = 4; i <= 30; i+=2) {
		D[i] += D[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			D[i] += D[i - j] * 2;
		}
	}

	printf("%d", D[n]);

	return 0;
}