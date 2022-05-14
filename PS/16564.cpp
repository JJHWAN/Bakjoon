#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

// 백준 16564번 히오스 프로게이머 문제

// 캐릭터의 수, 올릴 수 있는 레벨의 수가 주어진다.
// 그 다음 줄부터 캐릭터들의 레벨이 각각 주어질 때,
// min(캐릭터 레벨)의 최대를 출력하라.

#define MAX 1000001

int arr[MAX];
int n, k;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int result = arr[0], add_needed, i;

    for (i = 0; i < n - 1; i++) {
        add_needed = arr[i + 1] - result;
        if (k - (add_needed) * (i + 1) >= 0) {
            // 다음 캐릭터의 레벨만큼 아래 캐릭터를 모두 올리는게 가능한 경우
            k -= (add_needed) * (i + 1);
            result = arr[i + 1];
        }
        else {
            // 다음 캐릭터의 레벨만큼 아래 캐릭터를 모두 올리지는 못할 경우
            result += k / (i + 1);
            k %= add_needed;
            break;
        }
    }
    // 모든 캐릭터의 레벨을 동일하게 맞춘 경우
    if (i == n-1 && k > 0) {
        result += k / n;
    }

    cout << result;

    return 0;
}