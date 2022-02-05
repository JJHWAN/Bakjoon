#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 백준 8903 장비
// N개의 장비 중에 K개의 장비만 착용 가능
// 능력치는 5개로 나눠져 있으며, 중복 X => 제일 높은 것만 적용
// 최대의 종합 능력치는?

vector <int> group[5];
int power[10010][5], ans;
int n, k;

void func(int idx){
    if(idx == 5){
        // 5개 능력치를 k개 그룹에 각각 분배한 경우
        int result = 0;
        // 해당 그룹에 속한 능력치들의 합이 최대인 장비를 고른다.
        for(int i=0;i<k;i++){
            int max_profit = 0;
            for(int j=0;j<n;j++){
                int sum = 0;
                for(int a:group[i]){
                    sum += power[j][a];
                }
                max_profit = max(max_profit, sum);
            }
            result += max_profit;
        }
        ans = max(ans, result);
        return ;
    }

    // 능력치를 k개의 그룹에 분배
    for(int i=0;i<k;i++){
        // i번째 그룹에 idx번 능력치의 책임 부여
        group[i].push_back(idx);
        // idx+1 능력치를 위해 recursion
        func(idx+1);
        // 다른 그룹에도 해당 능력치 부여
        group[i].pop_back();
    }

}

void solve(){

    cin >> n >> k;

    ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> power[i][j];
        }
    }

    if(k >=5) {
        int maxP[5] = {0, };
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                if(power[i][j] > maxP[j])
                    maxP[j] = power[i][j];
            }
        }
        for(int j=0;j<5;j++){
            ans += maxP[j];
        }
        cout << ans << endl;
        return ;
    }

    // k개의 선택된 최적해가 있을텐데..
    // 그리디한 접근 방법이 통할까?
   
    // hint : 5개 점수 중에서 
    // K가 5보다 크거나 같으면? 각각 점수들의 최고값을 가지는 놈들만 선택하면 된다.
    // K가 1이면? => 총 종합 점수가 가장 큰 놈을 선택
    // 2 => ([1] [2, 3, 4, 5]) ([2] [1 3 4 5]) 등등 경우의 수를 나눠서 계산
    // 이러면 O(k^5 * N)으로 값을 구할 수 있음.

    for(int i=0;i<5;i++){
        group[i].clear();
    }
    
    func(0);
    cout << ans << endl;
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    for(int i=0;i<t;i++)
        solve();

    return 0;
}