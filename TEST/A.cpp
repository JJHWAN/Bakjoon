#include <iostream>

using namespace std;
using ll = long long;

// 수열의 모든 원소는 서로 다르고, 원소는 1 이상 100,000 이하의 정수다.
// 수열의 연속한 부분 수열 중에, 길이가 k인 모든 연속한 부분 수열의 합은 k로 나누어 떨어진다.

// (an + an-1 + .. an-k) % k = 0
// k for 1 to n

int n, t, a, b, k;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[5001];

    cin >> n;

    if (n % 2) {
        // 홀수
        arr[n / 2 + 1] = 2*n;
        for (int i = 1; i <= n / 2; i++) {
            arr[n / 2 + 1 - i] = 2*(n - i);
            arr[n / 2 + 1 + i] = 2*(n + i);
        }
    }
    else {
        // 짝수
        for (int i = 1; i <= n; i++) {
            arr[i] = 2 * i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}