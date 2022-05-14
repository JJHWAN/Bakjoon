#include <iostream>
#include <memory.h>

using namespace std;
using ll = long long;

int arr[1500100][2], dp[1500100][2];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 퇴사전 상담을 통해 얻을 수 있는 최대 이익 구하기
    // DP를 사용하면 편리할듯 

    // i번째 날에 취할 수 있는 행동은 2가지
    
    // i번째 날에 주어진 상담을 하느냐? or 하지 않느냐?
    
    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    memset(dp, 0, sizeof(dp));

    // dp[i] : index일차부터 시작해서 상담을 시작했을 때, 얻을 수 있는 최대 수익
    // dp[i][0] : i번째 날의 상담을 하는 경우
    // dp[i][1] : i번째 날의 상담을 하지 않는 경우,
    for (int i = n-1; i >=0; i--) {
        int time = arr[i][0];
        int price = arr[i][1];
        // i번째 일의 상담을 하는 경우,
        if(i+time <= n)
            dp[i][0] = max(dp[i + time][0], dp[i + time][1]) + price;
        // 하지 않는 경우,
        dp[i][1] = max(dp[i + 1][1], dp[i + 1][0]);
    }

    cout << max(dp[0][0], dp[0][1]);

    return 0;
}