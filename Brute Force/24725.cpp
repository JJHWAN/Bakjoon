#include <iostream>
#include <cstring>

using namespace std;

char MBTI[16][4];
char str[4][2] = { {'E', 'I'}, {'N', 'S'}, {'T', 'F'}, { 'J', 'P'} };

char arr[201][201];


void make(int idx) {

	int i, j, x = 16 / (1 << idx + 1), a = 0;
	char tmp;
	if (idx == 4) return;
	for (i = 0; i < 16; i += x) {
		if (a == 2) a = 0;
		tmp = str[idx][a];
		for (j = 0; j < x; j++) {
			MBTI[j + i][idx] = tmp;
		}
		a++;
	}
	make(idx + 1);
}

int check(char str[]) {
	int i;
	for (i = 0; i < 16; i++) {
		if (!strncmp(str, MBTI[i], 4)) return 1;
	}
	return 0;
}

void solve() {

	int n, m, i, j, k, cnt = 0;
	cin >> n >> m;

	for (i = 0; i < n; i++)
		cin >> arr[i];

	char str[4];
	// 아래 방향, (우측으로 갔다가 다시 좌측 체크)
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {

			if (j + 3 < m) {
				// 우측 체크
				for (k = 0; k < 4; k++)
					str[k] = arr[i][j + k];
				cnt += check(str);

				for (k = 0; k < 4; k++)
					str[k] = arr[i][j + 3 - k];

				cnt += check(str);
			}
			if (i + 3 < n) {
				// 아래 방향 체크

				for (k = 0; k < 4; k++)
					str[k] = arr[i + k][j];
				cnt += check(str);

				for (k = 0; k < 4; k++)
					str[k] = arr[i + 3 - k][j];

				cnt += check(str);

			}
			if (i + 3 < n && j + 3 < m) {
				// 우측 대각선 방향 체크
				for (k = 0; k < 4; k++)
					str[k] = arr[i + k][j + k];
				cnt += check(str);

				for (k = 0; k < 4; k++)
					str[k] = arr[i + 3 - k][j + 3 - k];
				cnt += check(str);
			}

			if (i + 3 < n && 2 < j) {
				if (i + 3 < n && 2 < j) {
					for (k = 0; k < 4; k++)
						str[k] = arr[i + k][j - k];
					cnt += check(str);

					for (k = 0; k < 4; k++)
						str[k] = arr[i + 3 - k][j - 3 + k];
					cnt += check(str);
				}
			}
		}
	}
	cout << cnt;

}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	make(0);

	solve();


	return 0;
}