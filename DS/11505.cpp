#include <iostream>

using namespace std;
using ll = long long;

#define MAXNUM 1000001
#define MOD 1000000007

ll v[MAXNUM];
ll tree[4 * MAXNUM];

// 백준 구간 곱 구하기 11505번
// 특정 값 업데이트 
// 최대 입력 개수 N : 1,000,000 (백만)
//
// M : 10,000 K : 10,000

// 단순 업데이트 한다고 하면 업데이트 한번에 시간 소모 얼마?
// 특정 값만 업데이트니까 O(logn)

ll init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = v[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}
ll update(int start, int end, int node, int idx, int value) {

    // start와 end 사이에 업데이트 해야하는 idx가 없는 경우,
    // 업데이트 할 요소가 없으니 바로 돌려주면 된다.
    if (idx < start || idx > end) return tree[node];

    if (start == end && start == idx) {
        return tree[node] = value;
    }
    if (start == end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    
    // 0이 들어오는 경우, 그 다음에 다시 그 위치를 업데이트하거나,
    // 다른 위치를 계산할 때, 큰 문제가 생긴다.
    // 자식 트리를 먼저 업데이트 하고 해당 값으로 다시 부모 트리를 업데이트 하도록 바꾸면?

    return tree[node] = (update(start, mid, node * 2, idx, value) * update(mid + 1, end, node * 2 + 1, idx, value)) % MOD;
}

ll getX(int start, int end, int node, int left, int right) {

    if (right < start || end < left) {
        return 1;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return (getX(start, mid, node * 2, left, right) * getX(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int x, y, z;

    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        cin >> x >> y >> z;
        if (x == 1) {
            update(0, n-1, 1, y-1, z);

        }
        else {
            cout << getX(0, n - 1, 1, y - 1, z - 1) << "\n";
        }
    }

    return 0;
}