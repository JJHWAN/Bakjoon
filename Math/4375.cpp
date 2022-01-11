#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector <int> v;

void solve(int k) {

	int mod = 1 % k, len = 1;
	int n1 = 1, n2;

	while (mod != 0) {
		n2 = (n1 * 10) % k;
		mod = (n2 + mod) % k;
		len++;
		n1 = n2;
	}

	printf("%d\n", len);
}

int main(void){

	int a;
	
	while (~scanf("%d", &a)) {
		solve(a);
	}

	return 0;
}