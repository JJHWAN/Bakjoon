#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int A[30001], B[30001];
int checked[30001] = { 0, };

void func(int x) {

	// 종료조건
	if (x >= n) return;

	// x번째 전우 확인
	if (checked[x] == 1) {
		return;
	}
	if (x == n - 1) {
		printf("권병장님, 중대장님이 찾으십니다");
		exit(0);
	}
	for (int i = x+1; A[i] <= A[x] + B[x]; i++) {
		func(i);
		checked[x] = 1;
	}

}

int main(void) {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	if (n == 1) {
		printf("권병장님, 중대장님이 찾으십니다");
		return 0;
	}
	
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &B[i]);
	}
	
	// 수류탼 분신술 필요?

	func(0);
	printf("엄마 나 전역 늦어질 것 같아");

	return 0;
}
