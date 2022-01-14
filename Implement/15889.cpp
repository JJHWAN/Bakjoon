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

	// ��������
	if (x >= n) return;

	// x��° ���� Ȯ��
	if (checked[x] == 1) {
		return;
	}
	if (x == n - 1) {
		printf("�Ǻ����, �ߴ������ ã���ʴϴ�");
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
		printf("�Ǻ����, �ߴ������ ã���ʴϴ�");
		return 0;
	}
	
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &B[i]);
	}
	
	// ������ �нż� �ʿ�?

	func(0);
	printf("���� �� ���� �ʾ��� �� ����");

	return 0;
}
