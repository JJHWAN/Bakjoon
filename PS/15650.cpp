#include <iostream>

using namespace std;
using ll = long long;

int n, m;

void func(int idx, int selected, int array[]){

    if(selected==m){
        for(int i=0;i<n;i++){
            if(array[i]){
                cout << i+1 << " ";
            }
        }
        cout <<"\n";
        return ;
    }

    if(idx == n){
        return ;
    }

    array[idx] = 1;
    func(idx+1, selected+1, array);
    array[idx] = 0;
    func(idx+1, selected, array);
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int array[8] = {0, };

    func(0, 0, array);

    return 0;
}