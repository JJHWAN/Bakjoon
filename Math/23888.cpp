#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;

typedef struct query {
	int a;
	int l;
	int r;
};

ll a, d;
int q, i, y;

vector <query> command;

ll gcd(ll a, ll b);
ll func1(ll l, ll r);
ll func2(int l, int r);

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll func1(ll l, ll r) {

	ll sum1, sum2;
	// a, a+d, a+2d ... a+ (n-1)d
	// n*a + (n-1)*n*d/2 -> n(a+(n-1)*d/2)
	sum1 = (l-1) * a + (l-1) * (l - 2) * d / 2;
	sum2 = r * a + r * (r - 1) * d / 2;

	return (sum2 - sum1);
}

ll func2(int l, int r) {
	// Al ~ Ar 의 최대 공약수 반환
	if (l == r) return (a + (l - 1)* d);
	// 1. gcd(a, a+d) = gcd(a, d) = K  
	// 2. gcd(a+xd, a+(x+1)d) = gcd(d, a+xd) = gcd(d, a) = K 
	// 3. gcd(a, b, c) = gcd(gcd(a,b), c)
	return y;
}


int main(void) {

	scanf("%lld %lld", &a, &d);
	scanf("%d", &q);
	y = gcd(a, d);
	int x1, x2, x3;
	query tmp;
	for (i = 0; i < q; i++) {
		scanf("%d %d %d", &x1, &x2, &x3);
		tmp.a = x1; tmp.l = x2; tmp.r = x3;
		command.push_back(tmp);
	}

	for (i = 0; i < q; i++) {
		tmp = command[i];
		if (tmp.a == 1) {
			printf("%lld\n", func1(tmp.l, tmp.r));
		}
		else {
			printf("%lld\n", func2(tmp.l, tmp.r));
		}
	}

	return 0;
}
