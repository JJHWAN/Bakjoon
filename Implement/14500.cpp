#include <iostream>
#include <string.h>

using namespace std;
using ll = long long;

int n, m, result = 0, k;
int maze[510][510];

// n, m <= 500, 최대 크기 배열의 모든 곳을 돌면서 검사해도
// 25000 * (5*4) => 시간 내에 충분히 계산 가능
// Brute Force하게 접근

// 소요시간: 1시간 가량

struct tetro {
    int arr[4][2];

    void rotate() {
        // 우측으로 90도씩 회전
        // 각각 회전의 기준이 되는 점만 잘 잡으면 문제 X
        // 90도 돌면? (cos * x + sin * y, -sin * x + cos * y)
        // 180도 돌면? (x, y) => (-x, -y)
        int tmp[4][2];

        for (int i = 0; i < 4; i++) {
            tmp[i][0] = arr[i][1];
            tmp[i][1] = -arr[i][0];
        }
        
        memcpy(arr, tmp, sizeof(tmp));
    }

    void check(int x, int y) {
        int sum = 0, tmpx, tmpy;
        for (int i = 0; i < 4; i++) {
            tmpx = x + arr[i][0];
            tmpy = y + arr[i][1];
            if (tmpx < 0 || n <= tmpx || tmpy <0 || tmpy >= m) {
                return;
            }
            sum += maze[tmpx][tmpy];
        }

        if (result < sum) {
            result = sum;
        }
    }
};

tetro A[7];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        A[0].arr[i][0] = 0;
        A[0].arr[i][1] = i;
    }

    for (int i = 1; i < 5; i++) {
        A[i].arr[0][0] = 0;
        A[i].arr[0][1] = 0;

        A[i].arr[1][0] = -1;
        A[i].arr[1][1] = 0;

        A[i].arr[2][0] = 0;
        A[i].arr[2][1] = 1;
    }

    A[1].arr[3][0] = -1;
    A[1].arr[3][1] = 1;

    A[2].arr[3][0] = -2;
    A[2].arr[3][1] = 0;

    A[3].arr[3][0] = 1;
    A[3].arr[3][1] = 1;

    A[4].arr[3][0] = 1;
    A[4].arr[3][1] = 0;

    // A[2]의 대칭

    A[5].arr[0][0] = 0;
    A[5].arr[0][1] = 0;

    A[5].arr[1][0] = -1;
    A[5].arr[1][1] = 0;

    A[5].arr[2][0] = -2;
    A[5].arr[2][1] = 0;
    
    A[5].arr[3][0] = 0;
    A[5].arr[3][1] = -1;

    // A[3]의 대칭

    A[6].arr[0][0] = 0;
    A[6].arr[0][1] = 0;

    A[6].arr[1][0] = 0;
    A[6].arr[1][1] = 1;

    A[6].arr[2][0] = -1;
    A[6].arr[2][1] = 1;

    A[6].arr[3][0] = 1;
    A[6].arr[3][1] = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (k = 0; k <= 6; k++) {
                for (int z = 0; z < 4; z++) {
                    A[k].check(i, j);
                    A[k].rotate();
                }
            }
        }
    }

    cout << result << "\n";
}

int main(void) {


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //for (int i = 0; i < 19; i++) {
        solve();
    //}

    return 0;
}