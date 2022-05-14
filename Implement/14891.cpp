#include <iostream>
#include <deque>
#include <memory.h>

using namespace std;

deque<int> dq[4];

void rotate_one(int num, int dir)
{
    if (dir == 0)
        return;
    int front, back;
    front = dq[num].front();
    back = dq[num].back();
    if (dir == -1)
    {
        // 반시계
        dq[num].pop_front();
        dq[num].push_back(front);
    }
    else
    {
        // 시계
        dq[num].pop_back();
        dq[num].push_front(back);
    }
}

void rotate(int num, int dir)
{
    // num이 0이면? 1 계산, 2 계산, 3계산..
    // 중간에 1이 안 돌면 2, 3은 당연히 돌 일 X
    int arr_dir[4], i;

    memset(arr_dir, 0, sizeof(arr_dir));
    arr_dir[num] = dir;

    for (i = num; i > 0; i--)
    {
        if (dq[i][6] + dq[i - 1][2] == 1)
        {
            arr_dir[i - 1] = arr_dir[i] * -1;
        }
    }

    for (i = num; i < 3; i++)
    {
        if (dq[i][2] + dq[i + 1][6] == 1)
        {
            arr_dir[i + 1] = arr_dir[i] * -1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        rotate_one(i, arr_dir[i]);
    }
    // 0:[6] - 1:[2]-
    // 1:[6] - 2:[2]
    // 2:[6] - 3:[2]
}

int main(void)
{

    // 각 톱니바퀴의 상태를 저장하는 배열 or queue 필요

    char tmp[9];
    int i, j, k;

    for (i = 0; i < 4; i++)
    {
        cin >> tmp;
        for (j = 0; j < 8; j++)
        {
            if (tmp[j] == '0')
                dq[i].push_back(0);
            else
                dq[i].push_back(1);
        }
    }

    cin >> k;

    // 12시방향부터 시계방향 순서
    // 마주보는 극은 3시 (dq[x][2]) or 9시 (dq[x][6])

    // 연쇄 작용이 문제..
    // 먼저 모든 톱니바퀴의 회전 여부, 회전 방향을 구하고 적용하는 걸로

    int num, dir, result = 0;
    for (i = 0; i < k; i++)
    {
        cin >> num >> dir;
        rotate(num - 1, dir);
    }

    for (i = 0; i < 4; i++) {
        if (dq[i][0]) result += 1 << i;
    }

    cout << result;

    return 0;
}