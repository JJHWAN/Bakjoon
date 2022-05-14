#include <iostream>

using namespace std;
using ll = long long;

ll n, m;

ll gcd(ll n, ll m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // n > m 이라고 하고, 모든 자리가 1로만 이루어져있는 n 자리의 자연수 N, m 자리의 자연수를 M이라 하자.
    // N = 10^n +10^(n-1) + ... + 1
    // M = 10^m + 10^(m-1) + ... + 1
    // n - km >= 0 를 만족하는 자연수 k에 대해서 모두 M의 10^(n-km) 배로 배수로 처리 가능
    // 나머지는? 10^(n%m) + ...  = 1
    
    // n = km으로 나눠지는 순간 최대 공약수 발견
    
    if (m > n) {
        ll tmp = n;
        n = m;
        m = tmp;
    }

    ll result = gcd(n, m);

    for (int i = 0; i < result; i++) {
        cout << "1";
    }

    return 0;
}