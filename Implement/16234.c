#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int N, L, R;
int arr[51][51];

// 모든 블록을 검사하고 연합마다 연산을 진행해야한다.
// union-find 느낌으로 블록을 검사하다가 두 개의 서로 다른 연합이 하나의 연합이 될 수 있음

typedef struct link_list {
	int x, y;
	int un_num;
	struct link_list* next;
} link_list;

link_list** UN;
int visited[51 * 51];

void add_list(int union_number, int union_add) {
	
	// UN[union_number]의 끝에 UN[union_add]을 추가

	link_list* tmp = UN[union_number];

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = UN[union_add];

	tmp = tmp->next;

	while (tmp != NULL) {
		tmp->un_num = union_number;
		tmp = tmp->next;
	}
}

void update_arr(int union_number) {
	link_list* tmp = UN[union_number];
	int sum = 0, cnt = 0, num;

	while (tmp != NULL) {
		cnt += 1;
		sum += arr[tmp->x][tmp->y];
		tmp = tmp->next;
	}

	num = sum / cnt;

	tmp = UN[union_number];
	while (tmp != NULL) {
		visited[tmp->x * N + tmp->y] = 1;
		arr[tmp->x][tmp->y] = num;
		tmp = tmp->next;
	}
}

void solve() {

	int cnt = 0, i, j, end_flag; // 인구 이동이 발생한 턴의 수
	// linked list로 할까?
	UN = (link_list**)malloc(sizeof(link_list*) * (N * N));
	for (i = 0; i < N * N; i++) {
		UN[i] = (link_list*)malloc(sizeof(link_list));
	}

	while (1) {

		end_flag = 0;
		memset(visited, 0, sizeof(visited));

		// 연합화 진행
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				UN[i * N + j]->x = i;
				UN[i * N + j]->y = j;
				UN[i * N + j]->un_num = i * N + j;
				UN[i * N + j]->next = NULL;
			}
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				// 인접한 칸 들의 인구수를 검사 (우, 아래만 검사하면 된다)
				if (j != N - 1) { //오른쪽 검사
					if (abs(arr[i][j] - arr[i][j + 1]) >= L && abs(arr[i][j] - arr[i][j + 1]) <= R) {
						// 인구 차이가 L명 이상, R명 이하이면 연합화
						if (UN[i*N + j]->un_num < UN[i*N + j + 1]->un_num) {
							// i, j 쪽으로 합체..
							add_list(UN[i * N + j]->un_num, UN[i * N + j + 1]->un_num);
						}
						if (UN[i * N + j]->un_num > UN[i * N + j + 1]->un_num) {
							add_list(UN[i * N + j + 1]->un_num, UN[i * N + j]->un_num);
						}
						end_flag = 1;
					}
				}
				if (i != N - 1) { // 아래 검사
					if (abs(arr[i][j] - arr[i+1][j]) >= L && abs(arr[i][j] - arr[i+1][j]) <= R) {
						if (UN[i * N + j]->un_num < UN[(i + 1) * N + j]->un_num) {
							// i, j 쪽으로 합체..
							add_list(UN[i * N + j]->un_num, UN[(i + 1) * N + j]->un_num);
						}
						if (UN[i * N + j]->un_num > UN[(i + 1) * N + j]->un_num) {
							add_list(UN[(i + 1) * N + j]->un_num, UN[i * N + j]->un_num);
						}
						end_flag = 1;
					}
				}
			}
		}

		if (!end_flag) break;
		else cnt += 1;
		// 연합화 끝
		
		// 각 연합마다 검사하면서 visited 체크하고 가져야할 값을 부여
		for (i = 0; i < N * N; i++) {
			if (visited[i]) continue;
			update_arr(i);
		}
	}

	printf("%d",  cnt);
}

int main(void) {

	int i, j;

	scanf("%d %d %d", &N, &L, &R);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	solve();

	return 0;
}