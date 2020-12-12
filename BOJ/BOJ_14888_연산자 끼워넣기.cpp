// BOJ_14888_연산자 끼워넣기
#include <iostream>
using namespace std;

long long max_result = -1000000000, min_result = 1000000000;
int num[11], op[4];
int n;

void solve(int m, long long result) {
	if (m == n - 1) {
		if (result < min_result)
			min_result = result;
		if (result > max_result)
			max_result = result;
		return;
	}
	
	// 연산자 종류별로 넣어보기
	if (op[0] > 0) {
		op[0] -= 1;
		solve(m + 1, result + num[m + 1]);
		op[0] += 1;
	}
	if (op[1] > 0) {
		op[1] -= 1;
		solve(m + 1, result - num[m + 1]);
		op[1] += 1;
	}
	if (op[2] > 0) {
		op[2] -= 1;
		solve(m + 1, result * num[m + 1]);
		op[2] += 1;
	}
	if (op[3] > 0) {
		op[3] -= 1;
		solve(m + 1, result / num[m + 1]);
		op[3] += 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	solve(0, num[0]);	// 0번째 연산자 자리부터 연산자 넣어보기

	cout << max_result << '\n' << min_result;
	
	return 0;
}