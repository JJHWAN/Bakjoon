#include <iostream>

using namespace std;
using ll = long long;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // 분해합 : 어떤 자연수 + 어떤 자연수의 각 자리수의 합
    // 245의 분해합 : 245 + 2 + 4 + 5
    // 256의 생성자 => 245

    int n, dec_cnt = 0;
    cin >> n;

    // N이 주어지면, N의 가장 작은 생성자를 구해라..?
    // 1. N <= 1,000,000 이므로,
    // O(nlogn) 이면 충분
    // 한번 순회하면서 검색하기?

    // 2. 수학적으로 구하는게 가능할까?
    // 백만이라고 해봤자 10^6
    // 각 자리수는 최대 7개
    // 빠르게 자리수를 세고 
    // 생성자 <= 분해합 <= 생성자 + (자리수)*10

    int tmp = n;
    while (tmp) {
        tmp /= 10;
        dec_cnt++;
    }
    tmp = 0;

    for (int i = n; i >= n - 10 * dec_cnt && i > 0; i--) {
        int sum = i, k = i;
        while (k) {
            sum += k % 10;
            k /= 10;
        }
        if (sum == n) {
            tmp = i;
        }
    }

    cout << tmp;

    return 0;
}