#include <iostream>

#define N_ 1001

using namespace std;
using ll = long long;

int n, arr[N_], dp[N_][2];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // DP[i]를 어떻게 구할까? = i번째 상자까지 봤을때 한번에 넣을 수 있는 최대의 상자 개수
    // i번째 상자를 활용 or 활용하지 않음
    // 이렇게 2가지 경우로 나눌 수 있음
    // 1. 활용하는 경우, 앞에 원소를 순회하면서 i번째 원소보다 작은 원소 검색
    // 2. 활용하지 않는 경우, max(i-1번째 활용, i-1번째 활용X)

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 초기값 설정
    dp[0][0] = 1; // 첫번째 상자 사용
    dp[0][1] = 0; // 첫번째 상자 사용X

    for (int i = 1; i < n; i++) {
        // i번째 상자를 활용하지 않는 경우,
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        
        dp[i][0] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
            }
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]);

    return 0;
}