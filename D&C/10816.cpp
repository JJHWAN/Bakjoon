#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;

vector <int> v, a;

int solve(int start, int end, int k) {
    if (start == end) {
        if (v[start] == k) return 1;
        else return 0;
    }

    if (k < v[start] || v[end] < k) return 0;
    if (v[start] == k && v[end] == k) return (end - start + 1);

    int mid = (start + end) / 2;

    return solve(start, mid, k) + solve(mid + 1, end, k);
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cin >> m;
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cout << solve(0, n - 1, a[i]) << " ";
    }


    return 0;
}