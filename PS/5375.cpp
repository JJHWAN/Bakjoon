#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

#define inf 1e16;

typedef struct X{
    ll price, num, fee;
};

int cmp(X a, X b){
    return a.price < b.price ? 1 : 0;
}

// 백준 5375번 공책 구매
void solve(int n, int m){
    // n은 구매하고자 하는 공책의 수
    // m은 쇼핑몰의 개수
    // 배송비는 한번만 내면 된다..
    // 특정 쇼핑몰에 대해서 이미 냈는지 안 냈는지?

    // si는 i번째 쇼핑몰에서 구매 가능한 개수
    // pi는 하나당 가격
    // oi는 배송비

    // Greedy한 성질을 적용하면 문제를 해결 가능하다.
    // 최적해 공책 집합 S가 있다고 하면, 
    // S 내부에 A 쇼핑몰의 공책이포함되어 있다면
    // 그 공책은 항상 공책의 최대 개수 si만큼 포함되어 있거나,
    // S의 원소중 pi가 가장 큰 원소이다. 
    
    // 최적해에서는 선택된 쇼핑몰의 경우, 모두 배송비를 지불했을테니,
    // 그 배송비는 생각에서 제외하고, 한개당 가격만 생각하면 된다...?

    ll dp[10001];
    dp[0] = 0;
    ll ans = inf;

    for(int i=1;i<=n;i++) dp[i] = inf;


    int price, num, fee;

    vector <X> v(m);

    for(int i=0;i<m;i++){
        cin >> v[i].num >> v[i].price >> v[i].fee;
    }

    sort(v.begin(), v.end(), cmp);

    
    for(int i=0;i<m;i++){
        price = v[i].price, num = v[i].num, fee = v[i].fee;
        for(int j=n;j>=0;j--){
            if(j + num >= n){
                // 가장 큰 원소라서 다 안 담기는 경우
                ans = min(ans, dp[j] + (n-j)*price + fee);
            }
            if(j >= num){
                // 공책 개수 >> 현재 쇼핑몰에서 살 수 있는 공책 개수
                // dp 내역 업데이트해서, 이 쇼핑몰 선택 or 선택 안 함 결정
                dp[j] = min(dp[j], dp[j-num] + price*num + fee);
            }
        }
    }
   cout << ans <<"\n";
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}