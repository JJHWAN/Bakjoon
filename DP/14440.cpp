#include <iostream>

using namespace std;
using ll = long long;

int x, y, a0, a1, n;

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> a0 >> a1 >> n;

    int tmp;
    for(int i=2;i<=n;i++){
        tmp = (x*a0 + y*a1) % 100;
        a0 = a1;
        a1 = tmp;
    }

    cout << tmp;

    return 0;
}