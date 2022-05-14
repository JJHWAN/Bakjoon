#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    string s;

    cin >> s;
    int len = s.size(), i;

    if(len = 1){
        cout << "YES" << "\n";
        return ;
    }

    for(i=1;i<=len/2;i++){
        if(s[len/2 + i] != s[len/2 - i]) break;
    }
    
    if(i > len/2)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        solve();
    }

    return 0;
}