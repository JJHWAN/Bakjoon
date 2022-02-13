#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

// 백준 12920 평범한 배낭 2

// Knapsack 문제
// 물건의 개수, 만족도, 무게가 주어진다.

// 물건의 종류의 개수 <= 100
// 배낭의 최대 무게 <= 10,000, 개수의 최대값 <= 10,000

// DP[x] : 무게가 x일 때, 얻을 수 있는 최대 만족도라고 하고,
// 그냥 DP를 이용하면, 시간 복잡도가 O(NMK)가 나와서 시간 초과

// 가장 핵심적인 아이디어는 K개의 물건을 logK개의 물건으로 
// 정확히 동치조건으로 만들어서 시간 복잡도를 줄이는 것이다. => ???

// 1. K개 물건이 준비되어 있다.
// 2. 1, 2, 4, ... , 2^m 그리고 K+1 - 2^(m+1)  크기의 패키지 물건이 준비되어 있다.
// (같은 물건들을 개수마다 엮어서 새로운 물건으로 취급한다? => 그러면 logK개의 물건 추가로 그냥 DP를 사용 가능)


vector <pair<ll, ll>> a;
ll dp[2000][10101] = {0, };

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    a.push_back({0,0});
    
    ll v, c, k;
     for(int i=0;i<n;i++){
        ll tmp = 1, sum = 0;
        cin >> v >> c >> k;
        while(sum + tmp <= k){
            a.push_back({v*tmp, c*tmp});
            sum += tmp;
            tmp *= 2;
        }
        if(k - sum > 0){
            a.push_back({v * (k - sum), c * (k - sum)});
        }
    }

    int h = a.size();
    for(int i=1;i<h;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j >= a[i].first){
                dp[i][j] = max(dp[i][j], dp[i-1][j - a[i].first] + a[i].second);
            }
        }
    }
    v = 0;
    for(int i=0;i<=m;i++){
        v = max(v, dp[h-1][i]);
    }
    cout << v;

    return 0;
}