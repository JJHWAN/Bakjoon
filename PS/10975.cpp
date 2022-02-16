#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int n, arr[100], cnt = 0, check[100] = { 0, };
vector <int> v;

void solve(int idx) {

    int flag = 0;

    check[idx] = 1;
    // 앞 뒤 중 하나만 check 되어 있어도 ok
    if (idx > 0 && check[idx - 1]) {
        flag = 1;
    }
    if (idx < n - 1 && check[idx + 1]) {
        flag = 1;
    }

    if (!flag) cnt++;
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; i++)
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

    for (int i = 0; i < n; i++)
        solve(arr[i]);

    cout << cnt;

    return 0;
}