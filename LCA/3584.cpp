#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
using ll = long long;

#define N_ 10001

int n, a, b;

vector <int> v[N_], for_node[N_];
int d[N_], par[N_][15];

void dfs(int x, int parent) {

    d[x] = d[parent] + 1;

    for (int next : v[x]) {
        // if (next == parent) continue;
        par[next][0] = x;
        dfs(next, x);
    }
}

int lca(int x, int y) {

    if (d[x] > d[y]) swap(x, y);

    for (int i = 14; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i)) {
            y = par[y][i];
        }
    }

    if (x == y) return x;

    for (int i = 14; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

void solve() {

    cin >> n;

    int i;

    for (i = 0; i < N_; i++) {
        v[i].clear();
        for_node[i].clear();
    }

    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        for_node[b].push_back(a);
    }

    memset(d, 0, sizeof(int) * N_);
    memset(par, 0, sizeof(int) * N_ * 15);
    
    for (i = 1; i <= n;i++) {
        if (for_node[i].empty()) break;
    }

    d[0] = 0;
    dfs(i, 0);

    for (i = 1; i < 15; i++) {
        for (int j = 1; j <= n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

    cin >> a >> b;
    cout << lca(a, b) << "\n";
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}