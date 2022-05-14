#include <iostream>
#include <stdlib.h>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

int n, m, cur_x, cur_y, cur_dir, cnt = 0;

int map[51][51];

int get_next_dir(int dir)
{
    if (dir == 0)
        return 3;
    else
        return (dir - 1);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> cur_x >> cur_y >> cur_dir;

    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }

    int next_x, next_y, tmp_dir;

    while (1)
    {
        // 현재 바라보는 곳을 청소
        map[cur_x][cur_y] = 2;
        cnt++;

        // 현재 상태의 왼쪽 블록이 청소하지 않은 빈 블록인지 확인
        tmp_dir = get_next_dir(cur_dir);
        next_x = cur_x + dir[tmp_dir][0];
        next_y = cur_y + dir[tmp_dir][1];

        for (i = 0; i < 4; i++)
        {
            tmp_dir = get_next_dir(tmp_dir);
            next_x = cur_x + dir[tmp_dir][0];
            next_y = cur_y + dir[tmp_dir][1];

            // 맞으면 전진하고 다시 while loop
            if (!map[next_x][next_y])
                break;
        }
        // 후진
        if (i > 3)
        {
            next_x = cur_x - dir[cur_dir][0];
            next_y = cur_y - dir[cur_dir][1];
            if (map[next_x][next_y] == 1)
                break;
        }

        cur_x = next_x;
        cur_y = next_y;
        cur_dir = tmp_dir;
    }
    // else 그렇지 않을 경우, 다시 왼쪽 방향으로 회전
    // 4번 반복시, 후진 => 만약 후진하려는데 뒤에 벽이 있다면? 작동 끝

    cout << cnt;
    return 0;
}