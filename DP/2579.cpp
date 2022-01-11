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

	// 1. ����� �� ���� 1�� �Ǵ� 2���� ���� �� �ִ�.
	// 2. ���ӵ� 3���� ����� ��� ��Ƽ��� �� �ȴ�.
	// 3. ������ ���� ����� ��ƾ� �Ѵ�.

	// DP + ���� ��� ���� ���
	// D[i] = max(D[i-1], D[i-2]) + ���� ��� ����
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	if (n == 1) {
		printf("%d", stair[1]);
		return 0;
	}

	// ��ĭ ���� �Ұ��� (i-1���� ĭ���� ��ĭ �����ؼ� ����) 
	D1[1] = stair[1]; D1[2] = stair[1] + stair[2];
	// ���� (i-2��° ĭ���� 2ĭ �����ؼ� ����)
	D2[1] = 0; D2[2] = stair[2];

	for (int i = 3; i <= n; i++) {
		D1[i] = D2[i - 1] + stair[i];
		D2[i] = max(D1[i - 2], D2[i-2]) + stair[i];
	}

	printf("%d", max(D1[n], D2[n]));


	return 0;
}