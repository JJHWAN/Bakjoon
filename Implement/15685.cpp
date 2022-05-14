#include <iostream>
#include <vector>
#include <utility>

using namespace std;
// 왜 틀렸는가..?

vector<pair<int, int>> v[11];

int arr[101][101];

void print_all() {
    for (int i = 0; i < 101; i++) {
        cout << i << ": \t";
        for (int j = 0; j < 101; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}

vector<pair<int, int>> rotate_dragon(int k)
{
    vector<pair<int, int>> tmp, result;
    tmp = v[k];

    int i, size = tmp.size();
    int a = tmp[0].first, b = tmp[0].second;
    // (0, 0)을 돌려놓은 결과를 매번 맨 앞에 놓는다.
    // (0, 0)은 매번 맨 뒤의 원소에 놓는다.
    for (i = size - 1; i > 0; i--)
    {
        result.push_back({ -tmp[i].second + b + a, -a + tmp[i].first + b });
    }

    for (i = 0; i < size; i++) {
        result.push_back(tmp[i]);
    }

    return result;
}

void get_dragon_curve()
{

    // 드래곤 커브를 구하기 위해서는 k세대를 마지막 기준점에 대해서 시계 방향으로 90도 회전
    // 다시 k세대 드래곤 커브 덮어쓰기를 반복하면 된다.
    int i;

    v[0].push_back({ 1, 0 });
    v[0].push_back({ 0, 0 });

    for (i = 1; i < 11; i++)
    {
        v[i] = rotate_dragon(i - 1);
    }
}

int main(void)
{

    int n, i, j, cnt = 0;
    int X, Y, D, G;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 생각해보면 드래곤 커브는 매번 동일하다.
    // 드래곤 커브를 0 ~ 10세대까지 미리 구해놓고, rotate만 해서 제공한다면?

    get_dragon_curve();

    for (i = 0; i < n; i++)
    {
        cin >> X >> Y >> D >> G;

        switch (D) {
        case 0: 
            for (auto a : v[G]) {
                arr[X + a.first][Y + a.second] = 1;
            }
            break;
        case 1:
            for (auto a : v[G]) {
                arr[X + a.second][Y - a.first] = 1;
            }
            break;
        case 2: 
            for (auto a : v[G]) {
                arr[X - a.first][Y - a.second] = 1;
            }
            break;
        case 3: 
            for (auto a : v[G]) {
                arr[X - a.second][Y + a.first] = 1;
            }
            break;
        }

    }

    print_all();

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 1] == 4) cnt++;
        }
    }

    cout << cnt;

    return 0;
}