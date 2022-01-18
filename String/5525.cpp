#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;

int main(void) {

	// 틀리면? 다 뛰어넘고 틀린곳부터 다시 1찾기 시작
	// 성공했으면? 계속 전진하면서 체크
	int cnt = 0, n, len, i = 0, k = 0;
	string s;

	scanf("%d", &n);
	scanf("%d", &len);
	getchar();

	getline(cin, s);

	while (i < len) {
		if (k % 2 == 0) {
			// I가 나올 차례
			if (s[i] == 'I') {
				k++;
				if (k / 2 >= n)
					cnt++;
			}
			else
				k = 0;
		}
		else {
			// O가 나올 차례
			if (s[i] == 'O')
				k++;
			else
			// I가 나온 경우, 처음 원소 'I'는 검사 필요 X
				k = 1;
		}
		i++;
	}

	printf("%d", cnt);

	return 0;
}