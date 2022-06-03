#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// N은 세로선의 개수
// M은 가로선의 개수 (주어지는)
// H는 세로선마다 가로선을 놓을 수 있는 위치의 개수
int N, M, H, MAX_CASE;
int** arr;

// (N-1) * H개의 가로선을 놓을 수 있는 선택지가 존재
// 그 중 M개는 이미 주어졌으니, 나머지 선택지 중에서 
// 1개, 2개, 3개.. 이렇게 조합들을 시도해 가면서 검색
// (N-1) * H개를 다 했는데도 안 되면 -1 출력

// 현재 arr로 가능한지 check해주는 함수 하나
// 조합을 만들어주는 함수 하나 

int check_possibility(int** arr);
int make_case(int** arr, int idx, int cnt, int limit);

int check_possibility(int** arr) {

	// arr[a][b] == 1 이면 a, a+1번째 세로선 사이에 b번째 가로선에 사다리가 있음
	// a에서 내려오던 중이면? a+1 번째로 이동
	int i, j, cur_pos;
	for (i = 0; i < N; i++) {
		j = 0; cur_pos = i;
		while (j < H) {
			if (cur_pos != 0) {
				if (arr[j][cur_pos - 1] == 1) { // 현재 타고 있는 사다리에서 왼쪽 가로선이 나타났다면?
					cur_pos = cur_pos - 1;
					j++; continue;
				}
			}
			if (cur_pos != N - 1) {
				if (arr[j][cur_pos] == 1) { // 현재 타고 있는 사다리에서 오른쪽 가로선이 등장하면?
					cur_pos = cur_pos + 1;
					j++; continue;
				}
			}
			j++;
		}
		if (cur_pos != i) return 0;
	}

	return 1;
}


int make_case(int** arr, int idx, int cnt, int limit) {

	if (cnt >= 4) return 0;

	// 종료조건1 limit 개의 사다리를 놓았을 때 
	if (cnt == limit)
		return check_possibility(arr);

	// 종료조건2 놓을 사다리가 (limit-cnt)개가 남았는데, 
	// 놓을 수 있는 자리가 그만큼 남지 않은 경우
	if (limit - cnt > MAX_CASE - idx - 1)
		return 0;

	int i;

	for (i = idx; i < MAX_CASE; i++) {
		// 양 옆에 사다리가 존재하면 설치 불가능
		if (arr[i / (N - 1)][i % (N - 1)] == 1) continue;

		if (i % (N - 1) != 0) {
			if (arr[i / (N - 1)][i % (N - 1) - 1] == 1) continue;
		}
		if (i % (N - 1) != N - 2) {
			if (arr[i / (N - 1)][i % (N - 1) + 1] == 1) continue;
		}

		arr[i / (N - 1)][i % (N - 1)] = 1;
		if (make_case(arr, i + 1, cnt + 1, limit))
			return 1;
		arr[i / (N - 1)][i % (N - 1)] = 0;
	}

	return 0;
}



int main(void) {

	int i, a, b;

	scanf("%d %d %d", &N, &M, &H);

	MAX_CASE = (N - 1) * H;
	arr = (int**)calloc(H, sizeof(int*));
	for (i = 0; i < H; i++)
		arr[i] = (int*)calloc(N - 1, sizeof(int));

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		arr[a - 1][b - 1] = 1;
	}

	for (i = 0; i <= 3; i++) {
		if (make_case(arr, 0, 0, i))
			break;
	}

	if (i ==4)
		printf("-1");
	else
		printf("%d", i);

	return 0;
}