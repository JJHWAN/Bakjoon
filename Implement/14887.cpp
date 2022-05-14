#include <iostream>

#define MAX_NUM 1000000000
enum OP
{
    PLUS,
    MINUS,
    MUL,
    DIV
};

int arr[11], max_num = -1 * MAX_NUM, min_num = MAX_NUM;
int n, op[4];

using namespace std;

int get_op_result(int result, int k, int num)
{

    switch (k)
    {
    case 0:
        result += num;
        break;
    case 1:
        result -= num;
        break;
    case 2:
        result *= num;
        break;
    case 3:
        result /= num;
        break;
    }
    return result;
}

void dfs(int result, int op[], int index)
{
    // 만약 한 가지 연산자만 남았다면, 빠르게 계산해서 return
    // else? 남은 연산자 중 하나 선택해서 progress

    int tmp = 0, i, k;
    for (i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            tmp++;
            k = i;
        }
    }

    if (tmp == 1)
    {
        for (i = index; i < n; i++)
        {
            result = get_op_result(result, k, arr[i]);
        }
        min_num = min(result, min_num);
        max_num = max(result, max_num);
        return;
    }

    for (i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            tmp = get_op_result(result, i, arr[index]);
            op[i]--;
            dfs(tmp, op, index+1);
            op[i]++;
        }
    }
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0; i < 4; i++)
        cin >> op[i];

    dfs(arr[0], op, 1);

    cout << max_num << "\n";
    cout << min_num << "\n";
    
    return 0;
}
