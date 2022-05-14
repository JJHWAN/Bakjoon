#include <iostream>

using namespace std;
using ll = long long;

#define NUM 1000000

int a[2000001] = {0, };

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, tmp, cnt = 0;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> tmp;
        a[tmp]++;
    }

    // ai + aj = x인 쌍의 개수를 구하라 
    // 서로 다른 수만 주어진다.
    // ai를 인자로 받으면 x - ai가 존재하는지 보면 된다

    cin >> x;
    if(x%2){
        for(int i=0;i<=x/2;i++){
            if(a[i] && a[x-i]) cnt++;
        }
    }
    else{
        for(int i=0;i<x/2;i++){
            if(a[i] && a[x-i]) cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}