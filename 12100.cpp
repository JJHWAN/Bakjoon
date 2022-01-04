#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>


using namespace std;

int N, max_num = 1;
int** arr, i, j;

struct board {
	int board[20][20];

	void rotate() {
		int tmp[20][20];
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				tmp[i][j] = board[N - 1 - j][i];
			}
		}
		memcpy(board, tmp, sizeof(board));
	}

	void push() {
		int tmp[20][20];
		for (i = 0; i < N; i++) {
			int idx = -1, flag = 0;
			for (j = 0; j < N; j++) {
				if (board[i][j] == 0);
				else if (flag && board[i][j] == tmp[i][idx]) {
					tmp[i][idx] *= 2; flag = 0;
				}
				else {
					tmp[i][++idx] = board[i][j]; flag = 1;
				}
			}
			for (idx++; idx < N; idx++) tmp[i][idx] = 0;
		}
		memcpy(board, tmp, sizeof(board));
	}

	void max_value() {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (max_num < board[i][j]) max_num = board[i][j];
			}
		}
	}

};


void DFS(board c, int cnt) {

	if (cnt == 5) {
		c.max_value();
		return;
	}

	int i;
	for (i = 0; i < 4; i++) {
		board next = c;
		next.push();
		DFS(next, cnt + 1);
		c.rotate();
	}
}

int main() {

	int i, j;
	board input;

	cin >> N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &input.board[i][j]);
		}
		getchar();
	}

	DFS(input, 0);

	printf("%d\n", max_num);

	return 0;
}