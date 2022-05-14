#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// 백준 21757 나누기

// 수열을 4개로 나누어
// 각 부분들의 합이 모두 같은 경우의 수를 구한다. 

// 4 <= N <= 100,000

// O(NlogN)까지는 줄여야? WC를 통과하지 않을까

// 나눔의 기준이 되는거?
// 1. index (n-1C3 ? 조합의 경우의 수로 해결 가능? No.. 오히려 더 많음)
// 2. 이전까지의 합(4개 수열중에서 맨 앞부분의 합으로 나머지 결정)
// 1번 케이스의 경우, O(n^3)
// 2번 케이스의 경우, (모든 수열의 합) / 4 = 4개로 나눠진 수열의 합
// 을 이용하면, 지금까지 수열의 합이 K(위에서 언급한 값)이 되는 경우,
// 특수한 주소라고 판단 가능

// 이 특수한 주소내에서 3개를 순서없이 고르면 된다 kC3

// 다시 조금 더 개선하면, k, 2k, 3k에 따라서 나눠야 구하기 쉽다.
// 위에서 생각했던 풀이는 [3] [-3 3] 이런 형태가 나올 수 있음.

// k개 되는 곳의 수를 세다가(n1) 2k가 나오면 n2에 n1을 더 해주기를 반복..
// 하다가 3k가 나오면 ans에 2n를 더하는 식으로 O(n)으로 계산 가능!

// 물론 k가 0일 때는 조금 특수한 경우.

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> v(n);

    ll presum = 0, cnt = 0, sum = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        presum += v[i];
    }

    if(presum%4){
        cout << "0";
        return 0;
    }
    
    presum /= 4;
    ll n1 =0, n2 =0, ans = 0;
    for(int i=0;i<n-1;i++){
        sum += v[i];
        if(!presum){
            if(!sum) cnt++;
        }
        else{
            if(sum%presum==0){
                switch(sum/presum){
                    case 1:
                    n1++;
                    break;
                    case 2:
                    n2 += n1;
                    break;
                    case 3:
                    ans += n2;
                    break;
                }
                if(sum) cnt++;
            }
        }
    }

    if(cnt < 3){
        cout << "0";
        return 0;
    }
    else{
        if(!presum)
            cout << cnt*(cnt-1)*(cnt-2)/6;
        else
            cout << ans;
    }

    return 0;
}