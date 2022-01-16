#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>

using namespace std;
using ll = long long;

string S, pattern;
vector <int> failure;

void fail(string pat) {
	int i, j;
	int n = pat.size();
	failure.push_back(-1);
	for (j = 1; j < n; j++) {
		i = failure[j - 1]; // 지금까지 구해놓은 failure 배열의 정보를 이용
		while ((pat[j] != pat[i + 1]) && (i >= 0)) {
			// 현재 j번째 패턴의 문자와 i+1 번째 문자를 비교해서
			// 다른 경우, 이전에 구해 놓은 failure vector를 통해서 
			// 다음 검사할 문자로 이동한다.
			i = failure[i];
		}
		if (pat[j] == pat[i + 1]) {
			failure.push_back(i + 1);
			//failure[j] = i + 1;
			// j번째 문자 검사하다가 틀리면 i+1 번째 원소로 이동
		}
		else failure.push_back(-1);
	}
}

int main(void) {

	ll k = 1;

	int i = 0, j = 0, n, m;
	getline(cin, S);
	getline(cin, pattern);

	n = S.size();
	m = pattern.size();
	if (n < m) {
		printf("0"); return 0;
	}

	fail(pattern);

	while (i < n && j < m) {
		if (S[i] == pattern[j]) {
			i++; j++;
		}
		else if (j == 0) {
			i++;
		}
		else {
			// 패턴의 failure 정보를 이용해서
			// 중간 지점 부터 검사
			j = failure[j - 1] + 1;
		}
	}
	if (j == m) printf("1");
	else printf("0");

	return 0;
}