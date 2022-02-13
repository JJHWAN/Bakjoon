#include <iostream>

using namespace std;
using ll = long long;

int n, m, lower = -1;

int arr[200001];

void find_lowerbound(int start, int end, int k){
    if(start == end){
        if(arr[start] == k)
            lower = min(lower, start);
    }
    int mid = (start+end)/2;

    if(arr[mid]==k){
        // 양쪽 변 다 체크
        find_lowerbound(start, mid, k);
        find_lowerbound(mid+1, end, k);
    }
    else if(arr[mid] > k){
        find_lowerbound(start, mid-1, k);
    }
    else{

    }
}

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n;i++)
        cin >> arr[i];

    int k;
    for(int i=0;i<m;i++){
        cin >> k;
        lower = -1;
        find_lowerbound(0, n-1, k);
        cout << lower << endl;
    }
    return 0;
}