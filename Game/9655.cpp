#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;
using ll = long long;

// 백준 9655번 돌 게임 문제
// 각자의 턴에 1개 또는 3개의 돌을 가져갈 수 있고,
// 마지막 으로 돌을 가져가는 사람이 승리한다.

// 1 or 3 => 항상 총 소비한 돌의 개수가 (홀, 짝, 홀, 짝, ...) 를 반복한다.
// 처음 돌의 개수가 홀수개면 처음 가져간 사람이 승리한다.
// 처음 돌의 개수가 짝수개면 늦게 가져간 사람이 승리한다.

int main(void) {

	int n;
	
	scanf("%d", &n);

	if (n % 2 == 1) {
		printf("SK");
	}
	else {
		printf("CY");
	}

	return 0;
}