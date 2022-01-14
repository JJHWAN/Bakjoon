#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector <int> v;
int main(void) {

	int n, tmp, i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	i = n-1;
	while (i>=2) {
		if (v[i] < v[i - 1] + v[i - 2]) {
			printf("%d", v[i] + v[i - 1] + v[i - 2]);
			return 0;
		}
		i--;
	}

	printf("-1");

	return 0;
}