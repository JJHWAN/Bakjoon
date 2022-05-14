#include <iostream>

using namespace std;

int n, l;
int arr[100][100];

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;

    // 경사로의 조건
    // 경사로는 낮은 칸에 놓으면, 연속된 L개의 칸의 값이 같아야 한다.
    // 경사로의 높이는 1

    int i, j, cnt = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 진행하다가 1 증가 or 1 감소시 경사로가 가능한지 확인
    // 각 행부터 검사
    int tmp, t, k;

    for (i = 0; i < n; i++)
    {
        tmp = 1;
        for (j = 0; j < n - 1; j++)
        {
            if (arr[i][j] + 1 == arr[i][j + 1])
            {
                // 뒤의 칸이 1 증가한 경우
                if (tmp < l)
                    break;
                else
                    tmp = 1;
            }
            else if (arr[i][j] - 1 == arr[i][j + 1])
            {
                // 뒤의 칸이 1 감소한 경우
                // 뒤의 L칸을 검사
                t = arr[i][j + 1];

                if (j + l >= n) break; // 범위 초과

                for (k = j + 1; k < j + 1 + l; k++)
                {
                    if (arr[i][k] != t) break;
                }

                if (k != j + 1 + l) break;

                j = k-2;
                tmp = 0;
            }
            else if (arr[i][j] == arr[i][j + 1])
            {
                // 같은 경우
                tmp++;
            }
            else
            {
                // 2 이상 차이가 나는 경우, 경사로 설정 불가
                break;
            }
        }
        if (j >= n - 1)
            cnt++;
    }


    for (i = 0; i < n; i++)
    {
        tmp = 1;
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j][i] + 1 == arr[j + 1][i])
            {
                // 뒤의 칸이 1 증가한 경우
                if (tmp < l)
                    break;
                else
                    tmp = 1;
            }
            else if (arr[j][i] - 1 == arr[j + 1][i])
            {
                // 뒤의 칸이 1 감소한 경우
                // 뒤의 L칸을 검사
                t = arr[j + 1][i];

                if (j + l >= n) break; // 범위 초과

                for (k = j + 1; k < j + 1 + l; k++)
                {
                    if (arr[k][i] != t) break;
                }

                if (k != j + 1 + l) break;

                j = k-2;
                tmp = 0;
            }
            else if (arr[j][i] == arr[j + 1][i])
            {
                // 같은 경우
                tmp++;
            }
            else
            {
                // 2 이상 차이가 나는 경우, 경사로 설정 불가
                break;
            }
        }
        if (j >= n - 1) 
            cnt++;
    }

    cout << cnt;

    return 0;
}