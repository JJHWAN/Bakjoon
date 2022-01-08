#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
using ll = long long;

ll n, a;

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}

// ax+by=1의 값을 x,y에 저장해준다. gcd(a,b)을 return 해준다.
ll ex_gcd(ll a, ll b, ll& x, ll& y) {

	if (!b) {
		x = 1, y = 0;
		return a;
	}

	ll ret = ex_gcd(b, a % b, x, y);
	ll temp = y;
	y = x - (a / b) * y;
	x = temp;
	
	if (x <= 0) {
		x += b;
		y -= a;
	}
	return ret;
}


int main(void) {


	ll b, c, x, y;

	scanf("%lld %lld", &n, &a);

	b = n - a;

	// (a*c) mod n = 1 => ax + 1 = ny => ax -ny = 1;
	// a mod n = k 라고 했을때, (a*c) mod n = ck mod n = q;
	if (gcd(n, a) != 1) x = -1;
	else ex_gcd(a, n, x, y);
	printf("%lld %lld", b, x);

	return 0;
}