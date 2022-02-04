#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int cnt[1010] = {0, };
// 백준 10986번 나머지 합 문제
// N개의 수가 주어지고, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수

// 연속된 부분 구간을 다루는 가장 잘 알려져 있는 방법은 prefix sum을 이용하는 것이다.
// 구간 [i, j]를 볼 때는 pre[j]와 pre[i-1]을 살펴봄으로써 구간에 대한 정보를 얻는다.
// 여기서 pre[x]는 앞에서부터 x까지의 부분 구간의 정보이다.

// 여기서 우리가 알 필요가 있는 정보는 정확한 구간의 합이 아닌
// 부분 구간의 합의 "나머지"이다. 
// 추가 배열을 만들어서, 0~i번째 원소까지의 합의 나머지가 0 ~ m-1 사이에 존재하므로,
// cnt[원소 합의 나머지] 를 증가시키고, 이를 고려하여 cnt를 증가시키면 된다.

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a;
    ll presum = 0, ans = 0;

    cin >> n >> m;
    // 입력으로 m의 배수가 들어오는 경우
    cnt[0]++;

    for(int i=0;i<n;i++){
        cin >> a;
        presum += a;
        presum %= m;
        // 지금까지 presum의 나머지가 나온 구간 합들을 빼면 개수 증가 가능
        ans += cnt[presum];
        // presum 하나 추가
        cnt[presum]++;
    }

    cout << ans;
    return 0;
}