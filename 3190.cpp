#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <utility>
#include <queue>

using namespace std;


typedef struct route {
	int x; int y;
};

int n, k, l;
int board[101][101] = {0, };
int rotate_info[100][2];

int dir[4][2] = {
	{0, +1}, {+1, 0}, {0, -1}, {-1, 0}
};

queue<route> snake;

int main(void) {

	int i;
	int a, b;
	char r;

	scanf("%d", &n);
	//getchar();
	scanf("%d", &k);
	//getchar();
	for (i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		board[a][b] = 1; // apple
	}

	scanf("%d", &l);
	//getchar();

	for (i = 0; i < l; i++) {
		scanf("%d %c", &rotate_info[i][0], &rotate_info[i][1]);
	}

	int time = 0, x = 0, flag = 0, rotate_idx = 0;
	int head_x = 1, head_y = 1;
	int tail_x = 1, tail_y = 1;

	route head, tail;

	board[1][1] = 2; // snake
	head.x = 1; head.y = 1;
	snake.push(head);

	while (1) {

		head_x += dir[x][0]; head_y += dir[x][1];
		time++;
		// collision check
		if (board[head_x][head_y] == 2 || head_x == 0 || head_x == n+1 || head_y == 0 || head_y == n+1) {
			break;
		}
		// check snake ate apple or not
		if (board[head_x][head_y] == 1) {
			flag = 1;
		}
		else flag = 0;
		
		board[head_x][head_y] = 2;
		head.x = head_x; head.y = head_y;
		snake.push(head);

		tail = snake.front();

		if (!flag) {
			// upadte tail -> need to know direction
			board[tail.x][tail.y] = 0;
			snake.pop();
		}

		if (rotate_idx < l && time == rotate_info[rotate_idx][0]) {
			if (rotate_info[rotate_idx][1] == 'D') {
				x++;
			}
			else {
				x--;
			}
			rotate_idx++;
			if (x == 4) x = 0;
			if (x == -1) x = 3;
		}

	}

	printf("%d", time);

	return 0;
}