#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 20001

using namespace std;
using ll = long long;

// 백준 2370 시장 선거 포스터
// 좌표 압축을 이용하는 문제

int n, cnt = 0, k = 0;
vector <int> xlist;
vector <pair<int, int>> v;

// 주어지는 좌표의 범위가 최대 1억이기 때문에, 1:1 대응은 메모리 초과 
// 실제 간격이 중요하지 않고, 상대적인 크기만 중요하다.

// 좌표 압축을 이용해서 각 포스터의 l,r 을 상대적인 순서로 대응시켜 보자.
// 입력이 (1, 4) (2, 6) (8, 10) (3, 4) (7, 10) 으로 들어온다고 하면?
// (0, 3) (1, 4) (6, 7) (2, 3) (5, 7)

void solve() {
    int arr[MAX] = { 0, }, check[MAX + 1] = { 0, };

    for (int i = 0; i < n; i++) {
        int l = v[i].first, r = v[i].second;
        for (int j = l; j <= r; j++) {
            arr[j] = i+1;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (!arr[i]) continue;
        if (check[arr[i]]) continue;
        else {
            check[arr[i]] = 1;
            cnt++;
        }
    }

}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        xlist.push_back(a);
        xlist.push_back(b);
        v.push_back({ a, b });
    }

    sort(xlist.begin(), xlist.end());
    xlist.erase(unique(xlist.begin(), xlist.end()), xlist.end());

    for (int i = 0; i < n; i++) {
        v[i].first = lower_bound(xlist.begin(), xlist.end(), v[i].first) - xlist.begin();
        v[i].second = lower_bound(xlist.begin(), xlist.end(), v[i].second) - xlist.begin();
    }

    k = xlist.back();

    solve();

    cout << cnt;

    return 0;
}