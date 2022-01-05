#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int N, M;
char **arr;
int visited[11][11][11][11] = { 0,};

typedef struct info{
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
	int dir;
};

queue<info> q;

// BFS�� ����
// ť�� ���� enqueue dequeue 
// DP �߰� �ʿ� -> �޸� �ʰ�
// DP how? ����ġ�⸦ ������?
int move(void);

int move(void){
	
	info cur, next;
	int result = 11, j;
	int flagrb, flagbr;
	while(1){
		if(q.empty()) return -1;
		cur = q.front();

		if (cur.cnt == 10) return -1;
		q.pop();
		
		for(int i=0;i<4;i++){
		start:
			next = cur;
			next.cnt = cur.cnt+1;
			flagrb = 0, flagbr = 0;
			switch(i){
				case 0:
					if(next.rx == next.bx){
						if(next.ry < next.by){
							flagrb = 1;
						}
						else flagbr = 1;
					}
					while(1){
						next.ry++, next.by++;
						if (arr[next.bx][next.by] == 'O') {
							i++; goto start;
						}
						if(arr[next.rx][next.ry] =='O'){
							while(1){
								if (arr[next.bx][next.by] == 'O') {
									i++; goto start;
									//return -1;
								}
								if(arr[next.bx][next.by]=='#'){
									result = min(result, next.cnt);
									return result;
								}
								next.by++;
							}
						}
						if (arr[next.bx][next.by] == '#' && arr[next.rx][next.ry] == '#') {
							next.by--; next.ry--;
							break;	
						}
						if(arr[next.bx][next.by] == '#'){
							next.by--;
						}
						if (arr[next.rx][next.ry] == '#') {
							next.ry--;
						}
						if(next.ry == next.by){
							if(flagrb){
								next.ry--;break;
							}
							if(flagbr){
								next.by--;break;
							}
						}
					}
					break;
				case 1:
					if(next.rx == next.bx){
						if(next.ry < next.by){
							flagrb = 1;
						}
						else flagbr = 1;
					}
					while(1){
						next.ry--, next.by--;
						if (arr[next.bx][next.by] == 'O') {
							i++; goto start;
						}
						if (arr[next.rx][next.ry] == 'O') {
							while (1) {
								if (arr[next.bx][next.by] == 'O') {
									i++; goto start;
									//return -1;
								}
								if(arr[next.bx][next.by]=='#'){
									result = min(result, next.cnt);
									return result;
									goto start;
								}
								next.by--;
							}
						}
						if (arr[next.bx][next.by] == '#' && arr[next.rx][next.ry] == '#') {
							next.by++; next.ry++;
							break;	
						}
						if(arr[next.bx][next.by] == '#'){
							next.by++;
						}
						if(arr[next.rx][next.ry] == '#'){
							next.ry++;
						}
						if(next.ry == next.by){
							if(flagrb){
								next.by++;break;
							}
							if(flagbr){
								next.ry++;break;
							}
						}
					}
					break;
				case 2:
					if(next.ry == next.by){
						if(next.rx < next.bx)
							flagrb = 1;
						else flagbr = 1;
					}
					while(1){
						next.rx++, next.bx++;
						if (arr[next.bx][next.by] == 'O') {
							i++; goto start;
						}
						if (arr[next.rx][next.ry] == 'O') {
							while (1) {
								if (arr[next.bx][next.by] == 'O') {
									i++; goto start;
									//return -1;
								}
								if(arr[next.bx][next.by]=='#'){
									result = min(result, next.cnt);
									return result;
									goto start;
								}
								next.bx++;
							}
						}
						if (arr[next.bx][next.by] == '#' && arr[next.rx][next.ry] == '#') {
							next.bx--; next.rx--;
							break;	
						}
						if(arr[next.bx][next.by] == '#'){
							next.bx--;
						}
						if (arr[next.rx][next.ry] == '#') {
							next.rx--;
						}
						if(next.rx == next.bx){
							if(flagrb){
								next.rx--; break;
							}
							if(flagbr){
								next.bx--; break;
							}
						}
					}
					break;
				case 3:
					if(next.ry == next.by){
						if(next.rx < next.bx)
							flagrb = 1;
						else flagbr = 1;
					}
					while(1){
						next.rx--, next.bx--;
						if (arr[next.bx][next.by] == 'O') {
							i++; goto start;
						}
						if (arr[next.rx][next.ry] == 'O') {
							while (1) {
								if (arr[next.bx][next.by] == 'O') {
									i++; goto start;
									//return -1;
								}
								if(arr[next.bx][next.by]=='#'){
									result = min(result, next.cnt);
									return result;
									goto start;
								}
								next.bx--;
							}
						}
						if(arr[next.bx][next.by] == '#' && arr[next.rx][next.ry] == '#'){
							next.bx++; next.rx++;
							break;	
						}
						if(arr[next.bx][next.by] == '#'){
							next.bx++;
						}
						if (arr[next.rx][next.ry] == '#') {
							next.rx++;
						}
						if(next.rx == next.bx){
							if(flagrb){
								next.bx++; break;
							}
							if(flagbr){
								next.rx++; break;
							}
						}
					}
					break;
			}
			if (visited[next.rx][next.ry][next.bx][next.by] == 1) continue;
			for (j = 0; j < 4; j++) {
				if (j / 2 == (cur.dir / 2) && cur.dir >= 0) continue;
				next.dir = j;
				visited[cur.rx][cur.ry][cur.bx][cur.by] = 1;
				q.push(next);
			}
		}
	}
	return result;
}


int main(){
	
	int i,j;
	
	int R_x, R_y;
	int B_x, B_y;
	char trash;

	cin >> N >> M;

	if (N < 3 || M < 3) return -1;
	if (N > 10 || M > 10) return -1;
	arr = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i<N;i++)
		arr[i] = (char *)malloc(sizeof(char) * M);
	getchar();
	for(i=0;i<N;i++){
		for (j=0;j<M;j++){
			scanf("%c", &arr[i][j]);
			if(arr[i][j]=='R'){
				R_x = i; R_y = j;
			}
			else if(arr[i][j]=='B'){
				B_x = i; B_y = j;
			}
		}
		getchar();
	}

	info first;
	first.rx = R_x, first.ry = R_y;
	first.bx = B_x, first.by = B_y;
	first.cnt = 0, first.dir = -1;
	visited[R_x][R_y][B_x][B_y] = 1;
	q.push(first);
	
	printf("%d", move());
		
	
	return 0;
}
