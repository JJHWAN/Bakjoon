#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;

int solve(int** arr, int k) {

    // arr를 [0, 0] [0, 1] [1, 0] [1, 1] 꼴로 나누어서
    // solve 적용, 2번째로 큰 값들만 return

    if (k == 2) {
        int idx = 0;
        vector <int> v(4);

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                v[idx++] = arr[i][j];
        sort(v.begin(), v.end());
        return v[2];
    }

    int** a;
    int idx = 0;
    vector <int> v(4);

    a = (int**)malloc(sizeof(int*) * (k / 2));
    for (int i = 0; i < k / 2; i++) {
        a[i] = (int*)malloc(sizeof(int) * (k / 2));
    }


    for (int x = 0; x < 4; x++) {
        int p, q;
        switch (x) {
        case 0:
            p = 0, q = 0;
            break;
        case 1:
            p = (k / 2), q = 0;
            break;
        case 2:
            p = 0, q = k / 2;
            break;
        case 3:
            p = k / 2, q = k / 2;
            break;
        }
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k / 2; j++) {
                a[i][j] = arr[i + p][j + q];
            }
        }
        v[x] = solve(a, k / 2);
    }

    sort(v.begin(), v.end());
    return v[2];
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int** a;
    cin >> n;
    m = pow(2, n);

    a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve(a, n);

    return 0;
}