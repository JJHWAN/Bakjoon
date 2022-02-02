#include <iostream>
#include <limits.h>

#define MAXNUM 100001
#define INIT_MAX 1000000000

using namespace std;
using ll = long long;

ll v[MAXNUM];
ll tree[4*MAXNUM];

ll init(int start, int end, ll node){
    if(start == end){
        return tree[node] = v[start];
    }
    int mid = (start+end)/2;
    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

ll get_min(int start, int end, ll node, int left, int right){
    if(left > end || right < start){
        return INIT_MAX;
    }
    if(left <= start && end <= right){
        return tree[node];
    }

    int mid = (start+end)/2;

    return min(get_min(start, mid, node*2, left, right), get_min(mid+1, end, node*2+1, left, right));
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    init(0, n-1, 1);

    int a, b;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << get_min(0, n-1, 1, a-1, b-1) << "\n";
    }

    return 0;
}