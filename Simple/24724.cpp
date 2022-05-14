#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int T, n, k = 1;

void solve() {

    int a, b, i, x, y;
    vector<pair<int, int>> v;
    cin >> n;
    cin >> a >> b;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    cout << "Material Management " << k << "\n";
    k++;
    cout << "Classification ---- End!\n";
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int i;

    cin >> T;
    for (i = 0; i < T; i++) {
        solve();
    }

    return 0;
}