#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int n;
int map[20][20];
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int fish_num[7] = {0, };
typedef struct shark_info {
	int x, y;
	int size, cnt;
} shark_info;

shark_info info;

typedef struct queue_node {
	int x, y, dist;
	struct queue_node* next;
} queue_node;

typedef struct queue {
	queue_node* top;
	queue_node* tail;
} queue;

queue* q;

int empty() {
	if (q->top == NULL) return 1;
	else return 0;
}

void add_queue(int x, int y, int dist) {

	queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
	new_node->x = x;
	new_node->y = y;
	new_node->dist = dist;
	new_node->next = NULL;

	if (q->top == NULL) {
		q->top = new_node;
		q->tail = new_node;
	}
	else {
		q->tail->next = new_node;
		q->tail = new_node;
	}
}

void delete_queue() {

	if (empty()) {
		printf("Queue is already empty\n");
		return;
	}

	queue_node* tmp = q->top;
	q->top = q->top->next;
}

queue_node* pop() {

	if (empty()) {
		//printf("Queue is already empty\n");
		return NULL;
	}
	queue_node* tmp = q->top;
	q->top = q->top->next;

	return tmp;
}

int serch(int x, int y) {
	// BFS using queue..
	int i, dist, cur_x, cur_y;
	int next_x, next_y, min_x, min_y;

	// 현재 위치를 큐에 넣고 시작
	add_queue(x, y, 0);
	queue_node* tmp = NULL;
	int visited[20][20] = {0, };
	visited[x][y] = 1;

	for (i = 1; i < info.size; i++) {
		if (fish_num[i] != 0) break;
	}
	if (i == info.size) return -1;

	while (1) {

		if (tmp != NULL)
			free(tmp);

		tmp = pop();
		// empty check	
		
		if (tmp == NULL) break;
		

		cur_x = tmp->x;
		cur_y = tmp->y;
		dist = tmp->dist;

		if (info.size > map[cur_x][cur_y] && map[cur_x][cur_y] != 0) {
			// 먹는 칸에 도달했다
			info.cnt += 1;
			map[x][y] = 0;
			min_x = cur_x, min_y = cur_y;
			while (!empty() && tmp->dist == dist) {

				if (info.size > map[tmp->x][tmp->y] && map[tmp->x][tmp->y] != 0) {
					if (tmp->x == min_x) {
						if (tmp->y < min_y) {
							min_y = tmp->y;
						}
					}
					if (tmp->x < min_x) {
						min_x = tmp->x;
						min_y = tmp->y;
					}
				}
				free(tmp);
				tmp = pop();
			}

			fish_num[map[min_x][min_y]]--;
			map[min_x][min_y] = 9;
			info.x = min_x;
			info.y = min_y;
			break;
		}

		for (i = 0; i < 4; i++) {
			// 범위 검사
			next_x = cur_x + dir[i][0];
			next_y = cur_y + dir[i][1];
			if (cur_x + dir[i][0] < 0 || cur_x + dir[i][0] >= n) continue;
			if (cur_y + dir[i][1] < 0 || cur_y + dir[i][1] >= n) continue;
			if (visited[next_x][next_y]) continue;
			if (info.size < map[next_x][next_y]) continue;

			visited[next_x][next_y] = 1;
			add_queue(next_x, next_y, dist + 1);
		}
	}
	
	if (tmp == NULL)
		return -1;
	else {
		if (info.cnt == info.size) {
			info.size++;
			info.cnt = 0;
		}
		return dist;
	}

}

void solve() {
	int sum = 0, tmp = 0;


	while (1) {
		tmp = serch(info.x, info.y);

		while (!empty()) {
			free(pop());
		}

		if (tmp == -1) break;
		else sum += tmp;
	}

	printf("%d", sum);
}

int main(void) {

	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				info.x = i;
				info.y = j;
				info.size = 2;
				info.cnt = 0;
			}
			else if (map[i][j] > 0) {
				fish_num[map[i][j]]++;
			}
		}
	}

	q = (queue*)malloc(sizeof(queue));
	q->top = NULL;
	q->tail = NULL;

	solve();

	return 0;
}