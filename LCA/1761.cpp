#include <iostream>
#include <vector>
#include <utility>

#define N_ 40001
using namespace std;
using ll = long long;

int n, a, b, cost;

int par[N_][21], sum[N_][21], m, d[N_];
vector <pair<int, int>> v[N_];

void dfs(int x, int parent) {
    // d[a] : a 정점의 depth 저장

    d[x] = d[parent] + 1;
    for (pair<int, int> next : v[x]) {
        if (next.first == parent) continue;
        par[next.first][0] = x;
        sum[next.first][0] = next.second;
        dfs(next.first, x);
    }
}


int lca(int x, int y) {
    // 항상 y의 depth가 더 깊거나 같도록 만들어주자.
    int sumx = 0, sumy = 0;
    if (d[x] > d[y]) swap(x, y);

    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            sumy += sum[y][i];
            y = par[y][i];
        }
    }
    if (x == y) return sumy;

    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            sumx += sum[x][i];
            sumy += sum[y][i];
            x = par[x][i];
            y = par[y][i];
        }
    }
    
    sumx += sum[x][0];
    sumy += sum[y][0];

    return sumx + sumy;
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> cost;
        v[a].push_back({ b, cost });
        v[b].push_back({ a, cost });
    }
    
    d[0] = 0;
    dfs(1, 0);

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
            sum[j][i] = sum[j][i-1] + sum[par[j][i - 1]][i - 1];
        }
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout <<  lca(a, b) << "\n";
    }

    return 0;
}