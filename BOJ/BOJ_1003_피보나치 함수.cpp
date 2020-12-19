// BOJ_1003_피보나치 함수
#include<iostream>
#include<cstring>
#include<utility>
using namespace std;

pair<int, int> Dp[41];    //first: 0이 출력되는 횟수, second: 1이 출력되는 횟수
int t, n, answer_0, answer_1;

pair<int, int> Solve(int n) {
	pair<int, int>& ret = Dp[n];
	if (ret != make_pair(-1, -1))
		return ret;
	if (n == 0) {
		ret = make_pair(1, 0);
		return ret;
	}
	else if (n == 1) {
		ret = make_pair(0, 1);
		return ret;
	}

	ret.first = Solve(n - 1).first + Solve(n - 2).first;
	ret.second = Solve(n - 1).second + Solve(n - 2).second;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(Dp, -1, sizeof(Dp));
		answer_0 = Solve(n).first;
		answer_1 = Solve(n).second;
		cout << answer_0 << ' ' << answer_1 << '\n';
	}

	return 0;
}
