#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

#define MAX_DIST 1000000000

typedef struct pos {
	int x, y;
} pos;

int N, M, chick_num = 0, home_num = 0, max_chick_dist = MAX_DIST;
int arr[101][101];
pos chicken[13], home[101];

void calculate(pos* chick, int cnt) {

	int tmp_dist, i, j, sum = 0;
	int dist[101];
	for (i = 0; i < home_num; i++)
		dist[i] = MAX_DIST;

	for (i = 0; i < cnt; i++) {
		for (j = 0; j < home_num; j++) {
			// get dist and update dist
			tmp_dist = abs(chick[i].x - home[j].x);
			tmp_dist += abs(chick[i].y - home[j].y);

			if (tmp_dist < dist[j])
				dist[j] = tmp_dist;
		}
	}

	for (i = 0; i < home_num; i++) {
		sum += dist[i];
	}

	if (sum < max_chick_dist)
		max_chick_dist = sum;

}

void combination(pos* chick, int idx, int cnt) {
	// chicken 집의 조합을 생성해서 검사
	if (cnt == M || idx == chick_num) {
		// calculate chick_dist
		calculate(chick, cnt);
		return;
	}

	// 최대 M개를 고르는 거니까 그 이하도 모두 검사
	int i;
	for (i = idx; i < chick_num; i++) {
		chick[cnt]= chicken[i];
		combination(chick, i + 1, cnt + 1);
		// 원상복구 할 필요가 있나..?
	}
}

void solve() {

	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				chicken[chick_num].x = i;
				chicken[chick_num].y = j;
				chick_num++;
			}
			if (arr[i][j] == 1) {
				home[home_num].x = i;
				home[home_num].y = j;
				home_num++;
			}
		}
	}

	// 치킨집의 수는..? => M <= K <= 13
	// 치킨집 내부의 M개를 뽑는 조합을 구하고, 치킨 거리를 갱신하는 경우로 시도
	

	pos chick[13];
	combination(chick, 0, 0);

	printf("%d", max_chick_dist);

	// 개선방안: 치킨 거리를 갱신할 때, 꼭 모든 집을 해야하는가?
}

int main(void) {

	int i;

	scanf("%d %d", &N, &M);
	solve();

	return 0;
}