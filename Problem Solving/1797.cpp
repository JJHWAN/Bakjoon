#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

#define MAX 1000000

// 백준 1797 균형잡힌 줄서기
// 팬클럽 회원 수 + 
// 각각 남, 녀를 구분하는 정보, 서 있는 좌표가 입력으로 주어진다.

// 남,녀의 수가 같은 가장 길이가 큰 그룹을 찾고자 한다.

// N < 1,000,000 이고, 제한시간은 2초
// O(nlogn)까지는 줄일 수 있어야 한다.

// 입력 후, 좌표 순으로 정렬하는건 맞는듯
// 1. DP? : 특정 인덱스까지의 최대 길이로 그 뒤의 길이를 유추할 수 있다?
// 1) k번째 포함하는 그룹 
// 2) k번째를 포함하지 않는 그룹
// 각각 최대 거리를 DP로 따로 배열해서 구할 수 있을까?
// 2)의 경우, DP1[k-1]과 DP2[k-1] 중 더 큰 거 같은데
// 1)은?? 
// 생각만큼 쉽지 않다.. DP로 접근하기 어려울듯

// 2. D&C ? : 히스토그램 마냥 부분정복하고 합치면서 다시 정복?
// 이건 시간복잡도가 아마 허용을 안 할 것 같은데..

// 3. 누적합을 활용하는 문제?
// 남자를 -1, 여자를 +1로 주고, x 좌표 값에 따라서 오름차순으로 정렬하고
// 성별에 따른 누적합이 같은 부분들을 "남녀 수가 같은 구간"으로 처리할 수 있다.

// 음수 ~ 양수의 구간합에 벡터를 선언하고 그 값에 대한 구간 합을 가진 인덱스들을 집어넣는다.

vector <ll> v[2000002];

int cmp(pair<int, int> a, pair <int, int> b){
    return a.first < b.first ? 1: 0;
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <pair<int, int>> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i].second >> a[i].first;
    }

    //sort(a.begin(), a.end(), cmp);
    sort(a.begin(), a.end());
    ll sum = 0, ans = 0;

    v[MAX].push_back(a[0].first);

    for(int i=0;i<n;i++){
        if(a[i].second){
            // 여자
            sum++;
        }
        else{
            // 남자
            sum--;
        }
        if(v[sum+MAX].empty()){
            if(i!=n-1){
                v[sum + MAX].push_back(a[i+1].first);
            }
        }
        else{
            ans = max(ans, a[i].first - v[sum + MAX][0]);
        }
    }

    cout << ans;

    return 0;
}