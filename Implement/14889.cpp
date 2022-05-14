#include <iostream>
#include <vector> 
#include <memory.h>

#define MAX_NUM 1000000000

int n, result = MAX_NUM;
int arr[20][20];
int sel[20];

using namespace std;


void get_power_of_each_team(vector<int> team1) {
    int sum_t1 = 0, sum_t2 = 0, i;

    // team1 능력치
    for (auto a : team1) {
        for (auto b : team1) {
            sum_t1 += arr[a][b];
        }
    }

    // team2 능력치
    for (i = 0; i < n; i++) {
        if (sel[i] == 0) {
            for (int j = 0; j < n; j++) {
                if (sel[j] == 0) sum_t2 += arr[i][j];
            }
        }
    }

    result = min(result, abs(sum_t1 - sum_t2));
}

void solve(vector<int> team1, int idx, int cnt) {
    
    
    if (cnt == n/2) {
        get_power_of_each_team(team1);
        return;
    }

    if (idx >= n) return;

    int tmp, i;
    for (i = idx; i < n; i++) {
       // 순열이 아닌 조합의 경우로 team1만 생성
        team1.push_back(i);
        sel[i] = 1;
        solve(team1, i + 1, cnt + 1);
        team1.pop_back();
        sel[i] = 0;
    }
}

int main(void) {

    int i, j;

    cin >> n;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    memset(sel, 0, sizeof(sel));
    vector<int> team1;
    // n은 항상 짝수로 2로 나누기 가능
    solve(team1, 0, 0);

    cout << result;

    return 0;
}