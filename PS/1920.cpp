#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
#define MAX 100001

int arr[MAX] = { 0, };

int find(int start, int end, int k) {

    int mid, result = 0;

    while (start <= end) {

        mid = (start + end) / 2;

        if (arr[mid] > k)
            end = mid - 1;
        else if (arr[mid] == k) {
            result = 1; break;
        }
        else
            start = mid + 1;
    }

    return result;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);


    cin >> m;

    for (int i = 0; i < m; i++) {

        cin >> k;
        if (find(0, n - 1, k)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}