#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n, i, j, tmp;
	int max_data = 0, min_data = 100000;
	vector<int> v;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
		if (tmp > max_data) max_data = tmp;
		if (tmp < min_data) min_data = tmp;
	}

	sort(v.begin(), v.end());

	int check_num, cnt = 0, flag = 0;

	if (max_data == min_data || n%2==1) flag = 1;

	// min ~ max 까지 각각 원소가 하나씩은 있어야 한다.
	// max - 1 ~ min+1 까지 다시 하나씩은 존재해야함 (2개씩은 있어야 한다)
	for (i = 0; i < n; i++)
		if (v[i] == min_data + 1) break;

	if (i == n) flag = 1;

	tmp = i; check_num = v[tmp];
	for (i = tmp; i < n;i++) {
		if (v[i] == max_data) break;
		if (v[i] != check_num) {
			if (cnt < 2 || v[i] != check_num + 1) { // 순차적인 수 존재를 보장
				flag = 1; break;
			}
			cnt = 0;
			check_num = v[i];
		}
		cnt++;
	}

	if (flag) {
		cout << "-1";
		return 0;
	}

	// 이미 사용된 데이터들 v에서 삭제
	check_num = min_data;
	v[0] = 0;
	for (i = tmp; i < n -1; i++) {
		if (v[i] != max_data && v[i] != check_num) {
			// min+1 ~ max-1 2개씩 삭제
			check_num = v[i];
			v[i] = 0; v[i + 1] = 0;
			i++;
		}
	}
	v[n - 1] = 0;

	// 다시 재정렬
	sort(v.begin(), v.end());
	// 남은 데이터들을 매칭시켜서 판단

	for (i = 0; i < n; i++) {
		if (v[i] != 0) { // 데이터가 남아있다면
			// 내려갔다가 다시 올라갈 수 있는가?
			// Search for v[i] + 1
			for (j = i + 1; j < n; j++) {
				if (v[i] + 1 == v[j]) {
					v[i] = 0; v[j] = 0; break;
				}
			}
			if (j == n) { // 올라올 수 없었다면
				flag = 1; break;
			}
		}
	}

	if (flag) cout << "-1";
	else cout << "1";

	return 0;
}