#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>


typedef struct node {
	int age;
	int cnt;
	struct node* next;
} node;

typedef struct map {
	int energy;
	int num_tree;
	struct node* next;
} map;

int N, M, K, CHK;
int A[10][10];

map List[10][10];
int dir[8][2] = { {1, 0}, {1, 1},{1, -1},{0, 1},{0, -1},{-1, 0},{-1, -1}, {-1, 1} };

void add_list(int x, int y, int age, int cnt) {

	node* tmp = List[x][y].next;
	List[x][y].num_tree += cnt;

	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->age = age;
	new_node->cnt = cnt;
	new_node->next = NULL;

	if (tmp == NULL) {
		// (x, y)에 나무가 하나도 없을 때
		List[x][y].next = new_node;
	}
	else {
		// 나이 순으로 나무를 정렬해두고 싶음
		
		// cnt까지 활용해서 같은 나이의 나무가 많으면 하나의 노드에 중첩
		if (tmp->age > new_node->age) {
			new_node->next = tmp;
			List[x][y].next = new_node;
			return;
		}
		else if (tmp->age == new_node->age) {
			tmp->cnt += cnt;
			return;
		}

		while (tmp->next != NULL && tmp->next->age < age) {
			tmp = tmp->next;
		}

		if (tmp->next->age == age) {
			tmp->next->cnt += cnt;
			return;
		}
		else {
			if (tmp->next == NULL) {
				tmp->next = new_node;
			}
			else {
				new_node->next = tmp->next;
				tmp->next = new_node;
			}
		}
	}
}

void init() {

	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			List[i][j].energy = 5;
			List[i][j].next = NULL;
			List[i][j].num_tree = 0;
		}
	}

	int x, y, age;
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &age);
		add_list(x-1, y-1, age, 1);
	}
}

// 봄
void spring_and_summer() {

	int i, j, k;

	node* tmp, *prev;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			// List[i][j]의 나무들에 양분을 공급
			if (List[i][j].num_tree == 0) continue;
			tmp = List[i][j].next;
			prev = NULL;
			// 나무들의 나이 증가
			while (tmp != NULL) {
				if ((tmp->age * tmp->cnt) <= List[i][j].energy) {
					List[i][j].energy -= (tmp->age * tmp->cnt);
					tmp->age += 1;
				}
				else {
					if (List[i][j].energy != 0) {
						for (k = 0; k < tmp->cnt; k++) {
							if (tmp->age <= List[i][j].energy) {
								List[i][j].energy -= (tmp->age);
							}
							else break;
						}
						List[i][j].energy += (tmp->age / 2) * (tmp->cnt - k);
						List[i][j].num_tree -= (tmp->cnt - k);
						tmp->cnt = k;
						if (k != 0) {
							tmp->age += 1; // 이 경우에는 tmp 노드를 리스트에서 삭제하면 안 된다..
						}
						prev = tmp;
						tmp = tmp->next;
					}

					if (prev == NULL)
						List[i][j].next = NULL;
					else
						prev->next = NULL;

					break;
				}
				prev = tmp;
				tmp = tmp->next;
			}
			// 여름에 죽일 나무들 flag set (그냥 여기서 죽이자.. 시간 부족!)
			while (tmp != NULL) {
				List[i][j].energy += (tmp->age / 2) * tmp->cnt;
				List[i][j].num_tree -= tmp->cnt;
				tmp = tmp->next;
			}
		}
	}

}

// 가을
void fall_and_winter() {

	int i, j, k;
	int next_x, next_y;
	node* tmp;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			// 겨울 행동
			List[i][j].energy += A[i][j];
			// 가을 행동
			if (List[i][j].num_tree == 0) continue;
			tmp = List[i][j].next;
			while (tmp != NULL) {
				if (tmp->age % 5 == 0 && tmp->age > 0) {
					for (k = 0; k < 8; k++) {
						next_x = i + dir[k][0];
						next_y = j + dir[k][1];
						if (next_x < N && next_x >= 0) {
							if (next_y < N && next_y >= 0) {
								add_list(next_x, next_y, 1, tmp->cnt);
							}
						}
					}
				}
				tmp = tmp->next;
			}
		}
	}
}

void solve() {

	int i, j, cnt = 0;

	init();

	for (CHK = 0; CHK < K; CHK++) {
		spring_and_summer();
		fall_and_winter();
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cnt += List[i][j].num_tree;
		}
	}

	printf("%d", cnt);
}

int main(void) {

	int i, j;

	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	solve();

	return 0;
}