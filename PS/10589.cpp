#include <iostream>

using namespace std;
using ll = long long;

// 백준 10589 마법의 체스판
// 크기가 n*m 인 마법의 체스판이 주어지고, 초기 칸들의 색상은 일반 체스판과 같다.
// 체스판에는 신기한 기능이 있는데, 그 중에는 체스판의 색상을 반전시킬 수 있는 기능이 있다.
// 이 기능을 사용하면 칸들을 포함하는 직사각형을 선택하여 색상을 반전시킬 수 있다.

// 위 기능을 최소한으로 이용하여 모든 칸의 색상을 같게 하고 싶다.
// 입력 : n, m (1<= n, m <= 50)
// 출력 : 반전 횟수 k, k 줄 동안 줄 마다 직사각형의 모서리를 포함하는 좌표와 마주보는 모서리의 좌표

// n = 2, m = 2
// X 0 => X X => X X
// 0 X => O O => X X

// n=2, m=3

// X O X 
// O X O

// X X X
// O O O

// X X X
// X X X

// n =3, m=3

// X O X
// O X O
// X O X

// X X X
// O O O
// X X X

// X O X O
// O X O X
// X O X O
// O X O X

// X X X X
// O O O O
// X X X X
// O O O O


int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m;

    k = (n/2) + (m/2);

    cout << k << endl;

    for(int i=2;i<=m;i+=2){
        cout << 1 << " " << i << " " << n << " " << i << endl;
    }

    for(int i=2;i<=n;i+=2){
        cout << i << " " << 1 << " " << i << " " << m << endl;
    }


    return 0;
}