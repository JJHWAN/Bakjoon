#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int v[9], flag = 0;

void func(int a, int b){
    // a, b는 선택받지 못한 수
    int sum = 0;
    for(int i=0;i<9;i++){
        if(i == a || i==b) continue;
        sum += v[i];
    }

    if(sum==100){
        for(int i=0;i<9;i++){
            if(i == a || i==b) continue;
            cout << v[i] << "\n";
        }
        flag = 1;
    }
    else return ;
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, n;

    for(i=0;i<9;i++){
        cin >> v[i];
    }

    sort(v, v+9);

    // 9개에서 7개 뽑기
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(j==i) continue;
            func(i, j);
            if(flag) return 0;
        }
    }

    return 0;
}