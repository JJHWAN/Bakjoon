#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

#define inf 1e12

// 신촌 알고리즘 캠프 중급 5주차 필수문제

// 주변 가게에서 bag of chips를 구매, 가게에는 n가지의 맛 존재
// i-th 맛의 cost of a bag => ai 로 주어진다.

// 가게의 과자들은 바닥날수도 있기에, 도착해서 구매를 결정
// 2가지 결정적인 규칙이 존재한다.

// 1. You habve only coins of 1, 2 and 3 burles.
// => 1, 2, 3원 단위의 화폐만 가지고 있음
// 2. since it's morning, the store will ask you to pay in exact change.
// => 아침이라 잔돈이 없어서, 정확한 액수를 지불해야함.

// 동전들은 무겁기 때문에, 가능한 적은 수의 동전을 들고 가고 싶다.
// what is the minimum total number of coins you should take with you, 
// so you can buy a bag of chips of any flavor in exact change?

// 어떤 맛이든 구매할 수 있으려면, 최소 몇개의 동전이 필요하겠는가?


// 입력
// 첫번째 줄에는 테스트 케이스의 개수
// 그 뒤로는 각 테스트 케이스가 들어오는데
// 각 테케마다 첫번째 줄에는 맛의 개수
// 두번째 줄에는 각 맛의 비용이 들어온다.

// 최소 개수를 어떻게 구할까?

// 1. 3의 개수으로 먼저 다 자르고 나머지를 구하는 방식으로 접근하는게 효율적
// 2. 작은 수 부터 하나하나 구하는데 => 이전의 수를 가능한 활용해서 접근 (DP적으로 접근)

// 문제는 만약 3k +1, 3a + 2 꼴의 수가 들어온 경우,
// 이 1, 2 두 개의 동전으로 3을 만들 수 있다...

// 1, 2를 합쳐서 하나를 만드는 건, 아래에 3k+1, 3a+2의 꼴의 수가 있기 때문에 힘들다.
// 그러나, 1원 짜리 동전 3개, 혹은 2원 짜리 동전 3개는 교환에 부담이 없다.
// => 1의 0~2개, 2가 0~2개인 경우만 고려하면 된다.. (그리디 + Brute Force)

vector <ll> A[3][3];

void solve() {
    // 각 테스트케이스에 대해서 solve
    int n;
    cin >> n;
    vector <ll> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());


    // 최대값을 3으로 나눈 몫
    ll div = v[n - 1] / 3;

    // A[x][y] : 1원 짜리 동전이 x개, 2원 짜리 동전이 y개 있을 때,
    // 낼 수 있는 돈의 모든 종류들을 모아놓은 벡터
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j].clear();
            A[i][j].push_back(0);
        }
    }

    A[1][0].push_back(1);
    
    A[2][0].push_back(1);
    A[2][0].push_back(2);
    
    A[0][1].push_back(2);

    A[0][2].push_back(2);
    A[0][2].push_back(4);

    A[1][1].push_back(1);
    A[1][1].push_back(2);
    A[1][1].push_back(3);

    A[1][2].push_back(1);
    A[1][2].push_back(2);
    A[1][2].push_back(3);
    A[1][2].push_back(4);
    A[1][2].push_back(5);

    A[2][1].push_back(1);
    A[2][1].push_back(2);
    A[2][1].push_back(3);
    A[2][1].push_back(4);

    A[2][2].push_back(1);
    A[2][2].push_back(2);
    A[2][2].push_back(3);
    A[2][2].push_back(4);
    A[2][2].push_back(5);
    A[2][2].push_back(6);

    ll ans = inf, sum, a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a = 0; // ??
            for (int ii = 0; ii < n; ii++) {
                sum = inf;
                for (auto next : A[i][j]) {
                    // 주어진 입력이 A[i][j]의 들어있는 수보다 작다면?
                    // 이미 다른 A[x][y]에 들어가 있을 것 + 어차피 검사 불가
                    if (v[ii] < next) continue;
                    // 딱 떨어지는 수라면 sum과 비교해서 더 작은 동전 수를 개수로 지정
                    if ((v[ii] - next) % 3 == 0)
                        sum = min(sum, (v[ii] - next) / 3); 
                }
                // v 중 최대를 다시 거르는 a
                a = max(a, sum);
            }
            ans = min(ans, a + i + j);
        }
    }
    cout << ans << "\n";
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;



    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}