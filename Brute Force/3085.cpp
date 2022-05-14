#include <iostream>
#include <memory.h>

using namespace std;

int max_num, n;
char map[50][50];

void solve()
{

    char str[50];
    max_num = 0;

    // 3 <= N <= 50
    // 사탕의 색상 종류는 4개 (C, P, Z, Y)

    // 사탕의 색이 다른 인접한 두 칸을 바꾸고,
    // 모두 같은 색으로 이루어진 가장 긴 연속 부분을 고른 다음 먹는다.

    // 긴 연속 부분의 최대? N
    // 사탕을 바꿔서 일어날 수 있는 변화는? +1 or 두 부분을 연결하는 경우

    // 행 방면의 연속 배열, 열 방연의 연속 배열을 만들어서 검사하는 방안으로
    // 만약 N개짜리 나오면 바로 break;

    int i, j, cnt, start_idx;

    for (i = 0; i < n; i++)
    {
        cin >> str;
        memcpy(map[i], str, sizeof(str));
    }

    int check_num = 0, k, tmp;

    // 행부터 검사
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (map[i][j - 1] != map[i][j])
            {
                // 다르다면

                tmp = map[i][j];
                map[i][j] = map[i][j - 1];
                map[i][j - 1] = tmp;

                // 1) i 행 검사
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[i][start_idx] == map[i][k])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }

                // 2) j 열 검사
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[start_idx][j] == map[k][j])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }

                // 3) j -1열 검사
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[start_idx][j - 1] == map[k][j - 1])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }

                tmp = map[i][j];
                map[i][j] = map[i][j - 1];
                map[i][j - 1] = tmp;
            }
        }
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (map[i - 1][j] != map[i][j])
            {

                tmp = map[i][j];
                map[i][j] = map[i - 1][j];
                map[i - 1][j] = tmp;

                // 1) j 행 검사
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[start_idx][j] == map[k][j])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }

                // 2) i 열
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[i][start_idx] == map[i][k])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }

                // 3) i-1 열
                for (k = 0; k < n;)
                {
                    cnt = 0;
                    start_idx = k;
                    while (k < n && map[i-1][start_idx] == map[i-1][k])
                    {
                        // 같으면 증가
                        cnt++;
                        k++;
                    }
                    // 다르거나, 끝났거나
                    max_num = max(max_num, cnt);
                }
                tmp = map[i][j];
                map[i][j] = map[i - 1][j];
                map[i - 1][j] = tmp;
            }
        }
    }

    cout << max_num;
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    solve();

    return 0;
}