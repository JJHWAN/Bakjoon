#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int l, c;
vector<char> a;

void func(int idx, int k, vector<char> v, int num1, int num2) {

    if (idx == l) {
        // 종료조건
        if (num1 >= 2 && num2 >= 1) {
            // 자음이 최소 2개 이상
            sort(v.begin(), v.end());
            for (int i = 0; i < l; i++)
                cout << v[i];
            cout << "\n";
        }
        return;
    }

    if (k == c) {
        return;
    }

    if (a[k] == 'a' || a[k] == 'o' || a[k] == 'e' || a[k] == 'i' || a[k] == 'u') {
        v[idx] = a[k];
        func(idx + 1, k + 1, v, num1, num2+1);
        v[idx] = '\0';
        func(idx, k + 1, v, num1, num2);
    }
    else {
        v[idx] = a[k];
        func(idx + 1, k + 1, v, num1+1, num2);
        v[idx] = '\0';
        func(idx, k + 1, v, num1, num2);
    }
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> l >> c;

    // 서로 다른 l개의 문자로 구성
    // 최소 1개의 모음, 2개의 자음 필요
    // 모음 : a , e, i ,o , u
    // 알파벳 순으로 정렬해서 가능성 있는 암호를 모두 출력, 중복까지는 고려할 필요 X
    // L, C <= 15

    vector<char> v(l);
    a.resize(c);

    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    func(0, 0, v, 0, 0);

    return 0;
}