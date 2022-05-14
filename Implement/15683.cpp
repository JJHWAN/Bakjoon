#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m, result = 64;
int map[8][8];

struct cam
{
	int x, y;
	int num, dir;
};

vector<struct cam> v;

void fill_map(int tmp[][8], int x, int y, int dir)
{
	// dir = 0이면 -x 방향으로 벽이나, 경계를 만날 때까지
	int i;
	switch (dir)
	{
	case 0: // -x 방향
		for (i = x; i >= 0; i--)
		{
			if (tmp[i][y] == 6)
				break;
			tmp[i][y] = -1;
		}
		break;


	case 1: // +y 방향
		for (i = y; i < m; i++)
		{
			if (tmp[x][i] == 6)
				break;
			tmp[x][i] = -1;
		}
		break;
	case 2: // +x 방향
		for (i = x; i < n; i++)
		{
			if (tmp[i][y] == 6)
				break;
			tmp[i][y] = -1;
		}
		break;
	case 3: // -y방향
		for (i = y; i >= 0; i--)
		{
			if (tmp[x][i] == 6)
				break;
			tmp[x][i] = -1;
		}
		break;
	}
}

void solve(int idx, vector<struct cam> v, int size)
{
	if (idx == size)
	{
		// 사각지대의 크기 구하기
		int tmp[8][8];
		memcpy(tmp, map, sizeof(map));
		// 1번 카메라는 감시하는 방향이 12시부터 시계방향으로 하나씩
		for (int i = 0; i < size; i++)
		{
			switch (v[i].num)
			{
			case 1:
				fill_map(tmp, v[i].x, v[i].y, v[i].dir);
				break;
			case 2:
				fill_map(tmp, v[i].x, v[i].y, v[i].dir);
				fill_map(tmp, v[i].x, v[i].y, v[i].dir + 2);
				break;
			case 3:
				fill_map(tmp, v[i].x, v[i].y, v[i].dir);
				fill_map(tmp, v[i].x, v[i].y, (v[i].dir + 1) % 4);
				break;
			case 4:
				fill_map(tmp, v[i].x, v[i].y, v[i].dir);
				fill_map(tmp, v[i].x, v[i].y, (v[i].dir + 1) % 4);
				fill_map(tmp, v[i].x, v[i].y, (v[i].dir + 2) % 4);
				break;
			case 5:
				for (int j = 0; j < 4; j++)
					fill_map(tmp, v[i].x, v[i].y, j);
				break;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] == 0) cnt++;
			}
		}
		result = min(result, cnt);
		// 2번은 (상, 하)/(좌, 우) 2가지 케이스만 검사
		return;
	}

	int k = v[idx].num, t;
	switch (k)
	{
	case 2:
		t = 2;
		break;
	case 5:
		t = 1;
		break;
	default:
		t = 4;
		break;
	}

	for (int i = 0; i < t; i++)
	{
		v[idx].dir = i;
		solve(idx + 1, v, size);
	}
}
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5)
			{
				struct cam tmp;
				tmp.num = map[i][j], tmp.dir = 0;
				tmp.x = i;
				tmp.y = j;
				v.push_back(tmp);
			}
		}
	}

	int size = v.size();
	solve(0, v, size);
	cout << result;

	return 0;
}