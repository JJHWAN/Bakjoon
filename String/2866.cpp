#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
using std::vector;

char arr[1001][1001];
vector <int> v[26];

int max_cnt = 0, r, c;

void cmp(int idx1, int idx2, int start, int end) {
	
	int result = 0;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (!strcmp(&arr[idx1][mid], &arr[idx2][mid])) {
			// 일치하는 경우?
			// start를 더 전진시켜서 확인?
			result = mid - 1;
			end = mid - 1;
		}
		else {
			// 불일치
			// 현재까지 구한 최대와 앞으로 구할 수 있는 가능성을 비교
			start = mid + 1;
		}
	}
	if (max_cnt)
		max_cnt = min(max_cnt, result);
	else
		max_cnt = result;
}

int main(void) {

	int cnt = 0;
	int i, j;
	scanf("%d %d", &r, &c);
	getchar();

	// (j, i)의 형태로 입력
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%c", &arr[j][i]);
		}
		getchar();
	}

	int idx;
	// hash table 적용
	for (i = 0; i < c; i++) {
		idx = arr[i][r-1] - 'a';
		v[idx].push_back(i);
	}

	for (j = 0; j < 26; j++) {
		if (v[j].size() > 1) break;
	}
	if (j == 26) {
		// 중복 하나도 없는 경우,
		printf("%d", r - 1); return 0;
	}

	// 이분 탐색으로 접근 가능?
	// 어떤한 지점 n부터 중복이면
	// 그보다 아래 부분은 당연히 모두 중복이다.

	int cur_idx, cmp_idx;
	
	for (j = 0; j < 26; j++) {
		for (int k = 0; k < v[j].size(); k++) {
			cur_idx = v[j][k];
			for (int x = k + 1; x < v[j].size(); x++) {
				cmp_idx = v[j][x];
				cmp(cur_idx, cmp_idx, 0, r-1);
			}
		}
	}

	printf("%d", max_cnt);

	return 0;
}