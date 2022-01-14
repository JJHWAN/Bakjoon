#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
char b[1010][1010];

int main(void) {

	char a[1010];

	fgets(a, 1010, stdin);

	int len = strlen(a);

	char tmp[1001];

	for (int i = 0; i < len - 1; i++) {
		strcpy(b[i], a + i);
		b[i][strlen(b[i]) - 1] = '\0';
	}
	

	for (int i = 1; i < len-1; i++) {
		for (int j = 0; j < i; j++) {
			if (strcmp(b[i], b[j]) < 0) {
				strcpy(tmp, b[i]);
				strcpy(b[i], b[j]);
				strcpy(b[j], tmp);
			}
		}
	}
	for (int i = 0; i < len - 1; i++) {
		printf("%s", b[i]);
		if (i == len - 2) break;
		printf("\n");
	}
	

	return 0;
}