#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
// 방향에 따라 X세대 드래곤 커브를 시계방향으로 90도 돌려주는 함수
// 드래곤 커브 생성 함수

// 드래곤 커브를 저장하는 방법은?
// 드래곤 커브는 0 ~ 10세대까지 있음

typedef struct pos {
	int x, y;
} pos;

pos dragon[11][2048];
int arr[101][101], cnt = 0;

void rotate(pos* des, int a, int b, int size, pos* src) {

	pos tmp[2048];
	int i;
	for (i = 0; i < size - 1; i++) {
		tmp[i].x = -1 * (src[i].y - b) + a;
		tmp[i].y = (src[i].x - a) + b;
	}

	memcpy(des, tmp, sizeof(tmp));
}

void make_curve(int k) {

	if (k == 0) {
		dragon[k][0].x = 0;
		dragon[k][0].y = 0;

		dragon[k][1].x = 1;
		dragon[k][1].y = 0;
		return;
	}

	// dragon[k]에 dragon[k-1]의 내용 복사
	// dragon[k]의 사이즈는 2, 3, 5, 8...

	int size = 2, i;
	for (i = 0; i < k - 1; i++)
		size += (size - 1);
	memcpy(dragon[k], dragon[k - 1], sizeof(dragon[k - 1]));

	// previous_dragon에 (x, y) 기준으로 90도 회전된 dragon[k-1]의 내용을 복사
	pos previous_dragon[2048];
	rotate(previous_dragon, dragon[k][size - 1].x, dragon[k][size - 1].y, size, dragon[k-1]);

	for (i = 2 * size - 2; i >= size; i--) {
		dragon[k][i].x = previous_dragon[2 * size - 2 - i].x;
		dragon[k][i].y = previous_dragon[2 * size - 2 - i].y;
	}

}

void rotate_v2(pos* des, int dir, int g) {

	int i, j, size = 2, tmp_x, tmp_y;
	pos tmp[2048];
	
	for (i = 0; i < g; i++)
		size += size - 1;

	memcpy(tmp, dragon[g], sizeof(dragon[g]));

	if (dir == 1) dir = 3;
	else if (dir == 3) dir = 1;

	for (i = 0; i < dir; i++) {
		for (j = 0; j < size; j++) {
			tmp_x = tmp[j].x;
			tmp_y = tmp[j].y;
			tmp[j].x = -1 * (tmp_y);
			tmp[j].y = tmp_x;
		}
	}

	memcpy(des, tmp, sizeof(tmp));
}

void apply(int x, int y, int dir, int g) {

	// (x, y)에 dir번 만큼 90도 회전한 g세대의 드래곤 커브를 Array에 적용
	int i, size = 2;
	pos result[2048];

	for (i = 0; i < g; i++)
		size += size - 1;

	rotate_v2(result, dir, g);

	for (i = 0; i < size; i++) {
		arr[result[i].x + x][result[i].y + y] = 1;
	}
}

void check_square() {
	
	int i, j, k;
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			if (!arr[i][j]) continue;
			if (!arr[i+1][j]) continue;
			if (!arr[i][j+1]) continue;
			if (!arr[i+1][j+1]) continue;
			cnt++;
		}
	}
}

void solve() {
	
	int n, i;
	int x, y, dir, g;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &dir, &g);
		apply(x, y, dir, g);
	}

	check_square();
}

int main(void) {

	int i;

	for (i = 0; i <= 10; i++) {
		make_curve(i);
	}

	solve();

	printf("%d", cnt);

	return 0;
}