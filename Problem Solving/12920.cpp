#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

// 백준 12920 평범한 배낭 2

// Knapsack 문제
// 물건의 개수, 만족도, 무게가 주어진다.

// 물건의 종류의 개수 <= 100
// 배낭의 최대 무게 <= 10,000, 개수의 최대값 <= 10,000

// DP[x] : 무게가 x일 때, 얻을 수 있는 최대 만족도라고 하고,
// 그냥 DP를 이용하면, 시간 복잡도가 O(NMK)가 나와서 시간 초과

// 가장 핵심적인 아이디어는 K개의 물건을 logK개의 물건으로 
// 정확히 동치조건으로 만들어서 시간 복잡도를 줄이는 것이다. => ???

// 1. K개 물건이 준비되어 있다.
// 2. 1, 2, 4, ... , 2^m 그리고 K+1 - 2^(m+1)  크기의 패키지 물건이 준비되어 있다.

// 1번과 2번은 같은가?
// 2진수로 K를 나타내서 OXOX...를 하면 K개를 모두 반복하기 보다는 logK개만 처리하면 된다?
// 1이 통과하면 2를 검사, 

typedef struct X{
    int v, c, k;
};

vector <pair<double, X>> v;

int cmp(pair<double, X> a, pair<double, X> b){
    return a.first >= b.first ? 1 : 0; 
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    double lf;
    X tmp;
    for(int i=0;i<n;i++){
        cin >> tmp.v >> tmp.c >> tmp.k;
        lf =  (double)tmp.c/tmp.v;
        v.push_back(make_pair(lf, tmp));
    }

    sort(v.begin(), v.end(), cmp);

    // 무게 당 만족도로 먼저 접근
    // DFS로 풀까.. BFS로 풀까...
    int weight = m, profit = 0, a;
    
    cout << profit;
    return 0;
}