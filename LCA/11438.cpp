#include <iostream>
#include <vector>

#define N_ 100001
using namespace std;
using ll = long long;

int par[N_][21], n, m, d[N_];
vector <int> v[N_];


void dfs(int x, int parent) {
    // d[a] : a 정점의 depth 저장

    d[x] = d[parent] + 1;
    for (int next : v[x]) {
        if (next == parent) continue;
        par[next][0] = x;
        dfs(next, x);
    }
}

int lca(int x, int y) {
    // 항상 y의 depth가 더 깊거나 같도록 만들어주자.
    if (d[x] > d[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            y = par[y][i];
        }
    }
    if (x == y) return x;

    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    d[0] = 0;
    dfs(1, 0);

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}