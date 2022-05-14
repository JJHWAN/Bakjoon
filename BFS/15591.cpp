#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define MAX_N 5001
using namespace std;
using ll = long long;

// 백준 15591번
// 다익스트라가 아니라 한 점으로부터 다른 점들에 대한 BFS를 이용한 순회 탐색에 가깝다.
int n, q;

vector <pair<int, int>> V[5001];

void BFS(int v, int k) {

    // visited 배열 필요
    // 큐를 만들어서 해결

    int visited[5001] = {0, };
    // 큐에는 해당 정점 index와 정점까지의 최소 유사도 저장
    queue <int> Q;
    Q.push(v); visited[v] = 1;

    int cur_v, cnt = 0;

    while (!Q.empty()) {
        cur_v = Q.front();
        Q.pop();
        // 해당 원소의 접점들을 검사
        for (int i = 0; i < V[cur_v].size(); i++) {
            int next = V[cur_v][i].first;
            if (visited[next]) continue;
            int val = V[cur_v][i].second;
                // path[cur_v][i]가 존재한다면
                // 최소값을 업데이트 하고, visited 값 역시 업데이트
                if (val >= k) {
                    visited[next] = 1;
                    cnt++;
                    // 해당 정점을 다시 큐에 삽입
                    Q.push(next);
                }
         
        }
    }
    cout << cnt << "\n";
}

void solve() {
    
    ll k, v, cnt = 0;
    cin >> k >> v;

    // 동영상 v를 보고 이쓴 소들에게 유사도 K 이상의 동영상 개수를 검사
    BFS(v, k);
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    ll a, b, c;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        V[a].push_back({ b, c });
        V[b].push_back({ a, c });
    }

    for (int i = 0; i < q; i++)
        solve();

    return 0;
}