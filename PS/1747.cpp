#include <iostream>

using namespace std;
using ll = long long;

#define MAX 1005000

int check1[MAX + 1] = { 0, }, check2[MAX + 1] = { 0, };

// 소수이자 펠린드롬인 수 구하기

// 각각 배열을 만들어서 소수는 체로 거르고,
// 펠린드롬은 더더욱 판별하기 쉬움

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    check1[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        if (check1[i]) continue;
        for (int j = 2; j * i <= MAX; j++) {
            check1[i * j] = 1;
        }
    }

    // 3자리수까지 판별 완료
    for (int i = 1; i < 10; i++) {
        check2[i] = 1;
        check2[i * 10 + i] = 1;
        for (int j = 0; j < 10; j++) {
            check2[i * 100 + j * 10 + i] = 1;
        }
    }

    // 4
    // ab ba
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int a = i * 10 + j;
            int b = j * 10 + i;
            check2[100 * a + b] = 1;
            //cout << a*100 + b << endl;
            for (int k = 0; k < 10; k++) {
                // 5
                // ab c ba  
                check2[a * 1000 + k * 100 + b] = 1;
                // cout << a*1000 + k*100 + b << endl;
            }
        }
    }

    // 6
    // abc cba
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int a = i * 100 + j * 10 + k;
                int b = k * 100 + j * 10 + i;
                check2[a * 1000 + b] = 1;
                //cout << a * 1000 + b << endl;
            }
        }
    }

    // 1005001
    check2[1000001] = 1;
    check2[1001001] = 1;
    check2[1002001] = 1;
    check2[1003001] = 1;
    check2[1004001] = 1;

    for (int i = n; i <= MAX; i++) {
        if (!check1[i] && check2[i]) {
            cout << i; 
            break;
        }
    }

    return 0;
}