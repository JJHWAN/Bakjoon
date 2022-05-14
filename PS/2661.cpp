#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 좋은 수열, 나쁜 수열
// 나쁜 수열 => 임의의 길이의 인접한 두 개의 부분 수열이 동일
// ex) 1212 => 12 12

// 숫자 1, 2, 3으로만 이루어지는 수열
// 어떤 수 N이 들어오면 
// 해당 자리 수의 정수 중에 가장 작은 좋은 수열을 나타내는 정수를 출력

// 1 <= N <= 80
// 경우의 수를 먼저 나누면
// 상태를 나타내기 위한 필요한 거 
// 1. 임의의 수열의 길이
// 2. 임의의 수열의 시작주소

// 모든 경우를 카운트하려면 3^80
// 시간 초과
// x x x a b c a b c y y y

int n;

bool check(int idx, vector<int> v) {

    int i, j;

    for (i = 0; i < (idx + 1) / 2; i++) {
        for (j = 0; j <= i; j++) {
            if (v[idx-i + j] != v[idx - 1 - 2 * i + j]) 
                break;
        }
        if (j > i) return false;
    }

    return true;
}

void solve(int idx, vector<int> v) {

    if (idx == n) {
        for (int i = 0; i < n; i++) {
            cout << v[i];
        }
        exit(0);
    }

    v[idx] = 1;
    if (check(idx, v))
        solve(idx + 1, v);
    v[idx] = 2;
    if (check(idx, v))
        solve(idx + 1, v);
    v[idx] = 3;
    if (check(idx, v))
        solve(idx + 1, v);

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    vector <int> v(n);

    solve(0, v);
    return 0;
}