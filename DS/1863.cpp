#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

// 틀렸다고 뜨는데 왜 틀렸는지 모르겠는 문제

int main(void){
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, width, cur, cnt = 0;

    // 스택에 보관
    // top이 같을 때까지 pop하고 1개씩 추가

    stack<int> stk;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> width >> cur;
        if(stk.empty()){
            if(cur) stk.push(cur);
        }
        else{
            while(!stk.empty() && cur < stk.top()){
                // 만약 높이가 작은 빌딩이 들어온다면?
                cnt++;
                stk.pop();
            }
            if (cur == 0) continue;
            if (stk.empty()) {
                stk.push(cur); continue;
            }
            if(cur > stk.top())
                stk.push(cur);
        }
    }

    cur = 0;
    while(!stk.empty() && cur < stk.top()){
                // 만약 높이가 작은 빌딩이 들어온다면?
                cnt++;
                stk.pop();
    }

    cout << cnt;

    return 0;
}