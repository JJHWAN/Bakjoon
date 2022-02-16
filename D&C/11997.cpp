#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;

int n, max_x, max_y;
vector <pair<int, int>> v;
vector <int> xlist1, xlist2;

int psum[1010][1010] = { 0, }, arr[1010][1010] = { 0, };

int get_max(int a, int b) {
    int s1, s2, s3, s4;
    s1 = psum[max_x-1][max_y-1] - psum[a][max_y-1]  - psum[max_x-1][b] + psum[a][b];
    s2 = psum[a][max_y-1] - psum[a][b];
    s3 = psum[a][b];
    s4 = psum[max_x-1][b] - psum[a][b];

    return max(max(s1, s2), max(s3, s4));
}

void solve() {

    int i, j;
    max_x = xlist1.size(), max_y = xlist2.size();

    for (i = 0; i < n; i++) {
        arr[v[i].first][v[i].second] = 1;
    }

    psum[0][0] = arr[0][0];
    for (i = 0; i < max_x-1; i++) {
        psum[i + 1][0] = psum[i][0] + arr[i + 1][0];
    }

    for (i = 0; i < max_y-1; i++) {
        psum[0][i + 1] = psum[0][i] + arr[0][i + 1];
    }

    for (i = 0; i < max_x-1; i++) {
        for (j = 0; j < max_y-1; j++) {
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + arr[i+1][j+1];
        }
    }

    int result = 1010;
    for (i = 0; i <= max_x; i++) {
        for (j = 0; j <= max_y; j++) {
            result = min(result, get_max(i, j));
        }
    }
    cout << result;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
        xlist1.push_back(a);
        xlist2.push_back(b);
    }

    sort(xlist1.begin(), xlist1.end());
    sort(xlist2.begin(), xlist2.end());

    xlist1.erase(unique(xlist1.begin(), xlist1.end()), xlist1.end());
    xlist2.erase(unique(xlist2.begin(), xlist2.end()), xlist2.end());

    for (int i = 0; i < n; i++) {
        v[i].first = lower_bound(xlist1.begin(), xlist1.end(), v[i].first) - xlist1.begin();
        v[i].second = lower_bound(xlist2.begin(), xlist2.end(), v[i].second) - xlist2.begin();
    }

 
    solve();

    return 0;
}