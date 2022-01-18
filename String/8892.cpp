#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int t, n;

void solve(vector<string> v) {

	int len, i, j, k;
	string tmp, tmp2;

	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			// v[i] 와 v[j]를 비교
			tmp = v[i]; tmp2 = v[j];
			tmp += v[j]; tmp2 += v[i];
			len = tmp.size();

			for (k = 0; k < len / 2; k++) {
				if (tmp[k] != tmp[len - 1 - k]) {
					break;
				}
			}
			if (k == len / 2) {
				cout <<tmp <<"\n";
				return;
			}

			for (k = 0; k < len / 2; k++) {
				if (tmp2[k] != tmp2[len - 1 - k]) {
					break;
				}
			}
			if (k == len / 2) {
				cout << tmp2 <<"\n";
				return;
			}

		}
	}
	printf("0\n");
}

int main(void) {

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		vector<string> v;
		scanf("%d", &n);
		getchar();
		for (int j = 0; j < n; j++) {
			string s;
			getline(cin, s);
			//getchar();
			v.push_back(s);
		}
		solve(v);
	}

	return 0;
}