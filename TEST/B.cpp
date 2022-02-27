#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// x % M의 경우, 0 ~ M-1로 순차적으로 돌아간다.
// N/x 의 경우는?

// 1 : N
// 2: N/2
// ... N/x : 1이 되는 순간은 언제인가?
// N/x = 1 => N >= x > N/2
// N/x = 2 => N/2 >= x > N/3
// ..
// N/x 
// N/x = N => N/(N/2) >= x > 0
// 전처리를 먼저 실행?

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, tmp;
    vector<int> v;

    cin >> n >> m;

    //v.push_back(0);

    for(int i=n;i>=1;i--){
        tmp = n/i;
        v.push_back(tmp); 
        i = n/(tmp+1); 
    }

    
    return 0;
}