#include <iostream>
#include <string>

#define MAX 1 << 6 + 1
using namespace std;
using ll = long long;

int n;
int arr[MAX][MAX];

void solve(int x, int y, int size) {

    int sum = 0, k = size / 2;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sum += arr[x + i][y + j];

    if (sum == 0) {
        cout << "0";
        return;
    }
    else if (sum == size * size) {
        cout << "1";
        return;
    }

    cout << "(";

    solve(x, y, k);
    solve(x, y + k, k);
    solve(x + k, y, k);
    solve(x + k, y + k, k);

    cout << ")";
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] -'0';
        }
    }

    solve(0, 0, n);

    return 0;
}