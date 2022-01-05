#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

using namespace std;


int map[21][21];
int command[1000];
int n, m, x, y, k, i, j;

struct dice {
	int plane[7] = {0, };
	
	void roll_up() {
		int tmp_plane[7] = { 0, };
		tmp_plane[1] = plane[5];
		tmp_plane[2] = plane[1];
		tmp_plane[3] = plane[3];
		tmp_plane[4] = plane[4];
		tmp_plane[5] = plane[6];
		tmp_plane[6] = plane[2];
		memcpy(plane, tmp_plane, sizeof(plane));
	}
	void roll_right() {
		int tmp_plane[7] = { 0, };
		tmp_plane[1] = plane[4];
		tmp_plane[2] = plane[2];
		tmp_plane[3] = plane[1];
		tmp_plane[4] = plane[6];
		tmp_plane[5] = plane[5];
		tmp_plane[6] = plane[3];
		memcpy(plane, tmp_plane, sizeof(plane));
	}

	void update_map() {
		if (map[x][y] == 0) {
			map[x][y] = plane[6];
		}
		else {
			plane[6] = map[x][y];
			map[x][y] = 0;
		}
	}
} dice;

int check_validity(int x, int y) {
	if (x == n || x < 0) 
		return 0;
	if (y == m || y < 0) 
		return 0;
	return 1;
}

int main(void) {
	
	scanf("%d %d %d %d %d ", &n, &m, &x, &y, &k);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
		//getchar();
	}

	for (i = 0; i < k; i++)
		scanf("%d", &command[i]);
	getchar();
	

	// 규칙 1. 이동후 칸의 숫자가 0이면 주사위의 바닥면의 숫자가 칸으로 복사된다.
	// 규칙 2. 칸의 숫자가 0이 아니면 칸에 쓰여 있는 숫자가 바닥면으로 복사된다.
	// 규칙 3. 지도의 바깥으로 이동시키는 명령이 주어지면 무시한다.
	// 이동할 때마다 주사위 윗 면에 쓰여있는 수를 출력한다.


	for (i = 0; i < k; i++) {

		switch (command[i]) {
		case 1:
			if (!check_validity(x, y + 1)) continue;
			y++;
			dice.roll_right();
			break;
		case 2:
			if (!check_validity(x, y - 1)) continue;
			y--;
			for(j=0;j<3;j++) dice.roll_right();
			break;
		case 3:
			if (!check_validity(x - 1, y)) continue;
			x--;
			dice.roll_up();
			break;
		case 4:
			if (!check_validity(x + 1, y)) continue;
			x++;
			for (j = 0; j < 3; j++) dice.roll_up();
			break;
		}
		dice.update_map();
		printf("%d\n", dice.plane[1]);
	}


	return 0;
}