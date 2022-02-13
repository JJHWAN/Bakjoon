#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, rank;

    cin >> n;

    vector <pair<int, int>> v(n);
    vector <int> a(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    for(int i=0;i<n;i++){
        rank = 1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(v[i].first < v[j].first){
                if(v[i].second < v[j].second){
                    rank++;
                }
            }
        }
        a[i] = rank;
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }


    return 0;
}