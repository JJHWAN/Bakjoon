#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int cnt = 0;
int n, m;

void func(vector <int> v, int idx, int sum) {
    if (idx == n) {
        if (sum == m) 
            cnt++;
        return;
    }

    func(v, idx + 1, sum);
    func(v, idx + 1, sum + v[idx]);
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector <int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    func(v, 0, 0);
    if (m == 0) cnt--;

    cout << cnt;
    return 0;
}