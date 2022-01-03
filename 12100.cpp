#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int N, max_num = 1;
int** arr;

void DFS(int** arr, int cnt);

void DFS(int** arr, int cnt) {
	// 4가지 방향에 대한 시도
	
	int i, j, a, b, tmp = 0;
	int row = 0, col = 0, k;
	
	int** arr2;
	arr2 = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		arr2[i] = (int*)malloc(sizeof(int) * N);


	if (cnt == 5) {
		//printf("\n");
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (tmp < arr[i][j]) tmp = arr[i][j];
				//printf("%d ", arr[i][j]);
			}	
			//printf("\n");
		}
		max_num = max(max_num, tmp);
		
		return ;
	}



	for (i = 0; i < 4; i++) {
		
		for (a = 0; a < N; a++) {
			for (b = 0; b < N; b++) {
				arr2[a][b] = arr[a][b];
			}
		}

		switch (i) {
		case 0:
			// 올라가는 방향
			for (col = 0; col < N; col++) {
				k = 0;
				while (k < N - 1) {
					// 일단 다 올려
					// 검사하는 칸 빈칸이면 다 올리기
					if (arr2[k][col] == 0) {
						a = 0;
						for (j = k; j < N; j++) {
							if (arr2[j][col] != 0) {
								a = j - k; break;
							}
						}
						for (j = k; j < N - a; j++) {
							arr2[j][col] = arr2[j + a][col];
							arr2[j + a][col] = 0;
						}
						arr2[N-1][col] = 0;
					}
					k++;
				}
			}

			for (col = 0; col < N; col++) {
				k = 0;
				while (k < N - 1) {
					// 검사하는 칸 빈칸(합친 칸)이면 올리기
					if (arr2[k][col] == 0) {
						if (arr2[k + 1][col] == 0) break;
						for (j = k; j < N - 1; j++) {
							arr2[j][col] = arr2[j + 1][col];
						}
						arr2[N - 1][col] = 0;
						continue;
					}
					if (arr2[k][col] == arr2[k + 1][col]) {
						// 만약 둘이 같으면?
						// 둘을 합치고 없어진 칸을 0으로 설정
						arr2[k][col] = 2 * arr2[k][col];
						arr2[k + 1][col] = 0;
					}
					k++;
				}
			}
			break;
		case 1:
			// 내려가는 방향
			for (col = 0; col < N; col++) {
				k = N - 1;
				while (k > 0) {
					if (arr2[k][col] == 0) {
						a = 0;
						for (j = k; j >= 0 ; j--) {
							if (arr2[j][col] != 0) {
								a = k - j; break;
							}
						}
						for (j = k; j >= a; j--) {
							arr2[j][col] = arr2[j - a][col];
							arr2[j - a][col] = 0;
						}

						//for (j = k; j > 0; j--) 
						//	arr2[j][col] = arr2[j - 1][col];
						
						arr2[0][col] = 0;
					}
					k--;
				}
			}
			
			for (col = 0; col < N; col++) {
				k = N - 1;
				while (k > 0) {
					if (arr2[k][col] == 0) {
						if (arr2[k - 1][col] == 0) break;
						for (j = k; j > 0; j--) {
							arr2[j][col] = arr2[j - 1][col];
						}
						arr2[0][col] = 0;
						continue;
					}
					if (arr2[k][col] == arr2[k - 1][col]) {
						// 둘이 같으면?
						// 둘을 합치고, 칸을 0으로 설정
						arr2[k][col] = 2 * arr2[k][col];
						arr2[k - 1][col] = 0;
					}
					k--;
				}
			}
			break;
		case 2:
			// 왼쪽으로 미는 경우
			for (row = 0; row < N; row++) {
				k = 0;
				while (k < N - 1) {
					if (arr2[row][k] == 0) {
						a = 0;
						for (j = k; j < N; j++) {
							if (arr2[row][j] != 0) {
								a = j - k; break;
							}
						}
						for (j = k; j < N - a; j++) {
							arr2[row][j] = arr2[row][j + a];
							arr2[row][j + a] = 0;
						}
						arr2[row][N - 1] = 0;
					}
					k++;
				}
			}


			for (row = 0; row < N; row++) {
				k = 0;
				while (k < N - 1) {
					if (arr2[row][k] == 0) {
						if (arr2[row][k + 1] == 0) break;
						for (j = k; j < N-1; j++) {
							arr2[row][j] = arr2[row][j + 1];
							arr2[row][j + 1] = 0;
						}
						arr2[row][N - 1] = 0;
						continue;
					}
					if (arr2[row][k] == arr2[row][k + 1]) {
						arr2[row][k] = 2* arr2[row][k];
						arr2[row][k + 1] = 0;
					}
					k++;
				}
			}
			break;
		case 3:
			// 오른쪽으로 미는 경우
			for (row = 0; row < N; row++) {
				k = N - 1;
				while (k > 0) {
					if (arr2[row][k] == 0) {
						a = 0;
						for (j = k; j >= 0; j--) {
							if (arr2[row][j] != 0) {
								a = k - j; break;
							}
						}
						for (j = k; j >= a; j--) {
							arr2[row][j] = arr2[row][j-a];
							arr2[row][j - a] = 0;
						}

						//for (j = k; j > 0; j--) 
						//	arr2[row][j] = arr2[row][j - 1];
						
						arr2[row][0] = 0;
					}
					k--;
				}
			}
			for (row = 0; row < N; row++) {
				k = N - 1;
				while (k > 0) {
					if (arr2[row][k] == 0) {
						if (arr2[row][k - 1] == 0) break;
						for (j = k; j > 0; j--) {
							arr2[row][j] = arr2[row][j - 1];
						}
						arr2[row][0] = 0;
						continue;
					}
					if (arr2[row][k] == arr2[row][k - 1]) {
						arr2[row][k] = 2 * arr2[row][k - 1];
						arr2[row][k - 1] = 0;
					}
					k--;
				}
			}
			break;
		}
		DFS(arr2, cnt + 1);
	}
}

int main() {

	int i, j;

	cin >> N;

	arr = (int**)malloc(sizeof(int*) * N);
	for (i = 0; i < N; i++)
		arr[i] = (int*)malloc(sizeof(int) * N);
	getchar();

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
		getchar();
	}

	DFS(arr, 0);

	printf("%d\n", max_num);

	return 0;
}