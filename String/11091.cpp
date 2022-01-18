#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int a[26] = {0, };

int check(string s) {
	
	int cnt = 0;
	memset(a, 0, sizeof(a));

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (j + 'a' == s[i] || j + 'A' == s[i]) {
				if (!a[j]) {
					a[j] = 1; cnt++;
				}
				break;
			}
		}
	}
	return (26 - cnt);
}


int main(void) {

	int n;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (!check(s))
			printf("pangram\n");
		else {
			printf("missing ");
			for (int j = 0; j < 26; j++) {
				if (!a[j])
					printf("%c", 'a' + j);
			}
			printf("\n");
		}
	}

	return 0;
}